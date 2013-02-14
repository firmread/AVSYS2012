#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	//ofSetFrameRate(60);
	ofSetCircleResolution(100);
	
	panel.setup("control", 770, 0, 300, 400);				//Name of your panel
	panel.addPanel("color", 1, false);						//Name of each section. Number of columns. Locked?
	panel.addPanel("geometry", 1, false);
	
	panel.setWhichPanel("color");							//Which panel would we like to manipulate
	panel.addSlider("red", "VAL_RED", 0,0,255, false);		//Add slider. Slider Name. Xml name. Starting value. Min Value. Max value. Is it an int?
	panel.addSlider("green", "VAL_GREEN", 0,0,255, false);
	panel.addSlider("blue", "VAL_BLUE",0,0,255, false);
	
	panel.setWhichPanel("geometry");						//Which panel would we like to manipulate
	panel.addToggle("rect", "VAL_RECT", true);				//Toggle name. Xml name. default value?  
	
	panel.loadSettings("settings.xml");						//Load settings from xml
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	panel.update();											//Update panel every frame

}

//--------------------------------------------------------------
void testApp::draw(){
	ofEnableAlphaBlending();
	
	ofSetColor(panel.getValueF("VAL_RED"), panel.getValueF("VAL_GREEN"), panel.getValueF("VAL_BLUE")); //Pull value from sliders in panel as floats
	
	if (panel.getValueB("VAL_RECT")){
		ofRect(10,10,800,600);
	} else {
		ofCircle(400,400,200);
	}
	
	panel.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	panel.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	panel.mousePressed(x,y,button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	panel.mouseReleased();
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