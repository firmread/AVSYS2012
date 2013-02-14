#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	//ofSetFrameRate(60);
	ofSetCircleResolution(100);
	
	panel.setup("control", 770, 0, 300, 400);
	panel.addPanel("granular settings", 1, false);
	
	panel.setWhichPanel("granular settings");
		
	panel.addSlider("Avg Freq",			"AVG_FRQ",			400,	100,1000, false);
	panel.addSlider("Avg Freq Spread",	"AVG_FRQ_S",		10,		0,500, false);
	
	panel.addSlider("Avg Length",		"AVG_LEN",			50,		1,200, false);
	panel.addSlider("Avg Length Spread","AVG_LEN_S",		10,		1,200, false);
	
	panel.addSlider("Avg Volume",		"AVG_VOL",			0.010,	0,1, false);
	panel.addSlider("Avg Volume Spread","AVG_VOL_S",		0.005,	0,1, false);
	
	panel.addSlider("Grains Per Sec",	"GRAINS_PER_SEC",	200,	0,1000, false);
	
	panel.loadSettings("settings.xml");
	
	ofSoundStreamSetup(2,0,this, 44100,512, 4);
	
	outputBufferCopy = new float[512*2];	
}

//--------------------------------------------------------------
void testApp::update(){
	
	panel.update();
		
	GM.avgFrequency = panel.getValueF("AVG_FRQ");
	GM.avgFrequencySpread = panel.getValueF("AVG_FRQ_S");
	
	GM.avgGrainLength = panel.getValueF("AVG_LEN");
	GM.avgGrainLengthSpread = panel.getValueF("AVG_LEN_S");
	
	GM.avgVolume = panel.getValueF("AVG_VOL");
	GM.avgVolumeSpread = panel.getValueF("AVG_VOL_S");
	
	GM.grainsPerSecond = panel.getValueF("GRAINS_PER_SEC");
	
	GM.idle();
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	panel.draw();
	
	// draw the waveform
	ofNoFill();
	ofSetColor(255, 255, 255);
	ofBeginShape();
	for (int i = 0; i < 512; i++){
		float sample = ofMap(outputBufferCopy[i*2], -1,1, 0,200);	
		ofVertex(i + 100, sample+100);
	}
	ofEndShape();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	panel.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	panel.mousePressed(x,y,button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	panel.mouseReleased();
}



//--------------------------------------------------------------
void testApp::audioRequested 	(float * output, int bufferSize, int nChannels){
	
	for (int i = 0; i < bufferSize; i++){
		output[i*nChannels    ] = 0;
		output[i*nChannels + 1] = 0;
	}
	
	GM.addToSoundBuffer(output, bufferSize);
	
	if (ofGetFrameNum()%4 == 0)
	memcpy(outputBufferCopy, output, bufferSize * nChannels * sizeof(float));
	
}
