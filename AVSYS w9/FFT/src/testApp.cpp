#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSoundStreamSetup(0, 2, this, 44100, BUFFER_SIZE, 4);
    left = new float [BUFFER_SIZE];
    right= new float [BUFFER_SIZE];
    FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
    
        /*buffersize need to be multiple of 8
        sometimes larger, sometimes smaller totally about soundcard things
        how many times// resolution of sound

         Fast Forward Transform
         >>> for frequency analysis
         trying to translate "time domain > frequency domain"
         opposite to what we did in making sound!

        fft buffer is different 
        fft have its own buffer 256 for fft
        shorter buffer harder to detect low frequency>> because each time is small
        so the size of buffer should be big enought to detect low sound too

        jump to definition to see the crazy maths behind*/
    
    FFTanalyzer.peakHoldTime    = 30;
    FFTanalyzer.peakDecayRate   = 0.095f;
    FFTanalyzer.linearEQIntercept = 0.9f;
    FFTanalyzer.linearEQSlope   = 0.01f;
    
        //f just makes things more precise >> give more precision with the float
    
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
//        ofRect(200+(i*4), 600, 4, -freq[i]*10.0f);
    }
    ofSetColor(255, 0, 0);
    
    for (int i = 0;i < FFTanalyzer.nAverages; i++){
        ofRect(200+(i*40), 600, 20, -FFTanalyzer.averages[i]*6);
    }
    
    ofSetColor(255);
    for (int i = 0 ; i< FFTanalyzer.nAverages; i++) {
        ofRect(200+(i*40), 600-FFTanalyzer.peaks[i]*6, 20, -4);
    }
    
    // bunch of option other than microphone
    // AUDIO JACK 
    // soundflower 
    // piezo to identify the vibration
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