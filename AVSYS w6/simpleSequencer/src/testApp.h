#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "stepButton.h" // <-------------- don't forget to include the class.h file 

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
    
        
        // metronome stuff
        float startTime;
        float intervalTime;
        int nTicks;
        bool bTick;
        
        float bpm;
        
        stepButton myStep[N_STEPS];     // array of stepButtons objects
        
        ofSoundPlayer   beat;           // sound player object


};

#endif
