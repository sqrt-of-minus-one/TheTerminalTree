////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: FormattedString.h           //
////////////////////////////////////////

#pragma once

#include "FormattedStringPiece.h"

#include <list>
#include <ostream>

namespace ui
{

class FormattedStringPiece;

// Allows to apply a formatting to strings (like colours, underline etc.)
// The $ characters are used to set formatting, e.g. in the string
//		ui::FormattedString fs = "This is a $bold(formatted$) string with $text:red(red text$)"
// "formatted" is bold, "red text" is red. Here is the list of supported features:
//	- $text:<colour> or $t:<colour> sets the text colour to <colour>; if no <colour> is provided, the default colour is applied;
//	- $background:<colour> or $back:<colour> sets the background colour to <colour>; if no <colour> is provided, the default colour is applied;
//	- $blinking:<type> or $blink:<type> makes the text blink; <type> can be either "slow" or "rapid"; if no <type> is provided, the "slow" is applied;
//	- $bold or $b makes the text bold;
//	- $italic, $it or $i makes the text italic;
//	- $underline:<type> or $u:<type> makes the underlined text; <type> can be either "single" or "double"; if no <type> is provided, the "single" is applied;
//	- $cross_out, $cross or $c crosses the text out
//	- $$ is used to make a single dollar sign $.
// The example of the formatted string:
//		ui::FormattedString fs = "This string contains $b(bold$), $i(italic$) and $t:green(green-coloured$) text. "
//			"It also has parts that are $b$i(both bold and italic$), and $b($i(italic$) inside bold$)";

// Note that FormattedString does not work properly with input/output manipulators (iomanip), use print_aline_<...>() instead
class FormattedString
{
private:
	// A formatted string consists of several pieces, each of them has its own formatting
	std::list<FormattedStringPiece> pieces_;

public:
	FormattedString() = default;
	FormattedString(const FormattedString& string) = default;
	FormattedString(FormattedString&& string) = default;
	FormattedString(const std::string& string);
	FormattedString(const char* string);
	std::list<FormattedStringPiece>& get_pieces();
	const std::list<FormattedStringPiece>& get_pieces() const;
	bool is_empty() const;
	std::string to_plain_string() const;
	int length() const;

	// Can be used instead of std::setw (which doesn't work properly)
	void print_align_left(std::ostream& stream, int width, char fill = ' ') const;
	void print_align_right(std::ostream& stream, int width, char fill = ' ') const;

	FormattedString& operator=(const FormattedString& string) = default;
	FormattedString& operator=(FormattedString&& string) = default;
	FormattedString& operator=(const std::string& string);
	FormattedString operator+(const FormattedString& string) const;
	FormattedString operator+(FormattedString&& string) const;
	FormattedString& operator+=(const FormattedString& string);
	FormattedString& operator+=(FormattedString&& string);
	friend std::ostream& operator<<(std::ostream& stream, const FormattedString& string);

private:
	void construct_(const std::string& string);
};

std::ostream& operator<<(std::ostream& stream, const FormattedString& string);

}

namespace ui_literals
{

// Allows to quickly create a formatted string using literal: "This is a $b(formatted$) string"_f
ui::FormattedString operator""_f(const char* string, size_t size);

}
