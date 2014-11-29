// $Revision: 1.17 $
// Copyright (c) 1995-1999, The MathWorks, Inc. All Rights Reserved.

#ifdef BORLAND
#if __BORLANDC__ < 0x0530
// Borland defines max and min as template functions, which conflicts with
// MATLAB's min and max functions.  The Borland include file stdlib.h 
// only defines min and max when the preprocessor constant __MINMAX_DEFINED
// is not defined.  So define it here to prevent the definition of those
// template functions.
#define __MINMAX_DEFINED 1
#elif __BORLANDC__ < 0x0540
#include <excpt>
// By including cstdlib instead of stdlib.h, the min and max functions are
// left in the std namespace and not placed in the global namespace.
#include <cstdlib>
// Temporarily undefine except
#undef except
#else
#include <excpt>
// By including cstdlib instead of stdlib.h, the min and max functions are
// left in the std namespace and not placed in the global namespace.
#include <cstdlib>
#include <_stddef.h> // This gets typedefs from stddef into global namespace
// Temporarily undefine except
#undef except
#endif
#endif

#include <stdio.h>    // stdio.h must be included first to prevent function
                      // overloading errors with fprintf and sprintf
#include "version.h"  // Global #defines and platform dependent settings
#include "dblmtrx.h"  // MATLAB C++ Math Library
#include "matmtxif.h" // Include all the mathematical functions
#include "mcccpp.h"   // Support for the MATLAB Compiler's C++ mode
#include "feval.h"    // Support for feval
#include "mvararg.h"  // Varargin functions
#include "handler.h"  // Error handling and memory management
#include "varargout.h"
#include "libsgl.hpp" // Graphics library interface.

#define mlxBitand_func mlxBitand
#define mlxBitor_func mlxBitor
#define mlxChar_func mlxChar
#define mlxClock_func mlxClock
#define mlxDouble_func mlxDouble
#define mlxDelete_func mlxDelete
#define mlxInt8_func mlxInt8
#define mlxInt16_func mlxInt16
#define mlxInt32_func mlxInt32
#define mlxOverload_func mlxOverload
#define mlxQuad_func mlxQuad
#define mlxRand_func mlxRand
#define mlxSingle_func mlxSingle
#define mlxStd_func mlxStd
#define mlxStruct_func mlxStruct
#define mlxUint8_func mlxUint8
#define mlxUint16_func mlxUint16
#define mlxUint32_func mlxUint32
#define mlxNunion_func mlxNunion
#define mlxUnix_func mlxUnix
#define mlxXor_func mlxXor

#ifdef BORLAND
#if __BORLANDC__ > 0x0530
// Put except back for Borland 5.3
#define except __except
#endif
#endif

#if defined(INTS_DEFINED) && defined(int32) 
#undef int32
#endif //INTS_DEFINED && int32

