#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

#define N_STEPS 8

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
    
        int currentTime;
        float intervalTime;
        int nTicks;
        bool bTick;
    
        void    audioRequested(float *input, int bufferSize, int nChannels);
        int     frequency;
        float   position, positionAdder;
        
        int     minFreq, maxFreq;           // min and max freq for the oscilator
        int     stepWidth;                  // width for each step on screen

        
        float   frequencies[N_STEPS];
};

#endif
