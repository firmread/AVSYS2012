#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	
	ofBackground(90, 90, 90);
    
 
	
    startTime = ofGetElapsedTimeMillis(); // set the current time

    bpm = 20; // start at 120 bpm (use '+' and '-' to increase/decrease bpm's in multiples of 10) - see onKeyPressed()
    
    
    // set the time interval between ticks - calculate how many miliseconds we need to wait to move to the next step based on bpm
    intervalTime = (60.0/bpm/4)*1000;
    bTick = false;                          // this variable will be true when the tick happens - pulse -  super fast so we can barely see it
    nTicks = 0;                             // number of Ticks since we started
    
    
    // load the sound file and set its looping mode to false
    beat.loadSound("BT7AADA.WAV"); 
    beat.setLoop(false);

    // setting up the stpe buttons
    for(int i = 0; i< N_STEPS; i++){
        ofRectangle tempRectangle(100+(60*i), 250, 50, 50);
        myStep[i].setup(tempRectangle);
        
    }
    

}

//--------------------------------------------------------------
void testApp::update(){
   
    if (ofGetElapsedTimeMillis() - intervalTime > startTime) {
        nTicks++;
        
        if (nTicks>=N_STEPS) nTicks = 0;    // loop the steps
        
        startTime = ofGetElapsedTimeMillis();
        bTick = true;
       
        // because this happens only once (pulse) every new tick - it is the right place to have our sound playback code
        if (myStep[nTicks].bPressed) {
            beat.play();
        }
        

        
    } else {
        bTick = false;
    }
    
    

    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for(int i = 0; i< N_STEPS; i++){
        myStep[i].draw();
    }
    
    ofFill();
    ofSetColor(160, 160, 160, 150);
    ofRect(100+(60*nTicks), 0, 50, ofGetHeight()-50);

    ofSetColor(80, 80, 80);
    ofRect(0, ofGetHeight()-50, ofGetWidth(), 50);
    ofSetColor(200, 200, 200);
    ofDrawBitmapString("bpm :: " + ofToString(bpm)+  "  interval Time ::" + ofToString(intervalTime) + "  current step :: " +  ofToString(nTicks+1), 50, ofGetHeight()-30);

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case '+':
            bpm+=10;                                // increase bpm by 10
            intervalTime = (60.0/bpm/4)*1000;       // update the interval time
            break;
        case '-':
            bpm-=10;                                // decrease bpm by 10
            intervalTime = (60.0/bpm/4)*1000;       // update the interval time
            break;
    }
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

    for(int i = 0; i< N_STEPS; i++){
        myStep[i].mouseDown(x, y);
        
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
 
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

