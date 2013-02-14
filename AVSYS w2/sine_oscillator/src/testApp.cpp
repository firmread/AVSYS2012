#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(60);
    
    // 2 output channels
    // 0 input channels
    // 44100 sampling rate / samples per second
    // 256 samples per buffer / buffersize
    // 4 buffers (latency)
    
    ofSoundStreamSetup(2, 0, this, 44100, 256, 4);
    
    frequency = 440;
    position= 0;
    positionAdder = (frequency/44100.0)*TWO_PI;

    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    frequency = y;
    positionAdder = (frequency/44100.0)*TWO_PI;
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












