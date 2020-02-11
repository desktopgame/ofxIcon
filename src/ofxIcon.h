#ifndef OFXICON_H
#define OFXICON_H
#include <ofColor.h>
#include <ofPixels.h>

namespace ofxIcon {

/**
 * ButtonStyle.
 */
struct ButtonStyle {
	explicit ButtonStyle();

	ButtonStyle& edgeSize(int _edgeSize);
	ButtonStyle& press(bool _press);
	ButtonStyle& borderColor(ofColor _borderColor);
	ButtonStyle& fillColor0(ofColor _fillColor0);
	ButtonStyle& fillColor1(ofColor _fillColor1);
	ButtonStyle& fillColor2(ofColor _fillColor2);

	int _edgeSize;
	bool _press;
	ofColor _borderColor;
	ofColor _fillColor0;
	ofColor _fillColor1;
	ofColor _fillColor2;
};
/**
 * @param pixels
 * @pram style
 */
void writeButtonImage(ofPixels& pixels, ButtonStyle style);

/**
 * InputFieldStyle.
 */
struct InputFieldStyle {
	explicit InputFieldStyle();

	InputFieldStyle& edgeSize(int _edgeSize);
	InputFieldStyle& fillColor(ofColor _fillColor);
	InputFieldStyle& borderShadowColor(ofColor _borderShadowColor);
	InputFieldStyle& borderLightColor(ofColor _borderLightColor);

	int _edgeSize;
	ofColor _fillColor;	
	ofColor _borderShadowColor;
	ofColor _borderLightColor;
};

/**
 * @param pixels
 * @param style
 */
void writeInputFieldImage(ofPixels& pixels, InputFieldStyle style);

/**
 * DropdownStyle.
 */
struct DropdownStyle {
	explicit DropdownStyle();

	DropdownStyle& edgeSize(int _edgeSize);
	DropdownStyle& fillColor(ofColor _fillColor);
	DropdownStyle& borderColor(ofColor _borderColor);
	DropdownStyle& fillSlotColor0(ofColor _fillSlotColor0);
	DropdownStyle& fillSlotColor1(ofColor _fillSlotColor1);
	DropdownStyle& fillSlotColor2(ofColor _fillSlotColor2);
	DropdownStyle& triangleColor(ofColor _triangleColor);

	int _edgeSize;
	ofColor _fillColor;
	ofColor _borderColor;
	ofColor _fillSlotColor0;
	ofColor _fillSlotColor1;
	ofColor _fillSlotColor2;
	ofColor _triangleColor;
};

/**
 * @param pixels
 * @param style
 */
void writeDropdownImage(ofPixels& pixels, DropdownStyle style);
}
#endif