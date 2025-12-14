////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: FormattedStringPiece.h      //
////////////////////////////////////////

#pragma once

//#include "FormattedString.h"

#include "TextStyle.h"

namespace ui
{

// A piece of the formatted string. The whole piece has the same style
class FormattedStringPiece
{
private:
	std::string string_;
	TextStyle style_;

public:
	FormattedStringPiece() = default;
	FormattedStringPiece(const FormattedStringPiece& piece) = default;
	FormattedStringPiece(FormattedStringPiece&& piece) = default;
	FormattedStringPiece(const std::string& string, const TextStyle& style);
	FormattedStringPiece(std::string&& string, const TextStyle& style);

	std::string& get_string();
	const std::string& get_string() const;
	void set_string(const std::string& string);
	void set_string(std::string&& string);
	TextStyle& get_style();
	const TextStyle& get_style() const;
	void set_style(const TextStyle& style);

	FormattedStringPiece& operator=(const FormattedStringPiece& style) = default;
	FormattedStringPiece& operator=(FormattedStringPiece&& style) = default;
	friend std::ostream& operator<<(std::ostream& stream, const FormattedStringPiece& piece);
};

std::ostream& operator<<(std::ostream& stream, const FormattedStringPiece& piece);

}
