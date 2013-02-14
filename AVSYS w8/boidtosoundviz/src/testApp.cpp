#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    
    for(int i=0; i<1; i++) {
        Boid newBoid;
        newBoid.setup(ofRandom(3, 7), 10);
        
        boids.push_back( newBoid );
    }
    
	ofSetVerticalSync(true);
	ofSoundStreamSetup(0, 2, this, 44100, 512, 4);
	inputBufferCopy = new float [512 *2];

}

//--------------------------------------------------------------
void testApp::update(){
    
    mouse.x = mouseX;
    mouse.y = mouseY;
    
    for(int i=0; i<boids.size(); i++) {
        
        boids[i].addNoise();
        boids[i].accelerateTowards(mouse);
        
        boids[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    
    for(int i=0; i<boids.size(); i++) {
    
        for(int j =0; j< 512; j++){
            float sample = ofMap(inputBufferCopy[j*2], -1, 1, 0, 200);
            boids[i].draw(j,sample);
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    Boid newBoid;
    newBoid.setup(ofRandom(3, 7), 10);
    
    boids.push_back( newBoid );
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
    
    boids.erase( boids.begin() );
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