#include "testApp.h"


int liner,linerM;
int fStock1;
bool stock1;
//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    
	ofBackground(20, 20, 20);
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	
    ofSetFrameRate(100);
    
	//panel.setup("control", 770, 0, 300, 400);
	//panel.addPanel("sound settings", 1, false);
	//panel.setWhichPanel("sound settings");
	//panel.addSlider("carrier frequency", "VAL_CARRIER_FREQ", 100,20,1000, false);
	//panel.addSlider("modulator frequency", "VAL_MODULATOR_FREQ", 1,0.01,200, false);
	//panel.addSlider("carrier frequency 2", "VAL_CARRIER_FREQ2", 100,20,1000, false);
	//panel.addSlider("modulator frequency 2", "VAL_MODULATOR_FREQ2", 1,0.01,200, false);

	
	//panel.loadSettings("settings.xml");
	
	
	ofSoundStreamSetup(2,0,this, 44100,256, 4); 
	//Setting up pur soundStream
	//Number of output channels. Number of input channels. pointer to the app we're using it . Sample Rate. BufferSize. Number of buffers 
	
    
    // we create two sine wave oscillators
	
	frequency								= 440;
	position								= 0;
	positionAdder							= (frequency / 44100.0) * TWO_PI;
	
	frequencyModulator						= 100;
	positionModulator						= 0;
	positionModulatorAdder					=  (frequencyModulator / 44100.0) * TWO_PI;
	
	modulator								= 0;
	sample									= 0;
    
    
    // we create two sine wave oscillators
	
	frequency2                              = 220;
	position2								= 0;
	positionAdder2							= (frequency2 / 44100.0) * TWO_PI;
	
	frequencyModulator2						= 200;
	positionModulator2						= 0;
	positionModulatorAdder2					=  (frequencyModulator2 / 44100.0) * TWO_PI;
	
	modulator2								= 0;
	sample2									= 0;
    
    
}

//--------------------------------------------------------------
void testApp::update(){
	panel.update();
	
	//frequency								= panel.getValueF("VAL_CARRIER_FREQ");
	positionAdder							= (frequency / 44100.0) * TWO_PI;
	//frequencyModulator						= panel.getValueF("VAL_MODULATOR_FREQ");
	positionModulatorAdder					= (frequencyModulator / 44100.0) * TWO_PI;	
    
	//frequency2								= panel.getValueF("VAL_CARRIER_FREQ2");
	positionAdder2							= (frequency2 / 44100.0) * TWO_PI;
	//frequencyModulator2						= panel.getValueF("VAL_MODULATOR_FREQ2");
	positionModulatorAdder2					= (frequencyModulator2 / 44100.0) * TWO_PI;
    
    liner = 10000/frequency;
    linerM = 1000/frequencyModulator;
	
	cout << frequency << endl;
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetLineWidth(6);
    ofSetColor(90, 90, 90, 100);
    
    for (int i=0; i<500; i++) {
        ofLine (0, i*liner, ofGetWidth(), i*liner);
        ofLine (i*linerM, 0, i*linerM, ofGetHeight());
    }
    ofSetLineWidth(1);
	
    //panel.draw();
	ofFill();
	ofSetColor(ofMap(mouseX, 0, ofGetWidth(), 50, 255), ofMap(mouseY, 0, ofGetHeight(), 50, 255), mouseX + mouseY);
	ofCircle(mouseX,mouseY,0.2*modulator2*frequency2, 0.2*modulator2*frequency2);
	

    
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'a') {
        frequency -= 5;
    }
    if (key == 'd') {
        frequency += 5;
    }
    if (key == 'w'){
        frequencyModulator += 5;
    }
    if (key =='s'){
        frequencyModulator -= 5;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){    
    frequency2 = ofMap(x, 0, ofGetWidth(), 100, 400);
    frequencyModulator2 = ofMap(y, 0, ofGetHeight(), 100, 400);
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
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void testApp::audioRequested 	(float * output, int bufferSize, int nChannels){
	
	for (int i = 0; i < bufferSize; i++){
		
		
		modulator	=  ofMap(sin (positionModulator), -1,1, 0,1); 
        
        //We are getting values between -1 and 1, but we need a scalar to multiply the amplitude of the carrier wave, so we scale it to 0-1
		positionModulator += positionModulatorAdder;
		
		
        modulator2	=  ofMap(sin (positionModulator2), -1,1, 0,1); 
        positionModulator2 += positionModulatorAdder2;
        
		sample		= sin( position ) * modulator;  // we use the modulator wave to modulate the amplitude of the                                        
		position	+= positionAdder;               // carrier wave/oscillator
        
		sample2		= sin( position2 ) * modulator2;  // we use the modulator wave to modulate the amplitude of the                                        
		position2	+= positionAdder2;               // carrier wave/oscillator
		
		output[i * 2 + 0] = sample+sample2;			// left channel
		output[i * 2 + 1] = sample+sample2;			// right channel
        
		
	}
	
	
	// because sin(..) of very large values is less precise, let's keep the position variable in the range of 0 to TWO_PI.  it's cyclical
	while (position > TWO_PI) {
		position -= TWO_PI;	
	}
	
	while (positionModulator > TWO_PI){
		positionModulator -= TWO_PI;	
	}
    
    
    while (position2 > TWO_PI) {
		position2 -= TWO_PI;	
	}
	
	while (positionModulator2 > TWO_PI){
		positionModulator2 -= TWO_PI;	
	}
	
}

