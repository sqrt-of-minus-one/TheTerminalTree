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

template<typename T_Key, typename T_Val>
const T_Val& at_or_first(const std::map<T_Key, T_Val>& map, T_Key key)
{
	auto it = map.find(key);
	return it == map.end() ? map.begin()->second : it->second;
}

}
