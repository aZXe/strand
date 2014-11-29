/* $Revision: 1.31 $ */
// Copyright (c) 1995-1999, The MathWorks, Inc. All Rights Reserved.
// version.h
// Peter Webb, May 1995
// 
// Localization of all compiler dependencies.  Each "feature" is listed as
// its own #define symbol.  Each compiler turns on the "features" it
// supports.
//
// TEMPLATES_WORK  :  Compiler properly supports templates
// EXCEPTIONS_WORK : Compiler recongnizes catch, try and throw keywords.
// EXPLICIT_TEMPLATES : Compiler requires explicit instantation of templates.
// EXCEPTION_DEFINED  : Compiler defines an exception class
// MS_WIN_API      : Microsoft Windows API in force
// MAC_API         : Macintosh API 
// POSIX_API       : Compiler supports POSIX functions
// BAD_NAN_INF     : NaN and Inf poorly implemented
// CPP_HEADERS     : System header files already prepared for C++
// EIGHT_DOT_THREE : File names limited to 8 chars, period, 3 char extension
// NONSTD_KEYWORDS : Compiler uses non-standard keywords (like pascal).
// WEAK_INLINES    : Inlines can't have for loops or multiple return statements
// WEAK_DEF_ARGS   : Default args that require a constructor not supported
// NO_BUILT_IN_SUPPORT_FOR_BOOL : bool is not a builtin type, like int or double
// LOGICAL_KEYWORDS: and, or, not, are keywords
// WEAK_VARARGS    : Can't pass objects with constructors through ... signature
// INT32_DEFINED   : int32 exists already in AIX 4.3

#ifndef version_h
#define version_h

#define CONST_OP_ARGUMENTS

#define TRIVIAL_CASTS_MATCH

#ifndef MLF_V2
#define MLF_V2
#endif

#define USE_MW_NAMESPACE

#if defined(MSWIND) && defined(MSVC)

#undef USE_MW_NAMESPACE
#undef TRIVIAL_CASTS_MATCH
#define BAD_NAN_INF
#define EIGHT_DOT_THREE
#define EXCEPTIONS_WORK
#define EXCEPTION_DEFINED
#define MS_WIN_API           1
#define INCLUDE_TEMPLATE_CPP
#define NONSTD_KEYWORDS
#define CPP_HEADERS

// Turn off warning about bool being a keyword
#pragma warning(disable: 4237)

// MSVC 5.0 introduces a new type, bool. In MSVC 4.2, you could get bool
// if you included yvals.h. So turn on the NO_BUILT_IN_SUPPORT_FOR_BOOL flag
// if we're using the MSVC 4.2 compiler where _MSC_VER is < 1100, and the
// user has not included yvals.h
#if (_MSC_VER < 1100) && !defined(YVALS)
#define NO_BUILT_IN_SUPPORT_FOR_BOOL
#endif

#endif  // MSVC

#if defined(MSWIND) && defined(WATCOM)

#define EXCEPTIONS_WORK
#define EXCEPTION_DEFINED
#define POSIX_API
#define BAD_NAN_INF
#define NONSTD_KEYWORDS

// In WATCOM 11, bool is a builtin type
#if (__WATCOMC__ < 1100)
#undef USE_MW_NAMESPACE
#define NO_BUILT_IN_SUPPORT_FOR_BOOL
#endif

#endif	// WATCOM

#if defined(MSWIND) && defined(BORLAND)

#define BAD_NAN_INF
#define EIGHT_DOT_THREE
#define EXCEPTIONS_WORK
#define EXCEPTION_DEFINED
#define POSIX_API
#define NONSTD_KEYWORDS
#define MS_WIN_API

#endif	// BORLAND

#if (defined(LNX86) || defined(GLNX86)) && defined(GCC)

#undef EXCEPTIONS_WORK
#define WEAK_VARARGS
#define POSIX_API
#define EXPLICIT_TEMPLATES
#define MATH_OP_MATCHING_OK

#endif

#if defined(SOL2) && defined(GCC)

#undef EXCEPTIONS_WORK
#define WEAK_VARARGS
#define EXCEPTION_DEFINED
#define POSIX_API
#define EXPLICIT_TEMPLATES
#define MATH_OP_MATCHING_OK

#endif	// SOL2

#if defined(SOL2) && !defined(GCC)

#define WEAK_VARARGS
#define COMPLEX_CLASS_EXISTS
#define EXCEPTIONS_WORK
#define EXCEPTION_DEFINED
#define POSIX_API
#define MATH_OP_MATCHING_OK

// SC5.0 makes bool a builtin type and defines _BOOL to indicate such
#if !defined(_BOOL)
#define NO_BUILT_IN_SUPPORT_FOR_BOOL
#endif /* _BOOL */

#endif

#if defined(SGI) && !defined(GCC)

#define EXCEPTIONS_WORK
#define COMPLEX_CLASS_EXISTS
#define POSIX_API
#define MATH_OP_MATCHING_OK
#define ANSI_FUNCTION_MATCHING

#endif

#if defined(SGI64) && !defined(GCC)

#define EXCEPTIONS_WORK
#define COMPLEX_CLASS_EXISTS
#define EXCEPTION_DEFINED
#define POSIX_API
#define MATH_OP_MATCHING_OK
#define ANSI_FUNCTION_MATCHING

#endif

#if defined(SGI) && defined(GCC)

#undef EXCEPTIONS_WORK
#define WEAK_VARARGS
#define POSIX_API
#define EXPLICIT_TEMPLATES
#define ANSI_FUNCTION_MATCHING
#define MATH_OP_MATCHING_OK

#endif


#if defined(HPUX) && !defined(GCC)

#define WEAK_VARARGS
#define EXCEPTIONS_WORK
#define POSIX_API
#define EXCEPTION_DEFINED
#define CPP_HEADERS

#endif

#if defined(HP700) && !defined(GCC)

#define WEAK_VARARGS
#define EXCEPTIONS_WORK
#define POSIX_API
#define EXCEPTION_DEFINED
#define CPP_HEADERS

#endif

#if defined(ALPHA) && defined(GCC)

#undef EXCEPTIONS_WORK
#define WEAK_VARARGS
#define EXPLICIT_TEMPLATES
#define EXCEPTION_DEFINED

#endif

#if defined(ALPHA) && !defined(GCC)

#define COMPLEX_CLASS_EXISTS
#define EXCEPTIONS_WORK
#define EXCEPTION_DEFINED
#define POSIX_API
#if !defined(_BOOL_EXISTS)
#define NO_BUILT_IN_SUPPORT_FOR_BOOL
#endif 

#endif

#if defined(IBM_RS) && !defined(GCC)

#include <float.h>
#define NaN DBL_QNAN

#define POSIX_API
#define EXCEPTION_DEFINED
#define EXCEPTIONS_WORK
#define MATH_OP_MATCHING_OK
#define INT32_DEFINED
#define NO_BUILT_IN_SUPPORT_FOR_BOOL

#undef USE_MW_NAMESPACE

#endif



#ifdef USE_MW_NAMESPACE
namespace MathWorks {}
using namespace MathWorks;
#endif

#endif // version_h
