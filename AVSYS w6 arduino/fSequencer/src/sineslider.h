//
//  sineslider.h
//  fSequencer
//
//  Created by firm on 2/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef fSequencer_sineslider_h
#define fSequencer_sineslider_h


#include "ofMain.h"

class sineslider{
public:

    int     frequency;
    float   position;
    float   positionAdder;
    
    int     minFreq;
    int     maxFreq;           // min and max freq for the oscilator
    int     stepWidth;                  // width for each step on screen
    
    ofRectangle rect;
    
    void setup(ofRectangle _rect, float _frequency);
    void update();
    void draw(ofColor background, ofColor slider);
    void mouseAct(int x,int y);
    
};

#endif
