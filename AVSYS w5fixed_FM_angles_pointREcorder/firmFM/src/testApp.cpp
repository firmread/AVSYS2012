#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	ofBackground(50, 50, 50);
	
    
    //----------metronome
	currentTime = ofGetElapsedTimeMillis();
	intervalTime = 1000;
    bTick = false;
    nTicks = 0;
    
    
    //----------sound
	ofSoundStreamSetup(2,0,this, 44100,256, 4);
    
    carrier_frequency				= 100;
	carrier_position				= 0;
	carrier_positionAdder			= (carrier_frequency / 44100.0) * TWO_PI;
	
	
	lowFreq					= 50;
	highFreq				= 400;
	
	modulator_frequency		= 100;
	modulator_position		= 0;
	modulator_positionAdder	=  (modulator_frequency / 44100.0) * TWO_PI;
	
	sample					= 0;
    
    clicktest = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
   
    //----------metronome
    if (ofGetElapsedTimeMillis() - intervalTime > currentTime) {
        
        currentTime = ofGetElapsedTimeMillis();
        bTick = true;
        nTicks ++;
    } else {
        bTick = false;
    }
    
    beat = nTicks % 4; 
    
    //----------anglefinder
    float dx = mouseX - prevPos.x; //the distance between the current position and the previous 'x' position
	float dy = mouseY - prevPos.y; //the distance between the current position and the previous 'y' position
	
	angle = atan2(dy, dx); // use the x and y distances to calculate the angle between the two positions
    
    cout << "angle = " << angle << endl;
    
	prevPos.x = mouseX; 
	prevPos.y = mouseY; 
    
    
    
    //firm modulation
    if (!clicktest) {
        shapeSize = 65;
    }
    if(clicktest){
        
        shapeSize = (50-points.size())+15;
        shapeAngle = ofMap(angle, -4, 4, 0.1, 4);
    }
    
    
    
    //----------sound
    //carrier frequency 0-500
	lowFreq = MAX(mouseX/2 - 100, 0) ;
	highFreq = MIN(mouseX/2+angle*3 + 100, 44100.0/2) ;
    //modulator frequency 0.1-10
	modulator_positionAdder	= (ofMap(shapeSize, 15, 65, .5, 3) / 44100.0) * TWO_PI;
    
    
    if (beat == 1) {
        lowFreq *= 2; 
    }
    if (beat == 4) {
        highFreq *=2;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    if(textSetup){
        //----------metronome
        ofSetColor(200, 200, 200);
        ofDrawBitmapString("Tick = "+ ofToString(bTick) +"\nTicks" + ofToString(nTicks) +": beat" + ofToString(beat+1), ofPoint(50,50));
    }

    
    
    //----------sound
    if (textSetup) {
        ////Draw strings onto screen
        string stringLowFreq	= ofToString(lowFreq,2);
        ofDrawBitmapString("Lowest Freq:  "			+stringLowFreq, 50,200);
        
        string stringHIghFreq	= ofToString(highFreq,2);
        ofDrawBitmapString("Highest Freq:  "		+stringHIghFreq, 50,230);
        
        string freq				= ofToString(carrier_frequency,2);
        ofDrawBitmapString("Carrier frequency:  "			+freq, 50,260);
        
        string posMod			= ofToString(modulator_position,2);
        ofDrawBitmapString("Modulator position:  "	+posMod, 50,290);
        
        string posAdd			= ofToString(carrier_positionAdder,2);
        ofDrawBitmapString("Carrier Position Adder:  "		+posAdd, 50,320);
    }

    
    
    //----------points recorder 
    ofNoFill();
	ofSetColor(90, 90, 90);
	
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){
        
        //use each ofPoint coordinates to plot the shape vertices
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
    ofFill();
	
    if (textSetup) {
        // draw some usefull info on screen
        ofSetColor(200, 200, 200);
        ofDrawBitmapString("number of points :: " + ofToString(points.size(),0), 50, 125);

    }
    
    
    
    //----------anglefinder
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,150);
    
	ofPushMatrix();     
        ofTranslate(mouseX, mouseY, 0);
        ofRotateZ(angle * RAD_TO_DEG);
        ofRect( 0,0, shapeSize + modulator_position*3,shapeSize + modulator_position*3);
	ofPopMatrix();
    ofDisableAlphaBlending();
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 's'){
        textSetup = !textSetup;
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
   
    //----------points recorder 
    // create a temp ofPoint to store current mouse data
	ofPoint tempPt;
	tempPt.x = x;
	tempPt.y = y;
    
    // add it to the end of vector
	points.push_back(tempPt);
	
    // we can use this condition if we want to limit the number of points stored and 
    // erase the points at the beggining of the vector (the oldest stored)
    
	if (points.size() > 50){
		points.erase(points.begin());
	}
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //----------points recorder 
    // clear the vector - delets all of its contents
	points.clear();
    if(button == 0){
       clicktest = true; 
    }
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

    if(button == 0){
        clicktest = false; 
    }
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
//--------------------------------------------------------------
void testApp::audioRequested 	(float * output, int bufferSize, int nChannels){
	
	for (int i = 0; i < bufferSize; i++){
		
		carrier_frequency			=  ofMap(sin (modulator_position), -1,1, lowFreq,highFreq);
		modulator_position	+= modulator_positionAdder;
		carrier_positionAdder		= (carrier_frequency / 44100.0) * TWO_PI;
		
		sample				=sin( carrier_position );
		carrier_position			+= carrier_positionAdder;
		
		output[i * 2 + 0]	= sample;			// left channel
		output[i * 2 + 1]	= sample;			// right channel
		
	}
	
	
	// because sin(..) of very large values is less precise, let's keep the position variable in the range of 0 to TWO_PI.  it's cyclical
	// so doing something like this, is very similar to %= for integer numbers. 
	while (carrier_position > TWO_PI) {
		carrier_position -= TWO_PI;	
	}
	
	while (modulator_position > TWO_PI){
		modulator_position -= TWO_PI;	
	}
	
}
