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

	ofPixels pix8;
	pix8.allocate(300, 15, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeSliderImage(pix8, ofxIcon::SliderStyle());
	sliderImage.setFromPixels(pix8);

	ofPixels pix9;
	pix9.allocate(300, 15, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeSliderImage(pix9, ofxIcon::SliderStyle().fillColor0(ofColor::gray).fillColor1(ofColor::white).fillColor2(ofColor::gray));
	sliderImage2.setFromPixels(pix9);

	ofPixels pix10;
	pix10.allocate(30, 30, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeSliderKnobImage(pix10, ofxIcon::SliderKnobStyle());
	sliderKnobImage.setFromPixels(pix10);

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
	sliderImage.drawSubsection(0, 265, 150, 15,0, 0);
	sliderImage2.drawSubsection(150, 265, 150, 15, 150, 0);
	sliderKnobImage.draw((300-30)/2, 265-((30 - 15)/2));
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
