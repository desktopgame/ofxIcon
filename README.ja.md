ofxIcon
=====================================

ofxIconはゲーム用のアイコンジェネレータです。
![screenshot](ss.png)

Introduction
------------
ofxIconはゲーム用のアイコンジェネレータです。
最初のスクリーンショットは以下のコードで生成されています。

````
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
````

License
-------
State which license you offer your addon under. openFrameworks is distributed under the [MIT License](https://en.wikipedia.org/wiki/MIT_License), and you might consider using this for your repository. By default, `license.md` contains a copy of the MIT license to which you can add your name and the year.

Installation
------------
このフォルダーを `openFrameworks/addons/` に置いてください。

Dependencies
------------
依存関係はありません。

Compatibility
------------
* of_v0.10.1_vs2017_release
* Windows10

Known issues
------------
現在のところ、既知の不具合はありません。

Version history
------------


### Version 0.1 (2020/02/12):
最初のリリースです。


