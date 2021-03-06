#pragma once

#include "ofMain.h"
#include "metronome.h"
#include "stepButton.h"

#define N_STEPS 16
class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    metronome nome;
    int beatCount;
    
    stepButton      drumStep[N_STEPS];
    ofSoundPlayer   drum;
    
    stepButton      drumStep2[N_STEPS];
    ofSoundPlayer   drum2;
    
    stepButton      drumStep3[N_STEPS];
    ofSoundPlayer   drum3;
    
    stepButton      drumStep4[N_STEPS];
    ofSoundPlayer   drum4;
    
    stepButton      drumStep5[N_STEPS];
    ofSoundPlayer   drum5;
    
    stepButton      drumStep6[N_STEPS];
    ofSoundPlayer   drum6;
    
    
    // audioRequested
    void    audioRequested(float *input, int bufferSize, int nChannels);
    int     frequency;
    float   position, positionAdder;
    
    int     minFreq, maxFreq;           // min and max freq for the oscilator
    int     stepWidth;                  // width for each step on screen
    
    // sine waves
    float   frequencies[N_STEPS];

};
