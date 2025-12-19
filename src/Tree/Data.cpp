////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Data.cpp                    //
////////////////////////////////////////

#include "Data.h"

using namespace the_tree;
using namespace ui_literals;

const std::map<int, std::vector<ui::FormattedString>> the_tree::TREES = {
	{ 0,
		{
"\n$t:white(  *       *   * *  \n"
"  $t:yellow(The Tree hasn't$)  \n"
"    $t:yellow(grown yet$)      \n"
" *       *    *    \n"
"    *    *      *  \n"
"  *         *      \n"
"       *      *   *\n"
"   *     *       * \n"
"*   *         *    \n"
"  *     $t:bright_green(_V_$)            \n"
"_________$t:bright_green(|$)_________$)\n\n"_f,

"\n$t:white(    *        *     \n"
"  $t:yellow(The Tree hasn't$)  \n"
"  * $t:yellow(grown yet$)    * \n"
"      *    *       \n"
" *       *    *    \n"
"    *    *      *  \n"
"  *         *      \n"
"       *      *   *\n"
"   *     *       * \n"
"     *  $t:bright_green(_V_$)      *     \n"
"_________$t:bright_green(|$)_________$)\n\n"_f }
	},

	{ 1,
		{
"\n$t:white(      *    *       \n"
" *       *    *    \n"
"    *    *      *  \n"
"  *         *      \n"
"       *      *   *\n"
"   *     *       * \n"
"*   *         *    \n"
" *       $t:bright_green(/\\$)  *      \n"
"     *  $t:bright_green(/  \\$)  *        \n"
"  *    $t:bright_green(/____\\$)          \n"
"_________$t:red(||$)________$)\n\n"_f,

"\n$t:white( *       *        *\n"
"      *    *       \n"
" *       *    *    \n"
"    *    *      *  \n"
"  *         *      \n"
"       *      *   *\n"
"   *     *       * \n"
"*   *    $t:bright_green(/\\$)    *   \n"
" *      $t:bright_green(/  \\$) *      \n"
"     * $t:bright_green(/____\\$)   *           \n"
"_________$t:red(||$)________$)\n\n"_f }
	},

	{ 2,
		{
"\n$t:white(    *    *      *  \n"
"  *         *      \n"
"       *      *   *\n"
"   *     *       * \n"
"*   *         *    \n"
" *       $t:bright_yellow(*$)  *      \n"
"     *  $t:bright_green(/$t:bright_cyan(.$)\\$)   *        \n"
"  *    $t:bright_green(/_ _\\$)           \n"
"    *  $t:bright_green(/  $t:bright_blue(*$)\\$)  *       \n"
"      $t:bright_green(/__$t:bright_red(#$)__\\$)     *   \n"
"________$t:red(|_|$)________$)\n\n"_f,

"\n$t:white(    *          *   \n"
"    *    *      *  \n"
"  *         *      \n"
"       *      *   *\n"
"   *     *       * \n"
"*   *    $t:bright_yellow(*$)    *   \n"
" *      $t:bright_green(/$t:bright_magenta(.$)\\$) *      \n"
"     * $t:bright_green(/_ _\\$)   *           \n"
"  *    $t:bright_green(/  $t:bright_red(*$)\\$)         \n"
"    * $t:bright_green(/__$t:bright_cyan(#$)__\\$) *     \n"
"________$t:red(|_|$)________$)\n\n"_f }
	},
	
	{ 3,
		{
"\n$t:white(       *      *   *\n"
"   *     *       * \n"
"*   *         *    \n"
" *       $t:bright_yellow(*$)  *      \n"
"     *  $t:bright_green(/$t:bright_cyan(,$)\\$)   *        \n"
"  *    $t:bright_green(/_ _\\$)           \n"
"    *  $t:bright_green(/  $t:bright_blue(#$)\\$)  *       \n"
"      $t:bright_green(/_$t:bright_red(o$)  _\\$)     *   \n"
"*     $t:bright_green(/  $t:yellow(0$)  \\$)       \n"
"  *  $t:bright_green(/___ ___\\$) *      \n"
"________$t:red(|_|$)________$)\n\n"_f,

"\n$t:white( *       *         \n"
"       *      *   *\n"
"   *     *       * \n"
"*   *    $t:bright_yellow(*$)    *   \n"
" *      $t:bright_green(/$t:bright_magenta(,$)\\$) *      \n"
"     * $t:bright_green(/_ _\\$)   *           \n"
"  *    $t:bright_green(/  $t:bright_red(#$)\\$)         \n"
"    * $t:bright_green(/_$t:bright_cyan(o$)  _\\$) *     \n"
"      $t:bright_green(/  $t:magenta(0$)  \\$)     *   \n"
"*    $t:bright_green(/___ ___\\$)         \n"
"________$t:red(|_|$)________$)\n\n"_f }
	},
	
	{ 4, {
"\n$t:white(*   *         *    \n"
" *       $t:bright_yellow(*$)  *      \n"
"     *  $t:bright_green(/$t:bright_cyan(,$)\\$)   *        \n"
"  *    $t:bright_green(/_ _\\$)           \n"
"    *  $t:bright_green(/  $t:bright_blue(%$)\\$)  *       \n"
"      $t:bright_green(/_$t:bright_red(o$)  _\\$)     *   \n"
"*     $t:bright_green(/  $t:yellow(0$)  \\$)       \n"
"  *  $t:bright_green(/_    $t:bright_cyan(*$)_\\$) *      \n"
"     $t:bright_green(/ $t:red(x$)  $t:bright_green(v$)  \\$)    *   \n"
"    $t:bright_green(/___ $t:bright_magenta(^$) ___\\$)  *    \n"
"________$t:red(|_|$)________$)\n\n"_f,

"\n$t:white(   *             * \n"
"*   *    $t:bright_yellow(*$)    *   \n"
" *      $t:bright_green(/$t:bright_magenta(,$)\\$) *      \n"
"     * $t:bright_green(/_ _\\$)   *           \n"
"  *    $t:bright_green(/  $t:bright_red(%$)\\$)         \n"
"    * $t:bright_green(/_$t:bright_cyan(o$)  _\\$) *     \n"
"      $t:bright_green(/  $t:magenta(0$)  \\$)     *   \n"
"*    $t:bright_green(/_    $t:bright_blue(*$)_\\$)         \n"
"  *  $t:bright_green(/ $t:bright_yellow(+$)  $t:red(v$)  \\$) *     \n"
"    $t:bright_green(/___ $t:green(^$) ___\\$)   *       \n"
"________$t:red(|_|$)________$)\n\n"_f }
		}
};
