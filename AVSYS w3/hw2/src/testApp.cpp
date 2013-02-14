#include "testApp.h"

int myCircleX,myCircleY,myCircleR;
//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(15);
    // 2 output channels
    // 0 input channels
    // 44100 samples per second
    // 256 samples per buffer
    // 4 buffers (latency)
    
    ofSoundStreamSetup(2, 0, this, 44100, 256, 4);
    
    ofSetCircleResolution(100);
    myCircleX = ofGetWidth()/2;
    myCircleY = ofGetHeight()/2;
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    
    frequency = 440;
    position = 0;
    positionAdder = (frequency/44100.0)* TWO_PI;

    frequency2 = 441;
    position2 = 0;
    positionAdder2 = (frequency2/44100.0)* TWO_PI;
    
    frequency3 = 442;
    position3 = 0;
    positionAdder3 = (frequency3/44100.0)* TWO_PI;

}

//--------------------------------------------------------------
void testApp::update(){
    myCircleR = myCircleX/20+myCircleY/20;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(250, 250, 250,20);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    //ofSetColor(250, 214, 52, 255);
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    ofCircle(myCircleX, myCircleY, myCircleR);
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    myCircleX = x;
    myCircleY = y;
    
    frequency = y+100;
    frequency2 = x+100;
    frequency3 = y+101;
    
    positionAdder = (frequency/44100.0)*TWO_PI;
    positionAdder2 = (frequency2/44100.0)* TWO_PI;
    positionAdder3 = (frequency3/44100.0)* TWO_PI;
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

// -------------------------------
void testApp::audioRequested( float *output, int bufferSize, int nChannels){
    
    
    
    for (int i  = 0; i < bufferSize; i++){
        
        float sample = sin(position);
        float sample2 = sin(position2);
        float sample3 = sin(position3);
        
        position += positionAdder;
        position2 += positionAdder2;
        position3 += positionAdder3;
        
        output[i* 2 + 0 ] = (sample/3) + (sample2/3) + (sample3/3); 
        output[i* 2 + 1 ] = (sample/3) + (sample2/3) + (sample3/3); 
        // we need to scale down each sample amplitude so it doesn't clip
        // therefore we're making them half of their original amplitude        
        
    }
    
    while(position>TWO_PI){
        position-=TWO_PI;
    }
    
    while(position2>TWO_PI){
        position2-=TWO_PI;
    }    
    
    while(position3>TWO_PI){
        position3-=TWO_PI;
    }    
    
}