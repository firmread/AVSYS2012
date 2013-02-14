#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(90, 90, 90);
	
	currentTime = ofGetElapsedTimeMillis();
	intervalTime = 1000;
    bTick = false;
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

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(200, 200, 200);
    ofDrawBitmapString("Tick = "+ ofToString(bTick) +"\nTicks" + ofToString(nTicks), ofPoint(50,50));
		
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

