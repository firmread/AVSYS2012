#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
//    ofSetFrameRate(30);
	ofSetVerticalSync(true);
    
    boonmee.loadMovie("bmwaterloop.mov");
    boonmee.play();
    
    ofSetWindowShape(boonmee.width, boonmee.height);
    bFullscreen = false;
    
	ofSoundStreamSetup(0, 2, this, 44100, 512, 4);
	inputBufferCopy = new float [512 *2];

    boxSize = 10;
    boxNo = 15;
    
    for (int i=0; i<boxNo; i++) {
        p[i].x = ofMap(i, 0, boxNo-1, 0, ofGetWidth());
        p[i].y = ofGetHeight() / 2.0;
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    boonmee.idleMovie();
    float speed = 0.5 + volume;
    boonmee.setSpeed(speed);
    boonmee.setVolume(100+ speed*500);
    
    for (int i=0; i<boxNo; i++) {
        p[i].x = ofMap(i, 0, boxNo-1, 0, ofGetWidth());
        p[i].y = ofGetHeight() / 2.0;
    }
    
    boxSize = 10 + volume*100;
}

//--------------------------------------------------------------
void testApp::draw(){
    boonmee.draw(0,0,ofGetWidth(),ofGetHeight());
    

//		float sample = ofMap(inputBufferCopy[j*2], -1, 1, -200, 200);
//		ofVertex(100+j, 100 + sample);
    

    for (int i=0; i<boxNo; i++) {   
//        ofNoFill();
        ofEnableAlphaBlending();
        ofSetColor(255, 255, 255,255-(volume*255));
        
        ofSetRectMode(OF_RECTMODE_CENTER);
            
        for(int j =0; j< 512; j++){
            int posmap = (j*2*boxNo)/512;
            float sample = ofMap(inputBufferCopy[posmap], -1, 1, -200, 200);
            p[i].y = (ofGetHeight() / 2.0) + sample ;
            cout << sample << endl;
        }
        
         
        ofRect (p[i].x, p[i].y, boxSize,boxSize);
            
        
    }
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDisableAlphaBlending();


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'f'||key == 'F'){
        
		bFullscreen = !bFullscreen;
		
		if(!bFullscreen){
			ofSetFullscreen(false);
		} else if(bFullscreen == 1){
			ofSetFullscreen(true);
		}
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
//--------------------------------------------------------------
void testApp::audioReceived(float *input, int bufferSize, int nChannels){
	memcpy(inputBufferCopy, input, bufferSize*nChannels*sizeof(float));
	volume = 0;
	for(int i = 0; i < bufferSize * nChannels; i++){
		volume+= input[i]*input[i]; // add the square value to emliminate any negative values
	}
	volume /= bufferSize *nChannels; // get the average of all square values
	volume = sqrt(volume);
	

}	