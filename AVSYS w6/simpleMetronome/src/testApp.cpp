#include "testApp.h"


float freqNotes[] = {220.0,340.0,440.0,650.0,180.5};
//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(90, 90, 90);
	
    
    
    //sound setup
    
    ofSoundStreamSetup(2, 0, this, 44100, 256, 4);
    
    frequency = 440;
    position= 0;
    positionAdder = (frequency/44100.0)*TWO_PI;

    
    
    
    //metronome setup
	currentTime = ofGetElapsedTimeMillis();
	intervalTime = 1000;
    
    // trigger
    bTick = false;
    
    //count
    nTicks = 0;
}

//--------------------------------------------------------------
void testApp::update(){
   
    if (ofGetElapsedTimeMillis() - intervalTime > currentTime) {
        
        currentTime = ofGetElapsedTimeMillis();
        bTick = true;
        nTicks ++;
    } else {
        bTick = false;
    }
    //change frequency through time
    frequency = freqNotes[nTicks];
    positionAdder = (frequency/44100.0)*TWO_PI;
    
    if (nTicks>=4){
        nTicks=0;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(200, 200, 200);
    ofDrawBitmapString("Tick = "+ ofToString(bTick) +"\nTicks" + ofToString(nTicks), ofPoint(50,50));
		
}


//--------------------------------------------------------------
void testApp::audioRequested(float *output, int bufferSize, int nChannels){
    
    for(int i = 0; i<bufferSize; i++){
        float sample = sin( position );
        position += positionAdder;
        
        output[i*2+0]= sample;
        output[i*2+1]= sample;
        
        
    } 
    
    // because sin(..) of very large values is less precise, 
    //let's keep the position variable in the range of 0 to TWO_PI.  
    // it's cyclical!
    while (position>TWO_PI) {       
        position -= TWO_PI;
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
       

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

