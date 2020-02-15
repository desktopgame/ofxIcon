#include "ofxIcon.h"
#include <iostream>
#include <algorithm>

namespace ofxIcon {
namespace util {
void fillColor(ofPixels & pixels, ofColor color) {
	for (int x = 0; x < static_cast<int>(pixels.getWidth()); x++) {
		for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
			pixels.setColor(x, y, color);
		}
	}
}

void fillGrad(ofPixels & pixels, ofColor fillColor0, ofColor fillColor1, ofColor fillColor2) {
	int baseline = static_cast<int>(static_cast<float>(static_cast<int>(pixels.getHeight())) * 0.4f);
	for (int x = 0; x < static_cast<int>(pixels.getWidth()); x++) {
		for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
			ofColor fc0 = fillColor0;
			ofColor fc1 = fillColor1;
			ofColor fc2 = fillColor2;
			if (y < baseline) {
				float f = static_cast<float>(y) / static_cast<float>(baseline);
				pixels.setColor(x, y, fc0.lerp(fc1, f));
			}
			else if (y >= baseline) {
				int start = y - baseline;
				int end = static_cast<int>(pixels.getHeight()) - baseline;
				float f = static_cast<float>(start) / static_cast<float>(end);
				pixels.setColor(x, y, fc1.lerp(fc2, f));
			}
		}
	}
}

void drawBorder(ofPixels & pixels, ofColor color, int edgeSize) {
	for (int x = 0; x < static_cast<int>(pixels.getWidth()); x++) {
		for (int y = 0; y < edgeSize; y++) {
			pixels.setColor(x, y, color);
		}
	}
	for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
		for (int x = static_cast<int>(pixels.getWidth()) - edgeSize; x < static_cast<int>(pixels.getWidth()); x++) {
			pixels.setColor(x, y, color);
		}
	}
	for (int x = 0; x < edgeSize; x++) {
		for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
			pixels.setColor(x, y, color);
		}
	}
	for (int x = 0; x < static_cast<int>(pixels.getWidth()); x++) {
		for (int y = static_cast<int>(pixels.getHeight()) - edgeSize; y < static_cast<int>(pixels.getHeight()); y++) {
			pixels.setColor(x, y, color);
		}
	}
}
void drawLine(ofPixels & pixels, ofColor color, glm::ivec2 start, glm::ivec2 end) {
	auto points = linePoints(start, end);
	for (auto& point : points) {
		pixels.setColor(point.x, point.y, color);
	}
}
std::vector<glm::ivec2> linePoints(glm::ivec2 start, glm::ivec2 end) {
	std::vector<glm::ivec2> v;
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
		v.emplace_back(start);
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
	return v;
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
	util::fillGrad(pixels, style._fillColor0, style._fillColor1, style._fillColor2);
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
	for (int x = 0; x < static_cast<int>(pixels.getWidth()); x++) {
		for (int y = 0; y < style._edgeSize; y++) {
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int y = style._edgeSize; y < style._edgeSize*2; y++) {
			pixels.setColor(x, y, style._borderLightColor);
		}
		for (int y = static_cast<int>(pixels.getHeight()) - (style._edgeSize * 2); y < static_cast<int>(pixels.getHeight()) - style._edgeSize; y++) {
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int y = static_cast<int>(pixels.getHeight()) - style._edgeSize; y < static_cast<int>(pixels.getHeight()); y++) {
			pixels.setColor(x, y, style._borderLightColor);
		}
	}
	for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
		for (int x = 0; x < style._edgeSize; x++) {
			if (y >= static_cast<int>(pixels.getHeight()) - style._edgeSize * 2) {
				break;
			}
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int x = style._edgeSize; x < style._edgeSize*2; x++) {
			if (y < style._edgeSize) {
				break;
			}
			if (y >= static_cast<int>(pixels.getHeight()) - style._edgeSize * 2) {
				break;
			}
			pixels.setColor(x, y, style._borderLightColor);
		}
		for (int x = static_cast<int>(pixels.getWidth()) - (style._edgeSize * 2); x < static_cast<int>(pixels.getWidth()) - style._edgeSize; x++) {
			if (y >= static_cast<int>(pixels.getHeight()) - style._edgeSize) {
				break;
			}
			pixels.setColor(x, y, style._borderShadowColor);
		}
		for (int x = static_cast<int>(pixels.getWidth()) - style._edgeSize; x < static_cast<int>(pixels.getWidth()); x++) {
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
	int baseline = static_cast<int>(static_cast<float>(static_cast<int>(pixels.getHeight())) * 0.4f);
	int slotSizeX = style.computeSlotWidth(static_cast<int>(pixels.getWidth()));
	int slotSizeY = static_cast<int>(pixels.getHeight());
	int slotPosX = static_cast<int>(pixels.getWidth()) - slotSizeX;
	int slotPosY = 0;
	for (int x = slotPosX; x < static_cast<int>(pixels.getWidth()); x++) {
		for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
			ofColor fillColor0 = style._fillSlotColor0;
			ofColor fillColor1 = style._fillSlotColor1;
			ofColor fillColor2 = style._fillSlotColor2;
			if (y < baseline) {
				float f = static_cast<float>(y) / static_cast<float>(baseline);
				pixels.setColor(x, y, fillColor0.lerp(fillColor1, f));
			}
			else if (y >= baseline) {
				int start = y - baseline;
				int end = static_cast<int>(pixels.getHeight()) - baseline;
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
		for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
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
			(static_cast<int>(pixels.getWidth()) / 2) - static_cast<int>(pixels.getWidth()) / 4,static_cast<int>(pixels.getHeight()) / 2
		);
		glm::ivec2 p1(
			(static_cast<int>(pixels.getWidth()) / 2) - static_cast<int>(pixels.getWidth()) / 4, (static_cast<int>(pixels.getHeight()) / 2) + static_cast<int>(pixels.getHeight()) / 4
		);
		glm::ivec2 p2(
			(static_cast<int>(pixels.getWidth()) / 2) + static_cast<int>(pixels.getWidth()) / 4, (static_cast<int>(pixels.getHeight()) / 2) - static_cast<int>(pixels.getHeight()) / 4
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
	int radiusX = static_cast<int>(pixels.getWidth()) / 2;
	int radiusY = static_cast<int>(pixels.getHeight()) / 2;
	int centerX = radiusX;
	int centerY = radiusY;
	int baseline = static_cast<int>(static_cast<float>(static_cast<int>(pixels.getHeight())) * 0.4f);
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
		int endX = std::min(centerX + innerix, static_cast<int>(static_cast<int>(pixels.getWidth()))-1);
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
				int end = static_cast<int>(pixels.getHeight()) - baseline;
				float f = static_cast<float>(start) / static_cast<float>(end);
				pixels.setColor(x, y, fillColor1.lerp(fillColor2, f));
			}
		}
	}
	if (!style._selected) {
		return;
	}
	int circleSize = ((static_cast<int>(pixels.getWidth()) + static_cast<int>(pixels.getHeight())) / 2) / 3;
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
//
// Slider
//
SliderStyle::SliderStyle()
 : _edgeSize(2),
   _borderColor(ofColor::black),
   _fillColor0(ofColor::cyan),
   _fillColor1(ofColor::white),
   _fillColor2(ofColor::cyan) {
}
SliderStyle SliderStyle::edgeSize(int _edgeSize) {
	auto c = *this;
	c._edgeSize = _edgeSize;
	return c;
}
SliderStyle SliderStyle::borderColor(ofColor _borderColor) {
	auto c = *this;
	c._borderColor = _borderColor;
	return c;
}
SliderStyle SliderStyle::fillColor0(ofColor _fillColor0) {
	auto c = *this;
	c._fillColor0 = _fillColor0;
	return c;
}
SliderStyle SliderStyle::fillColor1(ofColor _fillColor1) {
	auto c = *this;
	c._fillColor1 = _fillColor1;
	return c;
}
SliderStyle SliderStyle::fillColor2(ofColor _fillColor2) {
	auto c = *this;
	c._fillColor2 = _fillColor2;
	return c;
}
void writeSliderImage(ofPixels & pixels, SliderStyle style) {
	util::fillGrad(pixels, style._fillColor0, style._fillColor1, style._fillColor2);
	util::drawBorder(pixels, style._borderColor, style._edgeSize);
}
//
// SliderKnob
//
SliderKnobStyle::SliderKnobStyle()
	: _edgeSize(2),
	_borderColor(ofColor::black),
	_fillColor0(ofColor::cyan),
	_fillColor1(ofColor::white),
	_fillColor2(ofColor::cyan) {
}
SliderKnobStyle SliderKnobStyle::edgeSize(int _edgeSize) {
	auto c = *this;
	c._edgeSize = _edgeSize;
	return c;
}
SliderKnobStyle SliderKnobStyle::borderColor(ofColor _borderColor) {
	auto c = *this;
	c._borderColor = _borderColor;
	return c;
}
SliderKnobStyle SliderKnobStyle::fillColor0(ofColor _fillColor0) {
	auto c = *this;
	c._fillColor0 = _fillColor0;
	return c;
}
SliderKnobStyle SliderKnobStyle::fillColor1(ofColor _fillColor1) {
	auto c = *this;
	c._fillColor1 = _fillColor1;
	return c;
}
SliderKnobStyle SliderKnobStyle::fillColor2(ofColor _fillColor2) {
	auto c = *this;
	c._fillColor2 = _fillColor2;
	return c;
}
void writeSliderKnobImage(ofPixels & pixels, SliderKnobStyle style) {
	util::fillColor(pixels, ofColor(0, 0, 0, 0));
	int hw = static_cast<int>(pixels.getWidth()) / 2;
	int hh = static_cast<int>(pixels.getHeight()) / 2;
	for (int i = 0; i < style._edgeSize; i++) {
		util::drawLine(pixels,
			style._borderColor,
			glm::ivec2(0, i),
			glm::ivec2(static_cast<int>(pixels.getWidth()), i)
		);
		util::drawLine(pixels,
			style._borderColor,
			glm::ivec2(i, 0),
			glm::ivec2(i, hh)
		);
		util::drawLine(pixels,
			style._borderColor,
			glm::ivec2(static_cast<int>(pixels.getWidth())-(i+1), 0),
			glm::ivec2(static_cast<int>(pixels.getWidth())-(i+1), hh)
		);
		util::drawLine(pixels,
			style._borderColor,
			glm::ivec2(i, hh),
			glm::ivec2(hw- (style._edgeSize - i), static_cast<int>(pixels.getHeight()))
		);
		util::drawLine(pixels,
			style._borderColor,
			glm::ivec2(static_cast<int>(pixels.getWidth()) - (i + 1), hh),
			glm::ivec2(hw+(style._edgeSize-i), static_cast<int>(pixels.getHeight()))
		);
		util::drawLine(pixels,
			style._borderColor,
			glm::ivec2(hw - (style._edgeSize), static_cast<int>(pixels.getHeight()) - (i+1)),
			glm::ivec2(hw + (style._edgeSize), static_cast<int>(pixels.getHeight()) - (i+1))
		);
	}
	int baseline = static_cast<int>(static_cast<float>(static_cast<int>(pixels.getHeight())) * 0.4f);
	for (int y = 0; y < static_cast<int>(pixels.getHeight()); y++) {
		if (y < style._edgeSize) {
			continue;
		}
		int startX = 0; bool findStartX = false;
		int endX = 0;   bool findEndX = false;
		// ŠJŽn, I—¹‚ðŽæ“¾‚·‚é
		for (int x = 0; x < static_cast<int>(pixels.getWidth()); x++) {
			ofColor c = pixels.getColor(x, y);
			if (!findStartX && c == style._borderColor) {
				findStartX = true;
			}
			if (findStartX && c != style._borderColor) {
				startX = x;
				break;
			}
		}
		for (int x = static_cast<int>(pixels.getWidth())-1; x >=0; x--) {
			ofColor c = pixels.getColor(x, y);
			if (!findEndX && c == style._borderColor) {
				findEndX = true;
			}
			if (findEndX && c != style._borderColor) {
				endX = x;
				break;
			}
		}
		for (int x = startX; x <= endX; x++) {
			ofColor fc0 = style._fillColor0;
			ofColor fc1 = style._fillColor1;
			ofColor fc2 = style._fillColor2;
			if (y < baseline) {
				float f = static_cast<float>(y) / static_cast<float>(baseline);
				pixels.setColor(x, y, fc0.lerp(fc1, f));
			}
			else if (y >= baseline) {
				int start = y - baseline;
				int end = static_cast<int>(pixels.getHeight()) - baseline;
				float f = static_cast<float>(start) / static_cast<float>(end);
				pixels.setColor(x, y, fc1.lerp(fc2, f));
			}
		}
	}
}
}
