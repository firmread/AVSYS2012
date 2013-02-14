#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    ofSetFrameRate(30);
//    ofSetVerticalSync(true);
    ofSoundStreamSetup(0, 2, this, 44100, BUFFER_SIZE, 4);
    left = new float [BUFFER_SIZE];
    right= new float [BUFFER_SIZE];
    FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
    
    FFTanalyzer.peakHoldTime    = 30;
    FFTanalyzer.peakDecayRate   = 0.095f;
    FFTanalyzer.linearEQIntercept = 0.9f;
    FFTanalyzer.linearEQSlope   = 0.01f;
        
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    float avg_power = 0.0f;
    myfft.powerSpectrum(0, (int) BUFFER_SIZE/2, left, BUFFER_SIZE, &magnitude[0], &phase[0], &power[0], &avg_power);
    
    for(int i = 0; i<BUFFER_SIZE/2; i++){
        freq[i] = magnitude[i];
    }
    
    FFTanalyzer.calculate(freq);
    
    
    for (int i = 0; i < BUFFER_SIZE/2; i++) {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateZ(i*2);
        ofSetColor(255,150);
        ofRect(0, 0, 2, -freq[i]*10.0f);
        ofSetColor(204,120,12,100);
        ofRect(0, 0, 4, -freq[i]*20.0f);
        ofPopMatrix();
    }
    
    
    
    for (int i = 0;i < FFTanalyzer.nAverages; i++){
        int kolor = ofMap(FFTanalyzer.averages[i], 1, 50, 200, 255);
        ofSetColor(40, 80, kolor,150);
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateZ(i*20);
        ofRotateX(-100);
        ofRect(0, 0, 10, -FFTanalyzer.averages[i]*15);
        ofPopMatrix();
    }
    
    ofSetColor(255, 150);
    for (int i = 0 ; i< FFTanalyzer.nAverages; i++) {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotateZ(i*20);
        ofRotateX(-100);
//        ofCircle(0, -FFTanalyzer.peaks[i]*9, FFTanalyzer.peaks[i]*3);
        ofRect(0, -FFTanalyzer.peaks[i]*20, 10, FFTanalyzer.peaks[i]*3);
        ofPopMatrix();
    }
    
}

//--------------------------------------------------------------
void testApp::audioReceived(float *input, int bufferSize, int nChannels){
    
    for (int i = 0; i < bufferSize; i++){
        left[i]     =input [i*2];
        right[i]    =input [i*2+1];
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