#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


    // Try loading both movies to see the difference between using a "controlled" background 
    // and a cluttered background
    //vidPlayer.loadMovie("fingers.mov");
    
    ofHideCursor();
//    vidPlayer.loadMovie("background.mov");
//    vidPlayer.play();
    
    vidPlayer.initGrabber(320,240);
    
    // ofxCvColorImage and ofxCvGrayscaleImage are just like ofImage
    colorImg.allocate   (320,240);
	grayImage.allocate  (320,240);
	grayBg.allocate     (320,240);
	grayDiff.allocate   (320,240);

	bLearnBakground = true;
	threshold = 80;
}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(100,100,100);
    vidPlayer.update();

    // Step 1. put the pixels from the video camera into the ofxCvColorImage
    colorImg.setFromPixels(vidPlayer.getPixels(), 320, 240);

    // Step 2. Convert the ofxCvColorImage to ofxCvGrayscaleImage
    // remember: this means stripping out the color image, from 3 values per pixel (r,g,b) to 1 value per pixel (gray)
    grayImage = colorImg;
    
    // Step 3. When the user hits spacebar, bLearnBakground is set to true
    // This will save a "copy" of grayImage into grayBg so that we can use it later
    // 
    if (bLearnBakground == true)
    {
        grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
        bLearnBakground = false;
    }

    
    // Step 4: take the abs value of the difference between background and incoming and then threshold:
    // In other words, the only pixels we care about are the ones that are different between 
    // the background and the current frame
    grayDiff.absDiff(grayBg, grayImage);
    grayDiff.threshold(threshold);
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    grayDiff.dilate();
    
    
    // Step 5. find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
    contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, false);


}

//--------------------------------------------------------------
void testApp::draw(){

	// draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetHexColor(0xffffff);
	colorImg.draw(20,20);
	grayImage.draw(360,20);
	grayBg.draw(20,280);
	grayDiff.draw(360,280);

	// then draw the contours:

	ofFill();
	ofSetHexColor(0x333333);
	ofRect(360,540,320,240);
	ofSetHexColor(0xffffff);

	// we could draw the whole contour finder
	//contourFinder.draw(360,540);

	// or, instead we can draw each blob individually,
	// this is how to get access to them:
    for (int i = 0; i < contourFinder.nBlobs; i++)
    {
        contourFinder.blobs[i].draw(360,540);
        for (int j = 0; j < contourFinder.blobs[i].nPts; j++){
            ofPoint p = contourFinder.blobs[i].pts[j];
            int x = ofMap(p.x, 0, 320, 0, ofGetWidth()); 
            int y = ofMap(p.y, 0, 240, 0, ofGetHeight());
            ofCircle (x,y,5);
        }
        
    }

	// finally, a report:

	ofSetHexColor(0xffffff);
	char reportStr[1024];
	sprintf(reportStr, "bg subtraction and blob detection\npress ' ' to capture bg\nthreshold %i (press: +/-)\nnum blobs found %i, fps: %f", threshold, contourFinder.nBlobs, ofGetFrameRate());
	ofDrawBitmapString(reportStr, 20, 600);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch (key){
		case ' ':
			bLearnBakground = true;
			break;
		case '+':
			threshold ++;
			if (threshold > 255) threshold = 255;
			break;
		case '-':
			threshold --;
			if (threshold < 0) threshold = 0;
			break;
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
