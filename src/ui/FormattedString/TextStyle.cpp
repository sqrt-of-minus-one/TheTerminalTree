////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: TextStyle.cpp               //
////////////////////////////////////////

#include "TextStyle.h"

#include "../Escape.h"

#include <vector>

using namespace ui;

TextStyle TextStyle::operator~() const
{
	TextStyle result;
	if (text_colour)	result.text_colour	= DEFAULT.text_colour;
	if (back_colour)	result.back_colour	= DEFAULT.back_colour;
	if (blinking)		result.blinking		= DEFAULT.blinking;
	if (bold)			result.bold			= DEFAULT.bold;
	if (italic)			result.italic		= DEFAULT.italic;
	if (underline)		result.underline	= DEFAULT.underline;
	if (cross_out)		result.cross_out	= DEFAULT.cross_out;
	return result;
}

TextStyle TextStyle::operator+(const TextStyle& style) const
{
	TextStyle result = *this;
	return result += style;
}

TextStyle& TextStyle::operator+=(const TextStyle& style)
{
	if (style.text_colour)	text_colour	= style.text_colour;
	if (style.back_colour)	back_colour	= style.back_colour;
	if (style.blinking)		blinking	= style.blinking;
	if (style.bold)			bold		= style.bold;
	if (style.italic)		italic		= style.italic;
	if (style.underline)	underline	= style.underline;
	if (style.cross_out)	cross_out	= style.cross_out;
	return *this;
}

TextStyle TextStyle::operator-(const TextStyle& style) const
{
	TextStyle result = *this;
	return result -= style;
}

TextStyle& TextStyle::operator-=(const TextStyle& style)
{
	if (text_colour)	text_colour	= style.text_colour.value_or(*DEFAULT.text_colour);
	if (back_colour)	back_colour	= style.back_colour.value_or(*DEFAULT.back_colour);
	if (blinking)		blinking	= style.blinking.value_or(*DEFAULT.blinking);
	if (bold)			bold		= style.bold.value_or(*DEFAULT.bold);
	if (italic)			italic		= style.italic.value_or(*DEFAULT.italic);
	if (underline)		underline	= style.underline.value_or(*DEFAULT.underline);
	if (cross_out)		cross_out	= style.cross_out.value_or(*DEFAULT.cross_out);
	return *this;
}

TextStyle TextStyle::DEFAULT {
	.text_colour	= EColour::DEFAULT,
	.back_colour	= EColour::DEFAULT,
	.blinking		= EBlinking::OFF,
	.bold			= false,
	.italic			= false,
	.underline		= EUnderline::OFF,
	.cross_out		= false
};

std::ostream& ui::operator<<(std::ostream& stream, const TextStyle& style)
{
	std::vector<int> style_codes;
	if (style.text_colour)	style_codes.push_back(style::get_text_colour_code(*style.text_colour));
	if (style.back_colour)	style_codes.push_back(style::get_back_colour_code(*style.back_colour));
	if (style.blinking)		style_codes.push_back(style::get_blinking_code(*style.blinking));
	if (style.bold)			style_codes.push_back(*style.bold		? style::BOLD		: style::BOLD_OFF);
	if (style.italic)		style_codes.push_back(*style.italic		? style::ITALIC		: style::ITALIC_OFF);
	if (style.underline)	style_codes.push_back(style::get_underline_code(*style.underline));
	if (style.cross_out)	style_codes.push_back(*style.cross_out	? style::CROSS_OUT	: style::CROSS_OUT_OFF);
	if (!style_codes.empty())
	{
		stream << Escape::STYLE(std::move(style_codes));
	}
	return stream;
}
