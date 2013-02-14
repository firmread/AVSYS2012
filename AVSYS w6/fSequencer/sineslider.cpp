//
//  sineslider.cpp
//  fSequencer
//
//  Created by firm on 2/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "sineslider.h"



//--------------------------------------------------------------
void sineslider::setup(ofRectangle _rect, float _frequency){
    
    rect = _rect;
    frequency = _frequency;

    position = 0;
    positionAdder = (frequency/44100.0) * TWO_PI;
	
    
    minFreq = 120;
    maxFreq = 900;
    
    
    
}


//--------------------------------------------------------------
void sineslider::update(){
    
    positionAdder = (frequency/44100.0)*TWO_PI;
    
}

//--------------------------------------------------------------

void sineslider::draw(ofColor background, ofColor slider){
    
    ofSetColor(background);
    ofRect(rect);
    
    ofFill();
    ofSetColor(slider);
    ofRect(rect.x, ofMap(frequency, minFreq, maxFreq, rect.y, rect.y+rect.height*9/10), rect.width, rect.height/10);
    
    

}





//--------------------------------------------------------------
void sineslider::mouseAct(int x,int y){
    
    if (rect.inside(x,y)) { 
        frequency = ofMap(y, rect.y, rect.y+rect.height*9/10, minFreq, maxFreq);   
    }
     
    
}

//--------------------------------------------------------------












