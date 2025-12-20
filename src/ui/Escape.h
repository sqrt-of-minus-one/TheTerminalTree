////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Escape.h                    //
////////////////////////////////////////

#pragma once

#include <ostream>
#include <vector>

namespace ui
{

// A more convenient way to use ANSI commands
// E.g. if you want to move the cursor back five characters, you can use:
//		std::cout << ui::Escape::BACK(5);
// which is the equivalent of
//		std::cout << "\e[5D";
class Escape
{
private:
	// The command itself
	class EscapeCommand_
	{
	private:
		// Consists of the command character and the parameters:
		// '\e' + '[' + par1 + ';' + par2 + … + parN + char
		char command_;
		std::vector<int> values_;

	public:
		EscapeCommand_(char command);
		EscapeCommand_(char command, int value);
		EscapeCommand_(char command, std::initializer_list<int> values);
		EscapeCommand_(char command, const std::vector<int>& values);
		EscapeCommand_(char command, std::vector<int>&& values);
		friend std::ostream& operator<<(std::ostream& stream, const EscapeCommand_& escape);
	};

	char command_;

public:
	template<typename... Args>
	EscapeCommand_ operator()(Args... args) const;
	EscapeCommand_ operator()(const std::vector<int>& values) const;
	EscapeCommand_ operator()(std::vector<int>&& values) const;
	friend std::ostream& operator<<(std::ostream& stream, const EscapeCommand_& escape);

	static constexpr std::string_view CSI = "\033[";

	static const Escape UP;                      // Moves the cursor up
	static const Escape DOWN;                    // Moves the cursor down
	static const Escape FORWARD;                 // Moves the cursor forward
	static const Escape BACK;                    // Moves the cursor back
	static const Escape NEXT_LINE;               // Moves the cursor to the next line
	static const Escape PREVIOUS_LINE;           // Moves the cursor to the previous line
	static const Escape STYLE;                   // Applies the style like colour or underline (see the TextStyle class)
	static const Escape SAVE_CURSOR_POSITION;    // Saves the current cursor position
	static const Escape RESTORE_CURSOR_POSITION; // Restores the saved cursor position
	static const Escape ERASE;                   // Erases part of the terminal depending on the argument:
	                                             //  0 (or missing): from the cursor to the end of the screen;
	                                             //  1: from the cursor to the beginning of the screen;
	                                             //  2: the entire screen;

private:
	Escape(char command);

};

std::ostream& operator<<(std::ostream& stream, const Escape::EscapeCommand_& escape);
std::ostream& operator<<(std::ostream& stream, const Escape& escape);

}

#include "Escape.tpp"
