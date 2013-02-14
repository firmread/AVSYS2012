#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);    
    // 2 output channels 
    // 0 input channels
    // 44100 samples per second
    // 256 samples per buffer ( or on power of two of 256 )
    // 4 buffers (latency)
 
    ofSoundStreamSetup(2, 0, 44100, 256, 4);

    //making frequency
    frequency = 440;
    position = 0;
    positionAdder = (frequency/44100.0)* TWO_PI;
    //circle through time
    
    
    //making frequency
    frequency2 = 880;
    position2 = 0;
    positionAdder2 = (frequency2/44100.0)* TWO_PI;
    
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::audioRequested(float *output, int bufferSize, int nChannels){
    // noise
    
    
    //    float random = ofRandom(-.5f,.5f );
    //    for (int i =0; i<bufferSize; i++){
    //        output[i*2+0 ] = random;  //left channel
    //        output[i*2+1 ] = random;  // right channel
    //    }


    for (int i =0; i<bufferSize; i++){
        float sample = sin(position);
        float sample2 = sin(position2);
        position += positionAdder;
        position2 += positionAdder2;
        output[i*2+0 ] = sample;  //left channel
        output[i*2+1 ] = sample;  // right channel
    }
        
    while (position*TWO_PI) {
        position-=TWO_PI;
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