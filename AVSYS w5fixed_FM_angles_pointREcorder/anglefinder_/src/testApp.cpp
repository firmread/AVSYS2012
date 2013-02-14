#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

		
	ofSetVerticalSync(true);
	ofBackground(30,30,30);
    
}

//--------------------------------------------------------------
void testApp::update(){
     
    
	float dx = mouseX - prevPos.x; 
    //the distance between the current position and the previous 'x' position
	float dy = mouseY - prevPos.y; 
    //the distance between the current position and the previous 'y' position
	
	angle = atan2(dy, dx); 
    // use the x and y distances to calculate the angle between the two positions
    
	prevPos.x = mouseX; 
	prevPos.y = mouseY; 
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    
    ofSetColor(255,255,255);
	
    
	ofPushMatrix();     
        ofTranslate(mouseX, mouseY, 0);
        ofRotateZ(angle * RAD_TO_DEG);
        ofRect( 0,0, 30,30);
	ofPopMatrix();
    
    /*
     
     more on push and pop matrix and 2d transformations : 
     http://www.openframeworks.cc/documentation/graphics/ofGraphics.html#ofPopMatrix
     + p5 example - really good explanation! : http://processing.org/learning/transform2d/ 
     
     */ 
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
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
void testApp::mouseReleased(){
}
