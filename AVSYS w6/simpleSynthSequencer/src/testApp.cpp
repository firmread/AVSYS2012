#include "testApp.h"


// note to frequency scale here:
// http://www.seventhstring.com/resources/notefrequencies.html


//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	
	ofBackground(90, 90, 90);
    
    ofSoundStreamSetup(2, 0, this, 44100, 512, 4);
    
    frequency = 0;
    position = 0;
    positionAdder = (frequency/44100.0) * TWO_PI;
	
	
    currentTime = ofGetElapsedTimeMillis();             // set the current time
	intervalTime= 150;                                  // set the time interval between ticks
    bTick       = false;                                // this variable will be true when the tick happens - super fast so we can barely see it
    nTicks      = 0;                                    // number of Ticks since we started
    
    minFreq = 120;
    maxFreq = 900;
    stepWidth = ofGetWidth()/N_STEPS;
    
    // populate the frequencies array with some random numbers or manually
    //frequencies[220.0, 360.0, 240.0, 230.0, 260.0, 340.0, 670.0,180.0];
    
    for(int i = 0; i < N_STEPS; i ++){
        frequencies[i] = ofRandom(minFreq, maxFreq);
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
   
    if (ofGetElapsedTimeMillis() - intervalTime > currentTime) {
        
        currentTime = ofGetElapsedTimeMillis();
        bTick = true;
        
        nTicks ++;
        if(nTicks>=N_STEPS){
            nTicks = 0;
        }
        
    } else {
        bTick = false;
    }
    
    frequency = frequencies[nTicks];
    positionAdder = (frequency/44100.0)*TWO_PI;
}

//--------------------------------------------------------------
void testApp::draw(){
    
    		
    
    // draw playhead bar
    ofSetColor(255, 255, 255,100);
    ofRect(stepWidth*nTicks, 0, stepWidth, ofGetHeight()-50);
    
    // draw the graphics for the position of the frequency of each step on the screen
    ofSetColor(255,150, 0, 200);
    for (int i =0; i<N_STEPS; i++) {
        ofRect(stepWidth*i, ofMap(frequencies[i], minFreq, maxFreq, 0, ofGetHeight()-50), stepWidth, 30);
    }
    
    ofSetColor(80, 80, 80);
    ofRect(0, ofGetHeight()-50, ofGetWidth(), 50);
    
    ofSetColor(160, 160, 160);
    ofDrawBitmapString("Tick = "+ ofToString(bTick) +"  step = " + ofToString(nTicks+1) + "   interval Time = "+ ofToString(intervalTime), ofPoint(50,ofGetHeight()-30));
    ofDrawBitmapString("frequency = "+ ofToString(frequency), ofPoint(50,ofGetHeight()-15));

}

//--------------------------------------------------------------
void testApp::audioRequested(float *output, int bufferSize, int nChannels){
    
    for (int i = 0; i<bufferSize; i++) {
        
        float sample = sin(position);
        position += positionAdder;
        
        output[i*2+0] = sample;
        output[i*2+1] = sample;
        
        
        while (position > TWO_PI) {
            position -= TWO_PI;
        }
        
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

    if (y<ofGetHeight()-50) {                                                           // limit the max y pos read from the mouse to have some space for the info txt
        
        for (int i = 0; i< N_STEPS; i++) {                                              
            
                if ( x > stepWidth*i && x < stepWidth*(i+1)) {                          // check if the mouse x is inside any of the areas of each step
                    frequencies[i] = ofMap(y, 0, ofGetHeight()-50, minFreq, maxFreq);   // map/scale its vertical position to the max/min freq range
                }
        }
    }
    
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

