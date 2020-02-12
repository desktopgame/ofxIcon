#include "ofApp.h"
#include <ofxIcon.h>

//--------------------------------------------------------------
void ofApp::setup(){
	ofPixels pix;
	pix.allocate(300, 60, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeButtonImage(pix, ofxIcon::ButtonStyle());
	buttonImage.setFromPixels(pix);

	ofPixels pix2;
	pix2.allocate(300, 60, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeInputFieldImage(pix2, ofxIcon::InputFieldStyle());
	inputFieldImage.setFromPixels(pix2);

	ofPixels pix3;
	pix3.allocate(300, 60, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeDropdownImage(pix3, ofxIcon::DropdownStyle());
	dropdownImage.setFromPixels(pix3);

	ofPixels pix4;
	pix4.allocate(30, 30, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeCheckBoxImage(pix4, ofxIcon::CheckBoxStyle());
	checkboxImage.setFromPixels(pix4);

	ofPixels pix5;
	pix5.allocate(30, 30, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeCheckBoxImage(pix5, ofxIcon::CheckBoxStyle().selected(true));
	checkboxImage2.setFromPixels(pix5);

	ofPixels pix6;
	pix6.allocate(30, 30, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeRadioButtonImage(pix6, ofxIcon::RadioButtonStyle());
	radioButtonImage.setFromPixels(pix6);

	ofPixels pix7;
	pix7.allocate(30, 30, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeRadioButtonImage(pix7, ofxIcon::RadioButtonStyle().selected(true));
	radioButtonImage2.setFromPixels(pix7);

	ofSetBackgroundColor(ofColor::gray);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	buttonImage.draw(0, 0);
	inputFieldImage.draw(0, 65);
	dropdownImage.draw(0, 130);
	checkboxImage.draw(0, 195);
	checkboxImage2.draw(35, 195);
	radioButtonImage.draw(0, 230);
	radioButtonImage2.draw(35, 230);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
