#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

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
    
    //----------sound	
    void audioRequested 	(float * input, int bufferSize, int nChannels);
    
    float		carrier_frequency;
    float		carrier_position;
    float		carrier_positionAdder;
    
    float		modulator_frequency;
    float		modulator_position;
    float		modulator_positionAdder;
    
    float		lowFreq;
    float		highFreq;
	
    float		sample;
    
    
    //----------metronome variables
    int currentTime;
    int intervalTime;
    int nTicks;
    bool bTick;
    
    //----------angle finder variables
    ofPoint		prevPos;
    float		angle;
    
    //----------points recorder variables
    vector < ofPoint > points;


    //firm modulation
    float shapeSize,shapeAngle;
    bool clicktest;
    bool textSetup;
    int beat;
    int counter;
};

#endif
