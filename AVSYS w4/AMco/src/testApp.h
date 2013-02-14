#pragma once

#include "ofMain.h"
#include "ofxControlPanel.h"

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
	
		void audioRequested 	(float * input, int bufferSize, int nChannels);

		ofxControlPanel  panel;
		
		
		float		frequency,      frequency2;
		float		position,       position2;
		float		positionAdder,  positionAdder2;
		
		float		frequencyModulator,     frequencyModulator2;
		float		positionModulator,      positionModulator2;
		float		positionModulatorAdder, positionModulatorAdder2;
		
		float       modulator,  modulator2;
		float       sample,     sample2;
};
