/* $Revision: 1.2 $ */
// Copyright (c) 1995-2000 The MathWorks, Inc.
// libhginit.hpp
//
// A special class for handle graphics library initialization.  The class
// contains no data.  Its constructor initializes the library.

#ifndef libhginit_h
#define libhginit_h

#include "init.h"

//
// initialization code for C++/handle graphics
//

class mwLibhgInit : public mwLibInit {
 public:
  mwLibhgInit(mexcpp_information info)
    : mwLibInit(info) { mlfHGInitialize(NULL, NULL); }
  mwLibhgInit(mexcpp_information info, int* argc, const char** argv)
    : mwLibInit(info) { mlfHGInitialize(argc, argv); }
  ~mwLibhgInit() { mlfHGWaitForFiguresToDie(); mlfHGTerminate(); }
};

inline int mwMainhg(int argc,
		    const char** argv,
		    mxFunctionPtr fcn,
		    int output,
		    mexcpp_information info)
{
  try {
    mwLibhgInit init(info, &argc, argv);
    return mwMainCommon(argc, argv, fcn, output, info);
  } catch(mwException e) {
    cout << e;
    return 1;
  }
}

#endif
