/* $Revision: 1.10 $ */
// Copyright (c) 1995-2000 The MathWorks, Inc.
// init.h
// Peter Webb, Aug. 1995
//
// A special class for library initialization.  The class contains no
// data.  Its constructor initializes the library.

#ifndef init_h
#define init_h

#include "version.h"
#include "mathwork.h"
#include "matlab.h"

class DLL_EXPORT mwLibraryInitBuiltins
{
public:
  mwLibraryInitBuiltins();
  ~mwLibraryInitBuiltins();

private:
  static unsigned long refcount;
};

static mwLibraryInitBuiltins mathworks_math_library_initialize_builtins;

// The next type and class are used by compiler-generated library wrappers.

typedef void (*mwFnInitializeModule)();
typedef void (*mwFnTerminateModule)();

class mwArray;

typedef struct mexcppGlobalTableEntry {
  const char* name;   /* the name of the global */
  mwArray* variable;  /* a pointer to the variable */
} *mexcppGlobalTable;

typedef struct {
  void (*initialize)(void);
  void (*terminate)(void);
} _mexcppInitTermTableEntry, *mexcppInitTermTableEntry;

typedef struct _mexcpp_information {
  int version;
  int file_function_table_length;
  mexFunctionTable file_function_table;
  int global_variable_table_length;
  mexcppGlobalTable global_variable_table;
  int npaths;
  const char** paths;
  int                   init_term_table_length;
  mexcppInitTermTableEntry init_term_table;
} *mexcpp_information;

class mwLibInit {
 public:
  mwLibInit(mexcpp_information info);
  virtual ~mwLibInit();

 private:
  //mwFunctionTableInit ftab_;
  _mexcpp_information* lib_info;
  mwLibraryInitBuiltins builtin_init;
};

int mwMainCommon(int argc,
		 const char** argv,
		 mxFunctionPtr fcn,
		 int output,
		 mexcpp_information info);

inline int mwMain(int argc,
		  const char** argv,
		  mxFunctionPtr fcn,
		  int output,
		  mexcpp_information info)
{
  mwLibInit init(info);
  return mwMainCommon(argc, argv, fcn, output, info);
}

#endif
