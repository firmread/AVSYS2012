#pragma once

#include "ofMain.h"
#include "ofEvents.h"


class testApp : public ofSimpleApp{

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);

	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
		
    //arduino
	void setupArduino(const int & version);
	void updateArduino();

	ofArduino	ard;
	bool		bSetupArduino;
    
    //sound
    void audioRequested 	(float * input, int bufferSize, int nChannels);
    
    float		carrier_frequency;
    float		carrier_position;
    float		carrier_positionAdder;
    
    float		fm_frequency;
    float		fm_position;
    float		fm_positionAdder;
    
    float		am_frequency;
    float		am_position;
    float		am_positionAdder;
    
    float		lowFreq;
    float		highFreq;
	
    float       am;
    float		sample;

};

