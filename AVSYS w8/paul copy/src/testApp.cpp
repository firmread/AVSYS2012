#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(0);
	ofSetVerticalSync(true);
	ofSoundStreamSetup(0, 2, this, 44100, 512, 4);
	inputBufferCopy = new float [512 *2];

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	ofNoFill();
	ofSetColor(255, 0, 0);
	
	ofBeginShape();
	for(int i =0; i< 512; i++){
		float sample = ofMap(inputBufferCopy[i*2], -1, 1, 0, 200);
		ofVertex(100+i, 100 + sample);
	}
	ofEndShape();
    
    ofSetColor(255, 255, 0);
	
	ofBeginShape();
	for(int i =0; i< 512; i++){
		float sample = ofMap(inputBufferCopy[i*2+1], -1, 1, 0, 200);
		ofVertex(100+i, 500 + sample);
	}
	ofEndShape();
	
	ofFill();
	ofDrawBitmapString("volume = "+ ofToString(volume,2), 10 , 10);
	ofSetColor(255,0,0);
	ofRect(620, 200, 10, -volume*200);
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
//--------------------------------------------------------------
void testApp::audioReceived(float *input, int bufferSize, int nChannels){
	memcpy(inputBufferCopy, input, bufferSize*nChannels*sizeof(float));
	volume = 0;
	for(int i = 0; i < bufferSize * nChannels; i++){
		volume+= input[i]*input[i]; // add the square value to emliminate any negative values
	}
	volume /= bufferSize *nChannels; // get the average of all square values
	volume = sqrt(volume);
	

}	