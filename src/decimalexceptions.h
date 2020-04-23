#ifndef U167A1973DEC053EE9709BC5063087D0A
#define U167A1973DEC053EE9709BC5063087D0A

#include <boost/exception/exception.hpp>
#include <boost/exception/info.hpp>
#include <exception>
#include <string>

namespace mpdecimal
{
  struct DecimalException : public virtual std::exception, virtual boost::exception
  {
  };
  struct NotInitialized : public virtual DecimalException
  {
  };

  typedef boost::error_info<struct tag_error_message, std::string> ErrorString;
  typedef boost::error_info<struct tag_error_code, int> ErrorCode;
  typedef boost::error_info<struct tag_status_flags, std::string> StatusFlags;
} // namespace mpdecimal

#endif // U167A1973DEC053EE9709BC5063087D0A
