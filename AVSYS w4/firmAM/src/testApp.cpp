#include "testApp.h"
#define NUM_CIRCLE 100

int circleX [NUM_CIRCLE];
int circleY [NUM_CIRCLE];
int circleRadius [NUM_CIRCLE];

int red [NUM_CIRCLE];
int blu [NUM_CIRCLE];
int gre [NUM_CIRCLE];

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	ofSetCircleResolution(100);
	
	panel.setup("control", 770, 0, 300, 400);
	panel.addPanel("sound settings", 1, false);
	panel.setWhichPanel("sound settings");
	panel.addSlider("carrier frequency", "VAL_CARRIER_FREQ", 100,20,1000, false);
	panel.addSlider("modulator frequency", "VAL_MODULATOR_FREQ", 1,0.01,200, false);
	
	panel.loadSettings("settings.xml");
	
	
	ofSoundStreamSetup(2,0,this, 44100,256, 4); 
	//Setting up pur soundStream
	//Number of output channels. Number of input channels. pointer to the app we're using it . Sample Rate. BufferSize. Number of buffers 
	
    
    // we create two sine wave oscillators
	
	frequency								= 440;
	position								= 0;
	positionAdder							= (frequency / 44100.0) * TWO_PI;
	
	frequencyModulator						= 100;
	positionModulator						= 0;
	positionModulatorAdder					= (frequencyModulator / 44100.0) * TWO_PI;
	
	modulator								= 0;
	sample									= 0;
    
    for(int i=0; i<NUM_CIRCLE; i++)
    {
        red[i] = ofRandom(255);
        blu[i] = ofRandom(255);
        gre[i] = ofRandom(255);
        
        circleX[i] = ofRandom(-ofGetWidth()/2, ofGetWidth());
        circleY[i] = ofRandom(-ofGetHeight()/2, ofGetHeight());
        circleRadius[i] = ofRandom(5,40);
        
    }
    
    
}

//--------------------------------------------------------------
void testApp::update(){
	panel.update();
	
	frequency								= panel.getValueF("VAL_CARRIER_FREQ");
	positionAdder							= (frequency / 44100.0) * TWO_PI;
	frequencyModulator						= panel.getValueF("VAL_MODULATOR_FREQ");
	positionModulatorAdder					= (frequencyModulator / 44100.0) * TWO_PI;
	
	cout << frequency << endl;
    
    for(int i=0; i<NUM_CIRCLE; i++)
    {
        circleX[i] += ofRandom(-10,10);
        circleY[i] += ofRandom(-10,10);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	panel.draw();
	ofFill();
    for(int i=0; i<NUM_CIRCLE; i++)
    {
        ofSetColor(red[i], blu[i], gre[i]);
        ofCircle(mouseX+circleX[i],mouseY+circleY[i],0.5*modulator*frequency, 0.5*modulator*frequency);
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
				
		sample		= sin( position ) * modulator;  // we use the modulator wave to modulate the amplitude of the                                        
		position	+= positionAdder;               // carrier wave/oscillator
		
		output[i * 2 + 0] = sample;			// left channel
		output[i * 2 + 1] = sample;			// right channel
		
	}
	
	
	// because sin(..) of very large values is less precise, let's keep the position variable in the range of 0 to TWO_PI.  it's cyclical
	while (position > TWO_PI) {
		position -= TWO_PI;	
	}
	
	while (positionModulator > TWO_PI){
		positionModulator -= TWO_PI;	
	}
	
}

