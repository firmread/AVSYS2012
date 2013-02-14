//
//  stepButton.h
//  simpleSequencer_
//
//  Created by rux on 2/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef simpleSequencer__stepButton_h
#define simpleSequencer__stepButton_h

#include "ofMain.h"

class stepButton{

public:
    void setup(ofRectangle _rect); 
    void draw(ofColor _active, ofColor _passive);
    
    void mouseDown(int x, int y);
    
    ofRectangle rect;      
    ofColor     color;      
    
    bool        bPressed;   

}; 


#endif
