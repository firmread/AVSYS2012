//
//  stepButton.cpp
//  simpleSequencer_
//
//  Created by rux on 2/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "stepButton.h"         // we need to include the .h file

// -----------------------------------
void stepButton::setup(ofRectangle _rect){
     rect = _rect;
    color.r = 190;
    color.g = 190;
    color.b = 190;
    
    bPressed = false;
}


// -----------------------------------
void stepButton::draw(){
    
    // using the bool to give us visual feedback on the button status
    // by changing its color and fill/noFill
    
    if(bPressed == true){
        color.set(255, 255, 0);
        ofFill();
    } else {
        color.set(190, 190, 190);
        ofNoFill();
    }
    
    // drawing the button
    ofSetColor(color.r, color.g, color.b);
    ofRect(rect);
}


// -----------------------------------
void stepButton::mouseDown(int x, int y){
 
    if(rect.inside(x, y) == true){
        bPressed =! bPressed;
    }    
    
    //here's a shorter way of saying exactly the same thing:
    // if (rect.inside(x,y)) bPressed =! bPressed;

}




