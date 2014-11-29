/* $Revision: 1.7 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc.
// mathwork.h
// Peter Webb, May 1995
// 
// Determine the correct typedefs for the scalar types

#ifndef mathwork_h
#define mathwork_h

#include "version.h"
#include "tmwtypes.h"

#ifndef INT32_DEFINED
typedef int32_T int32;
#endif //INT32_DEFINED

typedef int16_T int16;
							 
typedef real32_T real32;
typedef real64_T real64;

typedef boolean_T  mwBool;

// On the PC, functions must be explicitly exported from a DLL in order to
// be visible in an import library. Of course, each PC compiler (WATCOM,
// MICROSOFT and BORLAND) handles this a different way.

#if defined(WATCOM)
#if 0
#define DLL_EXPORT2 __export
#define DLL_EXPORT __export
#endif
#endif

#if defined(BORLAND)
#endif

#if defined(MSVC)
#if defined(DLL)
#if defined(EXPORT_DATA)
#define DLL_EXPORT __declspec(dllexport)
#define DLL_EXPORT1 __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#define DLL_EXPORT1 __declspec(dllimport)
#endif
#endif 
#endif

// Only PC's are lunatic enough to use this technology
#ifndef DLL_EXPORT
#define DLL_EXPORT /* */
#endif

#ifndef DLL_EXPORT1
#define DLL_EXPORT1 /* */
#endif

#ifndef DLL_EXPORT2
#define DLL_EXPORT2 /* */
#endif

#endif // mathwork_h
