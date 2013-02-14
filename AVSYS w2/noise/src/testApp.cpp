#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);

    // 2 output channels
    // 0 input channels
    // 441000 samples per second
    // 256 samples per buffer
    // 4 num buffers (latency)
    
    ofSoundStreamSetup(2,0,this,44100,256,4);
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255, 255, 255);

}


// -------------------------------------------------------------
void testApp::audioRequested(float *output, int bufferSize, int nChannels){

    
    for(int i=0; i < bufferSize; i ++){

        float random = ofRandom(-0.1f,0.1f);    // generate a random number
        
        output[i * 2 + 0] = random;             // pass the random number to the left channel
        output[i * 2 + 1] = random;             // pass the random number to the right channel
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}