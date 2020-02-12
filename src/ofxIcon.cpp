#include "ofxIcon.h"
#include <iostream>
#include <algorithm>

namespace ofxIcon {
namespace util {
void fillColor(ofPixels & pixels, ofColor color) {
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = 0; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, color);
		}
	}
}
void drawBorder(ofPixels & pixels, ofColor color, int edgeSize) {
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = 0; y < edgeSize; y++) {
			pixels.setColor(x, y, color);
		}
	}
	for (int y = 0; y < pixels.getHeight(); y++) {
		for (int x = pixels.getWidth() - edgeSize; x < pixels.getWidth(); x++) {
			pixels.setColor(x, y, color);
		}
	}
	for (int x = 0; x < edgeSize; x++) {
		for (int y = 0; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, color);
		}
	}
	for (int x = 0; x < pixels.getWidth(); x++) {
		for (int y = pixels.getHeight() - edgeSize; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, color);
		}
	}
}
void drawLine(ofPixels & pixels, ofColor color, glm::ivec2 start, glm::ivec2 end) {
	int dx = std::abs(end.x - start.x);
	int dy = std::abs(end.y - start.y);
	int sx, sy = 0;
	if (start.x < end.x)
		sx = 1;
	else
		sx = -1;
	if (start.y < end.y)
		sy = 1;
	else
		sy = -1;
	int err = dx - dy;
	int e2 = 0;
	while (true) {
		pixels.setColor(start.x, start.y, color);
		if (start.x == end.x && start.y == end.y) {
			break;
		}
		e2 = 2 * err;
		if (e2 > -dy) {
			err = err - dy;
			start.x = start.x + sx;
		}
		if (e2 < dx) {
			err = err + dx;
			start.y = start.y + sy;
		}
	}
}
}
//
// Button
//
ButtonStyle::ButtonStyle()
	: _edgeSize(2),
	  _press(false),
      _borderColor(ofColor::black),
	  _fillColor0(ofColor::cyan),
	  _fillColor1(ofColor::white),
	  _fillColor2(ofColor::cyan) {
}
ButtonStyle ButtonStyle::edgeSize(int _edgeSize) {
	auto c = *this;
	c._edgeSize = _edgeSize;
	return c;
}
ButtonStyle ButtonStyle::press(bool _press) {
	auto c = *this;
	c._press = _press;
	return c;
}
ButtonStyle ButtonStyle::borderColor(ofColor _borderColor) {
	auto c = *this;
	c._borderColor = _borderColor;
	return c;
}
ButtonStyle ButtonStyle::fillColor0(ofColor _fillColor0) {
	auto c = *this;
	c._fillColor0 = _fillColor0;
	return c;
}
ButtonStyle ButtonStyle::fillColor1(ofColor _fillColor1) {
	auto c = *this;
	c._fillColor1 = _fillColor1;
	return c;
}
ButtonStyle ButtonStyle::fillColor2(ofColor _fillColor2) {
	auto c = *this;
	c._fillColor2 = _fillColor2;
	return c;
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
	util::drawBorder(pixels, style._borderColor, style._edgeSize);
}
//
// InputField
//
InputFieldStyle::InputFieldStyle()
 : _edgeSize(2),
   _fillColor(ofColor::white),
   _borderShadowColor(ofColor::black),
   _borderLightColor(ofColor::white) {
}
InputFieldStyle InputFieldStyle::edgeSize(int _edgeSize) {
	auto c = *this;
	c._edgeSize = _edgeSize;
	return c;
}
InputFieldStyle InputFieldStyle::fillColor(ofColor _fillColor) {
	auto c = *this;
	c._fillColor = _fillColor;
	return c;
}
InputFieldStyle InputFieldStyle::borderShadowColor(ofColor _borderShadowColor) {
	auto c = *this;
	c._borderShadowColor = _borderShadowColor;
	return c;
}
InputFieldStyle InputFieldStyle::borderLightColor(ofColor _borderLightColor) {
	auto c = *this;
	c._borderLightColor = _borderLightColor;
	return c;
}
void writeInputFieldImage(ofPixels & pixels, InputFieldStyle style) {
	util::fillColor(pixels, style._fillColor);
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
//
// Dropdown
//
DropdownStyle::DropdownStyle() 
 :  _edgeSize(2),
	_minSlotWidth(0),
	_maxSlotWidth(50),
    _fillColor(ofColor::white),
    _borderColor(ofColor::black),
    _fillSlotColor0(ofColor::cyan),
    _fillSlotColor1(ofColor::white),
    _fillSlotColor2(ofColor::cyan),
	_triangleColor(ofColor::black) {
}
DropdownStyle DropdownStyle::edgeSize(int _edgeSize) {
	auto c = *this;
	c._edgeSize = _edgeSize;
	return c;
}
DropdownStyle DropdownStyle::fillColor(ofColor _fillColor) {
	auto c = *this;
	c._fillColor = _fillColor;
	return c;
}
DropdownStyle DropdownStyle::borderColor(ofColor _borderColor) {
	auto c = *this;
	c._borderColor = _borderColor;
	return c;
}
DropdownStyle DropdownStyle::fillSlotColor0(ofColor _fillSlotColor0) {
	auto c = *this;
	c._fillSlotColor0 = _fillSlotColor0;
	return c;
}
DropdownStyle DropdownStyle::fillSlotColor1(ofColor _fillSlotColor1) {
	auto c = *this;
	c._fillSlotColor1 = _fillSlotColor1;
	return c;
}
DropdownStyle DropdownStyle::fillSlotColor2(ofColor _fillSlotColor2) {
	auto c = *this;
	c._fillSlotColor2 = _fillSlotColor2;
	return c;
}

DropdownStyle DropdownStyle::triangleColor(ofColor _triangleColor) {
	auto c = *this;
	c._triangleColor = _triangleColor;
	return c;
}

DropdownStyle DropdownStyle::minSlotWidth(int _minSlotWidth) {
	auto c = *this;
	c._minSlotWidth = _minSlotWidth;
	return c;
}

DropdownStyle DropdownStyle::maxSlotWidth(int _maxSlotWidth) {
	auto c = *this;
	c._maxSlotWidth = _maxSlotWidth;
	return c;
}

int DropdownStyle::computeSlotWidth(int width) const {
	int s = width / 6;
	s = std::min(s, _maxSlotWidth);
	s = std::max(s, _minSlotWidth);
	return s;
}

void writeDropdownImage(ofPixels & pixels, DropdownStyle style) {
	util::fillColor(pixels, style._fillColor);
	int baseline = static_cast<int>(static_cast<float>(pixels.getHeight()) * 0.4f);
	int slotSizeX = style.computeSlotWidth(pixels.getWidth());
	int slotSizeY = pixels.getHeight();
	int slotPosX = pixels.getWidth() - slotSizeX;
	int slotPosY = 0;
	for (int x = slotPosX; x < pixels.getWidth(); x++) {
		for (int y = 0; y < pixels.getHeight(); y++) {
			ofColor fillColor0 = style._fillSlotColor0;
			ofColor fillColor1 = style._fillSlotColor1;
			ofColor fillColor2 = style._fillSlotColor2;
			if (y < baseline) {
				float f = static_cast<float>(y) / static_cast<float>(baseline);
				pixels.setColor(x, y, fillColor0.lerp(fillColor1, f));
			}
			else if (y >= baseline) {
				int start = y - baseline;
				int end = pixels.getHeight() - baseline;
				float f = static_cast<float>(start) / static_cast<float>(end);
				pixels.setColor(x, y, fillColor1.lerp(fillColor2, f));
			}
		}
	}
	int triaW = slotSizeX / 2;
	int triaH = slotSizeY / 2;
	int spaceW = (slotSizeX - triaW) / 2;
	int spaceH = (slotSizeY - triaH) / 2;
	for (int y = spaceH; y < spaceH + triaH; y++) {
		float f = static_cast<float>((y - spaceH)) / static_cast<float>(triaH);
		f = 1.0f - f;
		int fixedTriaW = static_cast<int>(static_cast<float>(triaW) * f);
		int marginTriaW = (triaW - fixedTriaW) / 2;

		for (int x = slotPosX + spaceW; x < slotPosX + spaceW + fixedTriaW; x++) {
			pixels.setColor(marginTriaW + x, y, style._triangleColor);
		}
	}
	util::drawBorder(pixels, style._borderColor, style._edgeSize);
	for (int x = slotPosX; x < slotPosX + style._edgeSize; x++) {
		for (int y = 0; y < pixels.getHeight(); y++) {
			pixels.setColor(x, y, style._borderColor);
		}
	}
}
//
// CheckBox
//
CheckBoxStyle::CheckBoxStyle() 
 : _edgeSize(2),
   _selected(false),
   _lineColor(ofColor::black),
	_borderColor(ofColor::black),
	_fillColor0(ofColor::cyan),
	_fillColor1(ofColor::white),
	_fillColor2(ofColor::cyan) {
}
CheckBoxStyle CheckBoxStyle::edgeSize(int _edgeSize) {
	auto c = *this;
	c._edgeSize = _edgeSize;
	return c;
}
CheckBoxStyle CheckBoxStyle::selected(bool _selected) {
	auto c = *this;
	c._selected = _selected;
	return c;
}
CheckBoxStyle CheckBoxStyle::lineColor(ofColor _lineColor) {
	auto c = *this;
	c._lineColor = _lineColor;
	return c;
}
CheckBoxStyle CheckBoxStyle::fillColor0(ofColor _fillColor0) {
	auto c = *this;
	c._fillColor0 = _fillColor0;
	return c;
}
CheckBoxStyle CheckBoxStyle::fillColor1(ofColor _fillColor1) {
	auto c = *this;
	c._fillColor1 = _fillColor1;
	return c;
}
CheckBoxStyle CheckBoxStyle::fillColor2(ofColor _fillColor2) {
	auto c = *this;
	c._fillColor2 = _fillColor2;
	return c;
}
void writeCheckBoxImage(ofPixels & pixels, CheckBoxStyle style) {
	writeButtonImage(pixels, ofxIcon::ButtonStyle()
		.edgeSize(style._edgeSize)
		.borderColor(style._borderColor)
		.fillColor0(style._fillColor0)
		.fillColor1(style._fillColor1)
		.fillColor2(style._fillColor2));
	if (style._selected) {
		glm::ivec2 p0(
			(pixels.getWidth() / 2) - pixels.getWidth() / 4,pixels.getHeight() / 2
		);
		glm::ivec2 p1(
			(pixels.getWidth() / 2) - pixels.getWidth() / 4, (pixels.getHeight() / 2) + pixels.getHeight() / 4
		);
		glm::ivec2 p2(
			(pixels.getWidth() / 2) + pixels.getWidth() / 4, (pixels.getHeight() / 2) - pixels.getHeight() / 4
		);
		util::drawLine(pixels, style._lineColor, p0, p1);
		util::drawLine(pixels, style._lineColor, p0 + glm::ivec2(1,0), p1 + glm::ivec2(1, 0));
		util::drawLine(pixels, style._lineColor, p1, p2);
		util::drawLine(pixels, style._lineColor, p1 + glm::ivec2(1, 0), p2 + glm::ivec2(1, 0));
	}
}
//
// RadioButton
//
RadioButtonStyle::RadioButtonStyle()
 :  _edgeSize(2),
    _selected(false),
    _checkColor(ofColor::black),
    _borderColor(ofColor::black),
    _fillColor0(ofColor::cyan),
    _fillColor1(ofColor::white),
    _fillColor2(ofColor::cyan) {
}
RadioButtonStyle RadioButtonStyle::edgeSize(int _edgeSize) {
	auto c = *this;
	c._edgeSize = _edgeSize;
	return c;
}
RadioButtonStyle RadioButtonStyle::selected(bool _selected) {
	auto c = *this;
	c._selected = _selected;
	return c;
}
RadioButtonStyle RadioButtonStyle::checkColor(ofColor _checkColor) {
	auto c = *this;
	c._checkColor = _checkColor;
	return c;
}
RadioButtonStyle RadioButtonStyle::borderColor(ofColor _borderColor) {
	auto c = *this;
	c._borderColor = _borderColor;
	return c;
}
RadioButtonStyle RadioButtonStyle::fillColor0(ofColor _fillColor0) {
	auto c = *this;
	c._fillColor0 = _fillColor0;
	return c;
}
RadioButtonStyle RadioButtonStyle::fillColor1(ofColor _fillColor1) {
	auto c = *this;
	c._fillColor1 = _fillColor1;
	return c;
}
RadioButtonStyle RadioButtonStyle::fillColor2(ofColor _fillColor2) {
	auto c = *this;
	c._fillColor2 = _fillColor2;
	return c;
}
void writeRadioButtonImage(ofPixels & pixels, RadioButtonStyle style) {
	int radiusX = pixels.getWidth() / 2;
	int radiusY = pixels.getHeight() / 2;
	int centerX = radiusX;
	int centerY = radiusY;
	int baseline = static_cast<int>(static_cast<float>(pixels.getHeight()) * 0.4f);
	util::fillColor(pixels, ofColor(0, 0, 0, 0));
	for (int i = 0; i < 360; i++) {
		float f = static_cast<float>(i);
		f = f * (3.14f / 180.0f);
		for (int e = 0; e < style._edgeSize; e++) {
			float fx = (std::cos(f) * static_cast<float>(radiusX - e)) + centerX;
			float fy = (std::sin(f) * static_cast<float>(radiusY - e)) + centerY;
			int ix = static_cast<int>(fx);
			int iy = static_cast<int>(fy);
			pixels.setColor(ix, iy, style._borderColor);
		}
		float innerfx = std::cos(f) * static_cast<float>(radiusX - style._edgeSize);
		float innerfy = std::sin(f) * static_cast<float>(radiusY - style._edgeSize)+ centerY;
		int innerix = static_cast<int>(innerfx);
		int inneriy = static_cast<int>(innerfy);
		int startX = std::max(0, centerX - innerix);
		int endX = std::min(centerX + innerix, static_cast<int>(pixels.getWidth())-1);
		for (int x = startX; x < endX; x++) {
			pixels.setColor(x, inneriy, ofColor::white);
			int y = inneriy;
			ofColor fillColor0 = style._fillColor0;
			ofColor fillColor1 = style._fillColor1;
			ofColor fillColor2 = style._fillColor2;
			if (y < baseline) {
				float f = static_cast<float>(y) / static_cast<float>(baseline);
				pixels.setColor(x, y, fillColor0.lerp(fillColor1, f));
			} else if (y >= baseline) {
				int start = y - baseline;
				int end = pixels.getHeight() - baseline;
				float f = static_cast<float>(start) / static_cast<float>(end);
				pixels.setColor(x, y, fillColor1.lerp(fillColor2, f));
			}
		}
	}
	if (!style._selected) {
		return;
	}
	int circleSize = ((pixels.getWidth() + pixels.getHeight()) / 2) / 3;
	for (int i = 0; i < 360; i++) {
		float f = static_cast<float>(i);
		f = f * (3.14f / 180.0f);
		for (int e = 0; e <circleSize; e++) {
			float fx = (std::cos(f) * static_cast<float>(e)) + centerX;
			float fy = (std::sin(f) * static_cast<float>(e)) + centerY;
			int ix = static_cast<int>(fx);
			int iy = static_cast<int>(fy);
			pixels.setColor(ix, iy, style._checkColor);
		}
	}
}
}
