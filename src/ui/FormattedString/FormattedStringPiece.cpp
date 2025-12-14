////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: FormattedStringPiece.cpp    //
////////////////////////////////////////

#include "FormattedStringPiece.h"

#include "../Escape.h"

using namespace ui;

FormattedStringPiece::FormattedStringPiece(const std::string& string, const TextStyle& style) :
	string_(string),
	style_(style)
{}

FormattedStringPiece::FormattedStringPiece(std::string&& string, const TextStyle& style) :
	string_(std::move(string)),
	style_(style)
{}

std::string& FormattedStringPiece::get_string()
{
	return string_;
}

const std::string& FormattedStringPiece::get_string() const
{
	return string_;
}

void FormattedStringPiece::set_string(const std::string& string)
{
	string_ = string;
}

void FormattedStringPiece::set_string(std::string&& string)
{
	string_ = std::move(string);
}

TextStyle& FormattedStringPiece::get_style()
{
	return style_;
}

const TextStyle& FormattedStringPiece::get_style() const
{
	return style_;
}

void FormattedStringPiece::set_style(const TextStyle& style)
{
	style_ = style;
}

std::ostream& ui::operator<<(std::ostream& stream, const FormattedStringPiece& piece)
{
	return stream << piece.style_ << piece.string_;
}
