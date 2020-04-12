#ifndef H_C49D44343E5E456BA2D4AFB9F2576B7E
#define H_C49D44343E5E456BA2D4AFB9F2576B7E

#define THROW_DECIMAL_EXCEPTION( message ) \
  BOOST_THROW_EXCEPTION( DecimalException() \
        << ErrorString( message ) \
        << ErrorCode( status ) \
        << StatusFlags( DecimalPrivate::statusFlags( status ) ) )
  
  
#define CHECK_DECIMAL_OPERATION( message ) \
  if ( status != 0 ) { \
      THROW_DECIMAL_EXCEPTION( message ); \
  }
    
#define CHECK_DECIMAL_OPERATION_IGNORE_INEXACT_VALUE( message ) \
  if ( status != 0 && status != 4160 ) { \
      THROW_DECIMAL_EXCEPTION( message ); \
  }

#endif // H_C49D44343E5E456BA2D4AFB9F2576B7E
