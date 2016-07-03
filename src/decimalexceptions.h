#ifndef U167A1973DEC053EE9709BC5063087D0A
#define U167A1973DEC053EE9709BC5063087D0A

#include <exception>
#include <string>
#include <boost/exception/info.hpp>
#include <boost/exception/exception.hpp>

namespace mpdecimal
{
  struct DecimalException : public virtual std::exception, virtual boost::exception { };
  struct NotInitialized   : public virtual DecimalException { };
  
  typedef boost::error_info<struct tag_error_message, std::string> ErrorString;
  typedef boost::error_info<struct tag_error_code, int>            ErrorCode;
}

#endif // U167A1973DEC053EE9709BC5063087D0A
