#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0,0,0);
    ofSetCircleResolution(60);
    ofSetWindowShape(1024, 512);
    
    //arduino
    ard.connect("/dev/tty.usbserial-A800KDUD", 57600);
	//ard.connect("/dev/tty.usbmodem1a21", 57600);
	ofAddListener(ard.EInitialized, this, &testApp::setupArduino);

	bSetupArduino	= false;	
    
    
    //sound
	ofSoundStreamSetup(2,0,this, 44100,256, 4);
	
	
	carrier_frequency				= 100;
	carrier_position				= 0;
	carrier_positionAdder			= (carrier_frequency / 44100.0) * TWO_PI;
	
	
	lowFreq					= 50;
	highFreq				= 400;
	
	fm_frequency            = 100;
	fm_position             = 0;
	fm_positionAdder        =  (fm_frequency / 44100.0) * TWO_PI;
    
    am_frequency			= 100;
	am_position				= 0;
	am_positionAdder		=  (am_frequency / 44100.0) * TWO_PI;
	
	am						= 0;
	sample					= 0;
	

}

//--------------------------------------------------------------
void testApp::update(){

	updateArduino();
    lowFreq             =   ofMap(ard.getAnalog(0), 0, 255, 50, 200) ;
	highFreq            =   ofMap(ard.getAnalog(1), 0 , 255, 100, 700) ;
    
    fm_positionAdder	=   (ofMap(ard.getAnalog(2),0,255,0.01,10) / 44100.0) * TWO_PI;
    
    am_frequency        =   (ofMap(ard.getAnalog(3), 0, 255, 100, .01));
    
    
    cout << ard.getAnalog(3) << endl; 

}

//--------------------------------------------------------------
void testApp::setupArduino(const int & version) {
	
	ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
	ard.sendAnalogPinReporting(0, ARD_ANALOG);	
    ard.sendAnalogPinReporting(1, ARD_ANALOG);	
    ard.sendAnalogPinReporting(2, ARD_ANALOG);	
    ard.sendAnalogPinReporting(3, ARD_ANALOG);	
    
	bSetupArduino = true;
}

//--------------------------------------------------------------
void testApp::updateArduino(){
    
	ard.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,ofMap(fm_frequency, .01, 10, 50, 255));
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, carrier_frequency/10*am);
    ofDisableAlphaBlending();
    
    ofSetColor(100);
    ofRect(0, 10, ofGetWidth(), 25);
    ofRect(0, 40, ofGetWidth(), 25);
    ofRect(0, 70, ofGetWidth(), 25);
    ofRect(0, 100, ofGetWidth(), 25);
    
    ofSetColor(200);
    ofRect(ard.getAnalog(0), 10, 25, 25);
    ofRect(ard.getAnalog(1), 40, 25, 25);
    ofRect(ard.getAnalog(2), 70, 25, 25);
    ofRect(ard.getAnalog(3), 100, 25, 25);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	ard.sendDigital(13, ARD_HIGH);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	ard.sendDigital(13, ARD_LOW);
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
		
        am                          =   ofMap(sin (am_position), -1,1, 0,1);
        am_position                 +=  am_positionAdder;
        
		carrier_frequency			=   ofMap(sin (fm_position), -1,1, lowFreq,highFreq);
		fm_position                 +=  fm_positionAdder;
        
		carrier_positionAdder		=   (carrier_frequency / 44100.0) * TWO_PI;
		am_positionAdder            =   (am_frequency / 44100.0) * TWO_PI;
        
		sample                      =   sin( carrier_position ) *am;
		carrier_position			+=  carrier_positionAdder;
		
		output[i * 2 + 0]           =   sample;			// left channel
		output[i * 2 + 1]           =   sample;			// right channel
		
	}
	
	while (carrier_position > TWO_PI) {
		carrier_position -= TWO_PI;	
	}
	
	while (fm_position > TWO_PI){
		fm_position -= TWO_PI;	
	}
    
	while (am_position > TWO_PI){
		am_position -= TWO_PI;	
	}
	
	
}
