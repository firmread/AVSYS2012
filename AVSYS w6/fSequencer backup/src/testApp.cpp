#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableAlphaBlending();
	
	ofBackground(30, 30, 30);
    
    ofRectangle nomeRect (0,0,50,50);
    nome.setup(nomeRect);
    
    
    drum.loadSound("BT7AADA.WAV");
    drum.setLoop(false);
    
    drum2.loadSound("nf_gb_nl_kick_021.wav");
    drum2.setLoop(false);
    
    drum3.loadSound("nf_gb_nl_snare_004.wav");
    drum3.setLoop(false);
    
    drum4.loadSound("nf_gb_nl_hat_032.wav");
    drum4.setLoop(false);
    
    drum5.loadSound("nf_gb_nl_bass_016.wav");
    drum5.setLoop(false);
    
    drum6.loadSound("nf_gb_nl_noise_003.wav");
    drum6.setLoop(false);
    
    
    for (int i = 0; i< N_STEPS; i++) {
        ofRectangle tempRect (50+(30*i), 75, 25, 25);
        drumStep[i].setup(tempRect);
        
        ofRectangle tempRect2 (50+(30*i), 105, 25, 25);
        drumStep2[i].setup(tempRect2);
        
        ofRectangle tempRect3 (50+(30*i), 135, 25, 25);
        drumStep3[i].setup(tempRect3);
        
        ofRectangle tempRect4 (50+(30*i), 165, 25, 25);
        drumStep4[i].setup(tempRect4);
        
        ofRectangle tempRect5 (50+(30*i), 195, 25, 25);
        drumStep5[i].setup(tempRect5);
        
        ofRectangle tempRect6 (50+(30*i), 225, 25, 25);
        drumStep6[i].setup(tempRect6);
        
    }
    
    
    
    ofSoundStreamSetup(2, 0, this, 44100, 512, 4);
    
    frequency = 0;
    position = 0;
    positionAdder = (frequency/44100.0) * TWO_PI;
    
    
    minFreq = 120;
    maxFreq = 900;
    stepWidth = ofGetWidth()/N_STEPS;
    
    
    for(int i = 0; i < N_STEPS; i ++){
        frequencies[i] = ofRandom(minFreq, maxFreq);
    }

}

//--------------------------------------------------------------
void testApp::update(){
//    nome.update(N_STEPS);
    
    
    if (nome.bPressed){
        if (ofGetElapsedTimeMillis() - nome.intervalTime > nome.startTime) {
            nome.nTicks++;
            nome.startTime = ofGetElapsedTimeMillis();
            nome.bTick = true;
            if (nome.nTicks >= N_STEPS) nome.nTicks = 0;
            
            if (drumStep[nome.nTicks].bPressed) {
                drum.play();
            }
            
            if (drumStep2[nome.nTicks].bPressed) {
                drum2.play();
            }
            
            if (drumStep3[nome.nTicks].bPressed) {
                drum3.play();
            }
            
            if (drumStep4[nome.nTicks].bPressed) {
                drum4.play();
            }
            
            if (drumStep5[nome.nTicks].bPressed) {
                drum5.play();
            }
            
            if (drumStep6[nome.nTicks].bPressed) {
                drum6.play();
            }
            
        } 
        else {
            nome.bTick = false;
        }
    }
    
    
    frequency = frequencies[nome.nTicks];
    positionAdder = (frequency/44100.0)*TWO_PI;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //highlight
    ofFill();
    ofSetColor(27, 165, 224, 50);
    ofRect(50+(30*nome.nTicks), 50, 25, ofGetHeight());
    
    
    ofColor active (27,165,224);
    ofColor goingon (4,24,173);
    ofColor passive (100,100,100);
    
    nome.draw(active, passive);
    ofDrawBitmapString("bpm :: " + ofToString(nome.bpm), 50, 10);
    
    ofDrawBitmapString("interval Time ::" + ofToString(nome.intervalTime), 50, 20);
    
    ofDrawBitmapString("current step :: " +  ofToString(nome.nTicks+1), 50, 30);
    
    for (int i = 0; i< N_STEPS; i++) {
        drumStep[i].draw(goingon, passive);
        drumStep2[i].draw(goingon, passive);
        drumStep3[i].draw(goingon, passive);
        drumStep4[i].draw(goingon, passive);
        drumStep5[i].draw(goingon, passive);
        drumStep6[i].draw(goingon, passive);
        
    }
        
    
    
}

//--------------------------------------------------------------
void testApp::audioRequested(float *output, int bufferSize, int nChannels){
    


}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    nome.keyBPMctrl(key);
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
    nome.mouseDown(x, y);
    
    for (int i = 0; i< N_STEPS; i++) {
        drumStep[i].mouseDown(x, y);
        drumStep2[i].mouseDown(x, y);
        drumStep3[i].mouseDown(x, y);
        drumStep4[i].mouseDown(x, y);
        drumStep5[i].mouseDown(x, y);
        drumStep6[i].mouseDown(x, y);
    }
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