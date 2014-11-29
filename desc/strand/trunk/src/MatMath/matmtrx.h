/* $Revision: 1.2 $ */
// Copyright (c) 1995-1998, The MathWorks, Inc. All Rights Reserved.
// matmtrx.h
// Peter Webb, Apr. 1995

// Try to keep the name "Matrix" for ourselves.

#define Matrix MatlabMatrix


#include "v4.h"
#undef mxCallocInt
#undef mxCallocReal
#undef mxCreateDoubleMatrix(0,0,mxREAL)

extern "C" {

extern Matrix *mxCreateDoubleMatrix(0,0,mxREAL);

} // end extern "C"

#undef Matrix

