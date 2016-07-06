#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	ofSetVerticalSync(true);

	tess.setup();
	tess.setWhitelist("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,");
	//tess.setAccuracy(ofxTesseract::ACCURATE);
	tess.setMode(ofxTesseract::AUTO);

	img.loadImage("article.png");
	img.setImageType(OF_IMAGE_GRAYSCALE);
	img.update();

	//ocrResult = runOcr(2.5, 2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofPushMatrix();

	ofTranslate(300, 0);

	ofSetColor(255);
	vector<string> lines = ofSplitString(ocrResult, "\n");
	for (int i = 0; i < lines.size(); i++) {
		ofDrawBitmapString(lines[i], 10, 20 + i * 12);
	}

	ofSetColor(255);
	img.draw(0, 200);
	scaled.draw(0, 400);

	ofPopMatrix();

}

// depending on the source of the text you want to OCR,
// you might need to preprocess it. here i'm doing a
// simple resize followed by a median blur.
string ofApp::runOcr(float scale, int medianSize) {
	scaled = img;

	// resize and median blur the image
	scaled.resize(img.getWidth() * scale, img.getHeight() * scale);

	//medianBlur(scaled, medianSize);

	return tess.findText(scaled);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ocrResult = runOcr(2.5, 2);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
