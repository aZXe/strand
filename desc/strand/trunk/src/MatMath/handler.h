/* $Revision: 1.8 $ */
// Copyright (c) 1995-1998, The MathWorks, Inc. All Rights Reserved.
// handler.h
// Peter Webb, Sept. 1995
//
// Function protoypes for the print, error and memory allocation management
// routines.

#ifndef manager_h
#define manager_h

class mwException;

typedef void (*mwOutputFunc)(const char *);
typedef void (*mwErrorFunc)(const char*, mwBool);
typedef void (*mwExceptionMsgFunc)(const mwException &);
typedef void (*mwMemCompactFunc)(void);
extern "C" {
typedef void *(*mwMemAllocFunc)(size_t);
typedef void (*mwMemFreeFunc)(void *);
typedef void *(*mwMemReallocFunc)(void *, size_t);
typedef void *(*mwMemCallocFunc)(size_t, size_t);
}

void mwSetPrintHandler(mwOutputFunc);
mwOutputFunc mwGetPrintHandler(void);
void mwSetErrorMsgHandler(mwErrorFunc);
mwErrorFunc mwGetErrorMsgHandler(void);

void mwSetAllocHandler(mwMemAllocFunc);
void mwSetFreeHandler(mwMemFreeFunc);
void mwSetCompactHandler(mwMemCompactFunc);
void mwSetLibraryAllocFcns(mwMemCallocFunc, mwMemFreeFunc, mwMemReallocFunc,
                           mwMemAllocFunc, mwMemCompactFunc=0);


void mwDisplayException(const mwException &ex);
void mwSetExceptionMsgHandler(mwExceptionMsgFunc f);
mwExceptionMsgFunc mwGetExceptionMsgHandler(void);

#ifdef EXCEPTIONS_WORK
#define MW_BEGIN_MLX() \
    mclCppContext _mcl_cpp_ctx_;\
    try {\
        mclEnterCppContext(&_mcl_cpp_ctx_)


#define MW_END_MLX() \
    } catch (mwException &e) {\
        e.type();\
        mclCppError(&_mcl_cpp_ctx_);\
    } mclExitCppContext(&_mcl_cpp_ctx_)
#else
#define MW_BEGIN_MLX() \
    mclCppContext _mcl_cpp_ctx_;\
    mclEnterCppContext(&_mcl_cpp_ctx_)


#define MW_END_MLX() \
    mclExitCppContext(&_mcl_cpp_ctx_)
#endif

#ifndef USE_MW_PREFIX

typedef mwOutputFunc OutputFunc;
typedef mwErrorFunc ErrorFunc;
typedef mwMemAllocFunc MemAllocFunc;
typedef mwMemFreeFunc MemFreeFunc;
typedef mwExceptionMsgFunc ExceptionMsgFunc;
typedef mwMemCompactFunc MemCompactFunc;
typedef mwMemReallocFunc MemReallocFunc;
typedef mwMemCallocFunc MemCallocFunc;

#endif

#endif

