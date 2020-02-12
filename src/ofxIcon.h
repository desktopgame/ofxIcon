#ifndef OFXICON_H
#define OFXICON_H
#include <ofColor.h>
#include <ofPixels.h>

namespace ofxIcon {
namespace util {
/**
 * @param pixels
 * @param color
 */
void fillColor(ofPixels& pixels, ofColor color);

/**
 * @param pixels
 * @param color
 * @param edgeSize
 */
void drawBorder(ofPixels& pixels, ofColor color, int edgeSize);

/**
 * @param pixels
 * @param color
 * @param start
 * @param end
 * @see https://ja.wikipedia.org/wiki/%E3%83%96%E3%83%AC%E3%82%BC%E3%83%B3%E3%83%8F%E3%83%A0%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
 */
void drawLine(ofPixels& pixels, ofColor color, glm::ivec2 start, glm::ivec2 end);
}

/**
 * ButtonStyle.
 */
struct ButtonStyle {
	explicit ButtonStyle();

	ButtonStyle edgeSize(int _edgeSize);
	ButtonStyle press(bool _press);
	ButtonStyle borderColor(ofColor _borderColor);
	ButtonStyle fillColor0(ofColor _fillColor0);
	ButtonStyle fillColor1(ofColor _fillColor1);
	ButtonStyle fillColor2(ofColor _fillColor2);

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

	InputFieldStyle edgeSize(int _edgeSize);
	InputFieldStyle fillColor(ofColor _fillColor);
	InputFieldStyle borderShadowColor(ofColor _borderShadowColor);
	InputFieldStyle borderLightColor(ofColor _borderLightColor);

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

	DropdownStyle edgeSize(int _edgeSize);
	DropdownStyle fillColor(ofColor _fillColor);
	DropdownStyle borderColor(ofColor _borderColor);
	DropdownStyle fillSlotColor0(ofColor _fillSlotColor0);
	DropdownStyle fillSlotColor1(ofColor _fillSlotColor1);
	DropdownStyle fillSlotColor2(ofColor _fillSlotColor2);
	DropdownStyle triangleColor(ofColor _triangleColor);
	DropdownStyle minSlotWidth(int _minSlotWidth);
	DropdownStyle maxSlotWidth(int _maxSlotWidth);
	int computeSlotWidth(int width) const;

	int _edgeSize;
	int _minSlotWidth;
	int _maxSlotWidth;
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

/**
 * CheckBoxStyle.
 */
struct CheckBoxStyle {
	explicit CheckBoxStyle();

	CheckBoxStyle edgeSize(int _edgeSize);
	CheckBoxStyle selected(bool _selected);
	CheckBoxStyle lineColor(ofColor _lineColor);
	CheckBoxStyle fillColor0(ofColor _fillColor0);
	CheckBoxStyle fillColor1(ofColor _fillColor1);
	CheckBoxStyle fillColor2(ofColor _fillColor2);

	int _edgeSize;
	bool _selected;
	ofColor _lineColor;
	ofColor _borderColor;
	ofColor _fillColor0;
	ofColor _fillColor1;
	ofColor _fillColor2;
};

/**
 * @param pixels
 * @param style
 * @return
 */
void writeCheckBoxImage(ofPixels& pixels, CheckBoxStyle style);

/**
 * RadioButtonStyle.
 */
struct RadioButtonStyle {
	explicit RadioButtonStyle();

	RadioButtonStyle edgeSize(int _edgeSize);
	RadioButtonStyle selected(bool _selected);
	RadioButtonStyle checkColor(ofColor _checkColor);
	RadioButtonStyle borderColor(ofColor _borderColor);
	RadioButtonStyle fillColor0(ofColor _fillColor0);
	RadioButtonStyle fillColor1(ofColor _fillColor1);
	RadioButtonStyle fillColor2(ofColor _fillColor2);

	int _edgeSize;
	bool _selected;
	ofColor _checkColor;
	ofColor _borderColor;
	ofColor _fillColor0;
	ofColor _fillColor1;
	ofColor _fillColor2;
};
/**
 * @param pixels
 * @param style
 * @return
 */
void writeRadioButtonImage(ofPixels& pixels, RadioButtonStyle style);
}
#endif