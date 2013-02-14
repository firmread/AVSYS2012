#include "testApp.h"

// root mean square is a very good way to avarage by not taking negative value
// as sound can't take minus
// square, mean, root = average w/o minus!

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSoundStreamSetup(0, 2, this, 44100, 512, 4);
    inputBufferCopy = new float [512*2];
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofNoFill();
    ofSetColor(255, 0, 0);
    
    ofBeginShape();
    for (int i= 0; i < 512; i++) {
        float sample = ofMap(inputBufferCopy[i*2], -1, 1, 0, 200);
        ofVertex(i+100, 100+sample); 
    }
    ofEndShape();
    
    ofSetColor(100, 100, 10);
    ofBeginShape();
    for (int i= 0; i < 512; i++) {
        float sample = ofMap(inputBufferCopy[i*2+1], -1, 1, 0, 200);
        ofVertex(i+100, 100+sample); 
    }
    ofEndShape();
    
    
    ofFill();
    ofDrawBitmapString("volume = " +ofToString(volume,2), 10,10);
    ofSetColor(255,0, 0);
    ofRect(620, 200, 10, -volume);
}

//--------------------------------------------------------------

void testApp::audioRecieved(float * input, int bufferSize, int nChannels){
    //Copying new value from memory InputBufferCopy -- right click memcpy to see more definition
    memcpy(inputBufferCopy, input , bufferSize*nChannels* sizeof(float));
    // copy this on buffer to memory to manipulate/play with it
    // is the method that mostly have to use only when work with sound
    
    volume = 0;
    for (int i = 0; i < bufferSize * nChannels; i++) {
        volume += input[i] * input[i]; //square to get rid of negative values 
    }
    volume /= bufferSize*nChannels; // get the average of all square values
    volume = sqrt(volume);  //finally take the square root of the value
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