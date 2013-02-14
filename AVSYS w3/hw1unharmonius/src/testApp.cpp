#include "testApp.h"

int myCircleX,myCircleY,myCircleR;
float sampleNum;
//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate(10);
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
    //ofSetBackgroundAuto(false);
    
    frequency = 110+0;
    position = 0;
    positionAdder = (frequency/44100.0)* TWO_PI;

    frequency2 = 330+5;
    position2 = 0;
    positionAdder2 = (frequency2/44100.0)* TWO_PI;
    
    frequency3 = 550+10;
    position3 = 0;
    positionAdder3 = (frequency3/44100.0)* TWO_PI;   
    
    frequency4 = 770+15;
    position4 = 0;
    positionAdder4 = (frequency4/44100.0)* TWO_PI;
    
    frequency5 = 990+20;
    position5 = 0;
    positionAdder5 = (frequency5/44100.0)* TWO_PI;   
   
    frequency6 = 1210+25;
    position6 = 0;
    positionAdder6 = (frequency6/44100.0)* TWO_PI;   
    
    frequency7 = 1320+30;
    position7 = 0;
    positionAdder7 = (frequency7/44100.0)* TWO_PI;
}

//--------------------------------------------------------------
void testApp::update(){
    myCircleR = myCircleX/7+myCircleY/7;
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(50, 50, 50,20);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255, 255, 255);
    //ofSetColor(250, 214, 52, 255);
    //ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
    //ofRect(ofGetWidth()/2-sampleNum+1*100/2, ofGetHeight()/2-sampleNum+1*100/2, sampleNum+1*100, sampleNum+1*100);
    //ofCircle(myCircleX, myCircleY, myCircleR);
    
    // while loop
    int x =0;
    while (x < ofGetWidth()) {
        ofLine(x,0,x,ofGetHeight());
        //x+=20/sampleNum;
        x+=sampleNum*300;
    }
    // always do if condition is true
    
    //cout << sampleNum << endl;
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
 /*   myCircleX = x;
    myCircleY = y;
    
    frequency = y+100;
    frequency2 = x+100;
    frequency3 = y+101;
    
    positionAdder = (frequency/44100.0)*TWO_PI;
    positionAdder2 = (frequency2/44100.0)* TWO_PI;
    positionAdder3 = (frequency3/44100.0)* TWO_PI;
  */
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
        float sample4 = sin(position4);        
        float sample5 = sin(position5);        
        float sample6 = sin(position6);        
        float sample7 = sin(position7);
        
        position += positionAdder;
        position2 += positionAdder2;
        position3 += positionAdder3;
        position4 += positionAdder4;
        position5 += positionAdder5;
        position6 += positionAdder6;
        position7 += positionAdder7;
        
        output[i* 2 + 0 ] = (sample/8)+(sample2/8)+(sample3/8)+(sample4/8)+(sample5/8)+(sample6/8)+(sample7/8); 
        output[i* 2 + 1 ] = (sample/8)+(sample2/8)+(sample3/8)+(sample4/8)+(sample5/8)+(sample6/8)+(sample7/8); 
        sampleNum = (sample/8)+(sample2/8)+(sample3/8)+(sample4/8)+(sample5/8)+(sample6/8)+(sample7/8); 

        
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