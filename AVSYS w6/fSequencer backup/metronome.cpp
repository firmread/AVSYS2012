//
//  metronome.cpp
//  fSequencer
//
//  Created by firm on 2/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "metronome.h"

//--------------------------------------------------------------
void metronome::setup(ofRectangle _rect){
    
    rect = _rect;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    bPressed = false;
    
    
    startTime = ofGetElapsedTimeMillis();
    bpm = 120;
    intervalTime = (60.0/bpm/4)*1000;
    bTick = false; 
    nTicks = 0;
    
}


//--------------------------------------------------------------
void metronome::update(int nSteps){
//    if (bPressed){
//        if (ofGetElapsedTimeMillis() - intervalTime > startTime) {
//            nTicks++;
//            startTime = ofGetElapsedTimeMillis();
//            bTick = true;
//            if (nTicks >= nSteps) nTicks = 0;
//        } 
//        else {
//            bTick = false;
//        }
//    }
}


//--------------------------------------------------------------
void metronome::draw(ofColor _active, ofColor _passive){
    
    if(bPressed){
        color.set(_active);
        ofFill();
    }
    else {
        color.set(_passive);
        ofNoFill();
    }
    
    ofSetColor(color.r, color.g, color.b);
    ofRect(rect);
    
}



//--------------------------------------------------------------
void metronome::mouseDown(int x, int y){
    
    if(rect.inside(x, y)) bPressed =! bPressed;
    
}

//--------------------------------------------------------------
void metronome::keyBPMctrl(int key){
    
    switch (key) {
        case '+':
            bpm+=5;                                // increase bpm by 10
            intervalTime = (60.0/bpm/4)*1000;       // update the interval time
            break;
        case '-':
            bpm-=5;                                // decrease bpm by 10
            intervalTime = (60.0/bpm/4)*1000;       // update the interval time
            break;
    }

}