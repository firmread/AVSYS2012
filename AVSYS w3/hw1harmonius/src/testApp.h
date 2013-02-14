#pragma once

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
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void audioRequested(float *input, int bufferSize, int nChannels);
        
        float frequency,frequency2,frequency3,frequency4,frequency5,frequency6,frequency7;
        float position,position2,position3,position4,position5,position6,position7;
        float positionAdder,positionAdder2,positionAdder3,positionAdder4,positionAdder5,positionAdder6,positionAdder7;
    
};
