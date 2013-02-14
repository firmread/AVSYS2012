#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetCircleResolution(100);
	
	panel.setup("control", 770, 0, 300, 400);
	panel.addPanel("sound settings", 1, false);
	panel.setWhichPanel("sound settings");
	panel.addSlider("carrier", "VAL_CARRIER_FREQ", 100,20,1000, false);			//frequency of the carrier oscilator
	panel.addSlider("modulator", "VAL_MODULATOR_FREQ", 1,0.01,30, false);		//frequency of the modulator oscilator

	
	panel.loadSettings("settings.xml");
	
	ofSoundStreamSetup(2,0,this, 44100,256, 4);
	
	
	carrier_frequency				= 100;
	carrier_position				= 0;
	carrier_positionAdder			= (carrier_frequency / 44100.0) * TWO_PI;
	
	
	lowFreq					= 50;
	highFreq				= 400;
	
	modulator_frequency		= 100;
	modulator_position		= 0;
	modulator_positionAdder	=  (modulator_frequency / 44100.0) * TWO_PI;
	
	sample					= 0;
	
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	panel.update();
	
	
	lowFreq = MAX(panel.getValueF("VAL_CARRIER_FREQ") - 100, 0) ;
	highFreq = MIN(panel.getValueF("VAL_CARRIER_FREQ") + 100, 44100.0/2) ;
	modulator_positionAdder	= (panel.getValueF("VAL_MODULATOR_FREQ") / 44100.0) * TWO_PI;
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	panel.draw();
	
	////Draw strings onto screen
	string stringLowFreq	= ofToString(lowFreq,2);
	ofDrawBitmapString("Lowest Freq:  "			+stringLowFreq, 20,200);
	
	string stringHIghFreq	= ofToString(highFreq,2);
	ofDrawBitmapString("Highest Freq:  "		+stringHIghFreq, 20,230);
	
	string freq				= ofToString(carrier_frequency,2);
	ofDrawBitmapString("Carrier frequency:  "			+freq, 20,260);
	
	string posMod			= ofToString(modulator_position,2);
	ofDrawBitmapString("Modulator position:  "	+posMod, 20,290);
	
	string posAdd			= ofToString(carrier_positionAdder,2);
	ofDrawBitmapString("Carrier Position Adder:  "		+posAdd, 20,320);
	
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
		
		carrier_frequency			=  ofMap(sin (modulator_position), -1,1, lowFreq,highFreq);
		modulator_position	+= modulator_positionAdder;
		carrier_positionAdder		= (carrier_frequency / 44100.0) * TWO_PI;
		
		sample				=sin( carrier_position );
		carrier_position			+= carrier_positionAdder;
		
		output[i * 2 + 0]	= sample;			// left channel
		output[i * 2 + 1]	= sample;			// right channel
		
	}
	
	
	// because sin(..) of very large values is less precise, let's keep the position variable in the range of 0 to TWO_PI.  it's cyclical
	// so doing something like this, is very similar to %= for integer numbers. 
	while (carrier_position > TWO_PI) {
		carrier_position -= TWO_PI;	
	}
	
	while (modulator_position > TWO_PI){
		modulator_position -= TWO_PI;	
	}
	
}
