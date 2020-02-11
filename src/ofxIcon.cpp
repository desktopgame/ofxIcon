#include "ofxIcon.h"
#include <iostream>

namespace ofxIcon {
ButtonStyle::ButtonStyle()
	: _edgeSize(2),
	  _press(false),
      _borderColor(ofColor::blue),
	  _fillColor0(ofColor::cyan),
	  _fillColor1(ofColor::white),
	  _fillColor2(ofColor::cyan) {
}
ButtonStyle & ButtonStyle::edgeSize(int _edgeSize) {
	this->_edgeSize = _edgeSize;
	return *this;
}
ButtonStyle & ButtonStyle::press(bool _press) {
	this->_press = _press;
	return *this;
}
ButtonStyle & ButtonStyle::borderColor(ofColor _borderColor) {
	this->_borderColor = _borderColor;
	return *this;
}
ButtonStyle & ButtonStyle::fillColor0(ofColor _fillColor0) {
	this->_fillColor0 = _fillColor0;
	return *this;
}
ButtonStyle & ButtonStyle::fillColor1(ofColor _fillColor1) {
	this->_fillColor1 = _fillColor1;
	return *this;
}
ButtonStyle & ButtonStyle::fillColor2(ofColor _fillColor2) {
	this->_fillColor2 = _fillColor2;
	return *this;
}
void writeButtonImage(ofPixels & pixels, ButtonStyle style) {
	if (style._press) {
		style._fillColor0 = style._fillColor0.lerp(ofColor::black, 0.5f);
		style._fillColor1 = style._fillColor1.lerp(ofColor::black, 0.5f);
		style._fillColor2 = style._fillColor2.lerp(ofColor::black, 0.5f);
	}
	int baseline = static_cast<int>(static_cast<float>(pixels.getHeight()) * 0.4f);
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = 0; y < pixels.getHeight(); y++) {
			ofColor fillColor0 = style._fillColor0;
			ofColor fillColor1 = style._fillColor1;
			ofColor fillColor2 = style._fillColor2;
			if (y < baseline) {
				float f = static_cast<float>(y) / static_cast<float>(baseline);
				pixels.setColor(x, y, fillColor0.lerp(fillColor1, f));
			} else if(y >= baseline) {
				int start = y - baseline;
				int end = pixels.getHeight() - baseline;
				float f = static_cast<float>(start) / static_cast<float>(end);
				pixels.setColor(x, y, fillColor1.lerp(fillColor2, f));
			}
		}
	}
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = 0; y < style._edgeSize; y++) {
			pixels.setColor(x, y, style._borderColor);
		}
	}
	for (int y = 0; y < pixels.getHeight(); y++) {
		for (int x = pixels.getWidth() - style._edgeSize; x < pixels.getWidth(); x++) {
			pixels.setColor(x, y, style._borderColor);
		}
	}
	for (int x = 0; x < style._edgeSize; x++) {
		for (int y = 0; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, style._borderColor);
		}
	}
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = pixels.getHeight() - style._edgeSize; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, style._borderColor);
		}
	}
}
InputFieldStyle::InputFieldStyle()
 : _edgeSize(2),
   _fillColor(ofColor::white),
   _borderShadowColor(ofColor::black),
   _borderLightColor(ofColor::white) {
}
InputFieldStyle & InputFieldStyle::edgeSize(int _edgeSize) {
	this->_edgeSize = _edgeSize;
	return *this;
}
InputFieldStyle & InputFieldStyle::fillColor(ofColor _fillColor) {
	this->_fillColor = _fillColor;
	return *this;
}
InputFieldStyle & InputFieldStyle::borderShadowColor(ofColor _borderShadowColor) {
	this->_borderShadowColor = _borderShadowColor;
	return *this;
}
InputFieldStyle & InputFieldStyle::borderLightColor(ofColor _borderLightColor) {
	this->_borderLightColor = _borderLightColor;
	return *this;
}
void writeInputFieldImage(ofPixels & pixels, InputFieldStyle style) {
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = 0; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, style._fillColor);
		}
	}
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = 0; y < style._edgeSize; y++) {
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int y = style._edgeSize; y < style._edgeSize*2; y++) {
			pixels.setColor(x, y, style._borderLightColor);
		}
		for (int y = pixels.getHeight() - (style._edgeSize * 2); y < pixels.getHeight() - style._edgeSize; y++) {
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int y = pixels.getHeight() - style._edgeSize; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, style._borderLightColor);
		}
	}
	for (int y = 0; y < pixels.getHeight(); y++) {
		for (int x = 0; x < style._edgeSize; x++) {
			if (y >= pixels.getHeight() - style._edgeSize * 2) {
				break;
			}
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int x = style._edgeSize; x < style._edgeSize*2; x++) {
			if (y < style._edgeSize) {
				break;
			}
			if (y >= pixels.getHeight() - style._edgeSize * 2) {
				break;
			}
			pixels.setColor(x, y, style._borderLightColor);
		}
		for (int x = pixels.getWidth() - (style._edgeSize * 2); x < pixels.getWidth() - style._edgeSize; x++) {
			if (y >= pixels.getHeight() - style._edgeSize) {
				break;
			}
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int x = pixels.getWidth() - style._edgeSize; x < pixels.getWidth(); x++) {
			pixels.setColor(x, y, style._borderLightColor);
		}
	}
}
}