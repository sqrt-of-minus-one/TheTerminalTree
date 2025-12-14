////////////////////////////////////////////
/////    TheTerminalTree by sqrt(-1)     //
////                                    //
///  File: Escape.tpp                  //
////////////////////////////////////////

namespace ui
{

template<typename... Args>
Escape::EscapeCommand_ Escape::operator()(Args... values) const
{
	return Escape::EscapeCommand_(command_, { values... });
}

}
