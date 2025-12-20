////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Escape.cpp                  //
////////////////////////////////////////

#include "Escape.h"

using namespace ui;

Escape::EscapeCommand_::EscapeCommand_(char command) :
	command_(command),
	values_()
{}

Escape::EscapeCommand_::EscapeCommand_(char command, int value) :
	command_(command),
	values_({ value })
{}

Escape::EscapeCommand_::EscapeCommand_(char command, std::initializer_list<int> values) :
	command_(command),
	values_(values)
{}

Escape::EscapeCommand_::EscapeCommand_(char command, const std::vector<int>& values) :
	command_(command),
	values_(values)
{}

Escape::EscapeCommand_::EscapeCommand_(char command, std::vector<int>&& values) :
	command_(command),
	values_(std::move(values))
{}

Escape::EscapeCommand_ Escape::operator()(const std::vector<int>& values) const
{
	return Escape::EscapeCommand_(command_, values);
}

Escape::EscapeCommand_ Escape::operator()(std::vector<int>&& values) const
{
	return Escape::EscapeCommand_(command_, std::forward<std::vector<int>>(values));
}

std::ostream& ui::operator<<(std::ostream& stream, const Escape::EscapeCommand_& escape)
{
	stream << Escape::CSI; // The escape sequence begins
	if (!escape.values_.empty()) // The parameters if there are any
	{
		stream << escape.values_[0];
		for (int i = 1; i < escape.values_.size(); i++)
		{
			stream << ';' << escape.values_[i];
		}
	}
	return stream << escape.command_; // The command
}

std::ostream& ui::operator<<(std::ostream& stream, const Escape& escape)
{
	return stream << escape();
}

Escape::Escape(char command) :
	command_(command)
{}

const Escape Escape::UP('A');
const Escape Escape::DOWN('B');
const Escape Escape::FORWARD('C');
const Escape Escape::BACK('D');
const Escape Escape::NEXT_LINE('E');
const Escape Escape::PREVIOUS_LINE('F');
const Escape Escape::STYLE('m');
const Escape Escape::SAVE_CURSOR_POSITION('s');
const Escape Escape::RESTORE_CURSOR_POSITION('u');
const Escape Escape::ERASE('J');
