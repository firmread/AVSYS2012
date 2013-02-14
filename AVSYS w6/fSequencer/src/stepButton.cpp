//
//  stepButton.cpp
//  simpleSequencer_
//
//  Created by rux on 2/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "stepButton.h"        

// -----------------------------------
void stepButton::setup(ofRectangle _rect){
     rect = _rect;
    color.r = 190;
    color.g = 190;
    color.b = 190;
    
    bPressed = false;
}


// -----------------------------------
void stepButton::draw(ofColor _active, ofColor _passive){
    
    
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


// -----------------------------------
void stepButton::mouseDown(int x, int y){
 
    if (rect.inside(x,y)) bPressed =! bPressed;

}




