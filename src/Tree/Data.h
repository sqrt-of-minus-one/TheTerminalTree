////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Data.h                      //
////////////////////////////////////////

#pragma once

#include "../ui/ui.h"

#include <map>

namespace ui
{
class FormattedString;
}

namespace the_tree
{

extern const std::map<int, std::vector<ui::FormattedString>> TREES;

}
