#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	ofSetVerticalSync(true);
	
	ofBackground(255, 255, 255);
	
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	

}

//--------------------------------------------------------------
void testApp::draw(){

	ofNoFill();
	ofSetColor(0, 0, 0);
	
    // start the shape
	ofBeginShape();
    
    //loop through the vector 
	for (int i = 0; i < points.size(); i++){
        
        //use each ofPoint coordinates to plot the shape vertices
		ofVertex(points[i].x, points[i].y);
	}
    
    //end the shape
	ofEndShape();
	

    // draw some usefull info on screen
	ofSetColor(90, 90, 90);
    ofDrawBitmapString("number of points :: " + ofToString(points.size(),0), 50, 50);

	
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
    
    // create a temp ofPoint to store current mouse data
	ofPoint tempPt;
	tempPt.x = x;
	tempPt.y = y;
    
    // add it to the end of vector
	points.push_back(tempPt);
	
    
	
    // we can use this condition if we want to limit the number of points stored and 
    // erase the points at the beggining of the vector (the oldest stored)
    
	if (points.size() > 50){
		points.erase(points.begin());
	}
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    // clear the vector - delets all of its contents
	points.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

