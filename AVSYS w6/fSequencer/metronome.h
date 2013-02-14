//
//  metronome.h
//  fSequencer
//
//  Created by firm on 2/29/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef fSequencer_metronome_h
#define fSequencer_metronome_h

#include "ofMain.h"

class metronome{
public:
    

    float   bpm;
    float   startTime;
    float   intervalTime;
    int     nTicks;
    bool    bTick;
    bool    bPressed;
    
    ofRectangle rect;
    ofColor     color;
    
    void setup(ofRectangle _rect);
    void update(int nSteps);
    void draw(ofColor _active, ofColor _passive);
    void mouseDown(int x,int y);
    void keyBPMctrl(int key);
    
};


#endif
