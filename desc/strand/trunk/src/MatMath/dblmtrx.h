/* $Revision: 1.46 $ */
// Copyright (c) 1995-2000, The MathWorks, Inc. All Rights Reserved.
// dblmtrx.h
// Peter Webb, Sept. 1994
//
// The mwArray class.  Instances of this class manipulate 2D arrays
// of double precision real numbers. 

#if !defined(dblmtrx_h)
#define dblmtrx_h 1

#if defined(BORLAND) && __BORLANDC__ >= 0x0540
#include <cstdlib>
#include <_stddef.h> // This gets typedefs from stddef into global namespace
#endif

// THIS NEEDS TO GO FIRST. The static initializer in init.h sets the memory 
// management functions, and needs to be executed before anything else.
// The constructor for this static variable initializes the library. 
// Initialization consists of various tasks, including setting numeric
// constants like NaN and Inf, and turning off floating point exceptions
// (on non-IEEE platforms where that matters).

#include "init.h"

#ifdef GCC
#pragma interface
#endif

#include <assert.h>

#include "mtrxref.h"
#include "mathwork.h"    // Global typedefs and defines
#include "mlmexcpt.h"    // mlm_exception and MLM_THROW() macros
#include "stdexcpt.h"    // mwException hierarchy
#include "mwstr.h"       // mwString
#include "arrayidx.h"

#if 0
#ifdef COMPLEX_CLASS_EXISTS
#include <complex.h>
#endif
#endif

// Include private information about MATLAB struct matrix.  Rename 
// Matrix to MatlabMatrix.  Also include MLM (built-in) and MLT (toolbox)
// function prototypes.

#define Matrix MatlabMatrix
extern "C" {
#include "matlab.h"
} // End extern "C"
#undef Matrix

// These are defined by MATLAB for automatic generation of header files
// C++ needs them unadorned.

#undef public
#undef private

// Forward decls.

// We can't include arrayidx.h because there is a dependency loop
// between mwArray and mwArrayIndex.  Therefore, forward
// declare mwArrayIndex here.

class mwArrayIndex;
class mwArrayIndexList;
class mwVarargin;
class mwNumericSubArray;
class mwEmptySqBracket;

// Typedefs

typedef int Dimension;

// The default action is to fill the array with zeros. This enum is used
// by the mwArray constructors.

enum mwNumericInitAction 
{ 
    mwEyeAct,    // Places ones on the main diagonal
    mwOnesAct,   // Fill array with ones
    mwZerosAct,  // Fill array with zeros
    mwRandAct,   // Fill array with random numbers
    mwRandnAct   // Fill array with normally distributed random numbers
};

// Enumeration indicating the type of the elements stored in the 
// array

enum mwNumericEltType
{
    mwReal64, mwInt8, mwUnknownNumericEltType
};


// The mwArray class is the heart of the MATLAB C++ Math Library.
// An mwArray contains a pointer to a MatrixRef object.  The
// mwArray class has four private static class variables, 
// IndexBase, an integer that indicates the index of the first element
// in the matrix and three counter variables, one each for constructor
// calls, destructor calls and scalar constructors.
//
// Most of the math routines take mwArray objects as arguments and
// return mwArray objects as results.  Many of the mwArray
// methods are inline, for efficiency.

class DLL_EXPORT mwArray 
{
public:

//////////////////////////////////////////////////////////////////////////////
// Constants
//

// Invalid input and output matrices.  Used by the MATLAB Compiler for 
// specifying default arguments to functions.

#if defined(BORLAND) || defined(SGI)
static mwArray DIN;    // Default input
static mwArray DOUT;   // Default output
static mwArray UNDEFINED; // UNDEFINED Array
static mwArray EMPTY;
#else
static const mwArray DIN;    // Default input
static const mwArray DOUT;   // Default output
static const mwArray UNDEFINED; // UNDEFINED Array
static const mwArray EMPTY;
#endif


//////////////////////////////////////////////////////////////////////////////
// Friends

friend class mwArrayIndex;
friend class mwVarargin;
friend class mwNumericSubArray;
friend class mwOutputArg;

//////////////////////////////////////////////////////////////////////////////
// Constructors
//
// mwArray.  The constructors also count the number of mwArray 
// objects built.

    mwArray();
    mwArray(const char *str);
    mwArray(mwString str);
    mwArray(Dimension, Dimension, mwNumericInitAction);
    mwArray(Dimension, Dimension, double *real, double *imag = 0,
		   int copy = 1);
    mwArray(Dimension, Dimension, int *real, int *imag = 0);
    mwArray(Dimension, Dimension, unsigned short *real,
		   unsigned short *imag = 0);
    mwArray(Dimension, Dimension, short *real,
		   short *imag = 0);
    mwArray(const mwArray &mtrx);
    mwArray(const MatlabMatrix *mtrx, mwBool freeflg =1);
    mwArray(const MatlabMatrix *mtrx, mwBool freeflg, mwBool staticflg);
    mwArray(double start, double step, double stop);
    mwArray(const mwArrayIndex &idx);
    mwArray(const mwNumericSubArray & a);
    mwArray(MatrixRef *matref);
    mwArray(const mwEmptySqBracket &eb);

    mwArray(double);
    mwArray(double, double);
    mwArray(int);
    mwArray(int, const char**);
    mwArray(mxFunctionPtr f, const char *name = "");
#ifdef BORLAND
    mwArray(bool);
#endif
  
    ~mwArray();

//////////////////////////////////////////////////////////////////////////////
// Input and output

    friend inline ostream& operator<<(ostream &os, const mwArray&);
    friend inline istream& operator>>(istream &is, mwArray&);
    void Read(istream&, int is2D = 0);
    void Write(ostream&) const;
    void Print(const char* name) const;
    
    // Assignment

    mwArray &operator=(const mwArray&);

//////////////////////////////////////////////////////////////////////////////
// Memory management.  Override operators new and delete

    inline void *operator new(size_t size);
    inline void operator delete(void *ptr);

//////////////////////////////////////////////////////////////////////////////
// Data extraction.  Reach into the matrix and grab out the doubles stored
// there.

     // Extract data as either integers (used in indexing) or doubles.

     void ExtractData(int32 *);
     void ExtractData(double *);
     void ExtractData(double *, double *);
     double ExtractScalar(double&, int32) const;
     double ExtractScalar(int32) const;

     double x(int32 i) const;

   // Return the MatlabMatrix associated with this mwArray. Not to
   // be used lightly.  The pointer you get back is the real thing - do not
   // write to the matrix structure, or delete the pointer (with, for example,
   // mxDestroyArray). If you do, expect your program to crash soon afterwards.
     inline MatlabMatrix *GetData() const {return data->data;}

#if 0
    void SetData(MatlabMatrix *d);
#endif

    MatlabMatrix *FreezeData(void);
    int32 GetRefCount() {return data->GetRefCount();}
    void Clear();

//////////////////////////////////////////////////////////////////////////////
// Indexing. Overload the () operator to provide multi-dimensional indexing.

    mwArray operator()(const mwVarargin &a) const;
    mwNumericSubArray operator()(const mwVarargin &a);

  mwArray operator()(const mwArray &a1, const mwArray &a2) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
const mwArray &a28) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
const mwArray &a28);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
const mwArray &a28, const mwArray &a29) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
 const mwArray &a28, const mwArray &a29);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
 const mwArray &a28, const mwArray &a29, const mwArray &a30) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
 const mwArray &a28, const mwArray &a29, const mwArray &a30);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
 const mwArray &a28, const mwArray &a29, const mwArray &a30, const mwArray &a31) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
 const mwArray &a28, const mwArray &a29, const mwArray &a30, const mwArray &a31);

  mwArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
 const mwArray &a28, const mwArray &a29, const mwArray &a30, const mwArray &a31, const mwArray &a32) const;
  mwNumericSubArray operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27,
 const mwArray &a28, const mwArray &a29, const mwArray &a30, const mwArray &a31, const mwArray &a32);

   mwArray cell(const mwVarargin &RI1, const mwArray &OI2=mwArray::DIN, const mwArray &OI3=mwArray::DIN, const mwArray &OI4=mwArray::DIN, const mwArray &OI5=mwArray::DIN, const mwArray &OI6=mwArray::DIN, const mwArray &OI7=mwArray::DIN, const mwArray &OI8=mwArray::DIN, const mwArray &OI9=mwArray::DIN, const mwArray &OI10=mwArray::DIN, const mwArray &OI11=mwArray::DIN, const mwArray &OI12=mwArray::DIN, const mwArray &OI13=mwArray::DIN, const mwArray &OI14=mwArray::DIN, const mwArray &OI15=mwArray::DIN, const mwArray &OI16=mwArray::DIN, const mwArray &OI17=mwArray::DIN,
const mwArray &OI18=mwArray::DIN, const mwArray &OI19=mwArray::DIN, const mwArray &OI20=mwArray::DIN, const mwArray &OI21=mwArray::DIN, const mwArray &OI22=mwArray::DIN, const mwArray &OI23=mwArray::DIN, const mwArray &OI24=mwArray::DIN, const mwArray &OI25=mwArray::DIN, const mwArray &OI26=mwArray::DIN, const mwArray &OI27=mwArray::DIN, const mwArray &OI28=mwArray::DIN, const mwArray &OI29=mwArray::DIN, const mwArray &OI30=mwArray::DIN, const mwArray &OI31=mwArray::DIN, const mwArray &OI32=mwArray::DIN ) const;

    mwNumericSubArray cell(const mwVarargin &RI1, const mwArray &OI2=mwArray::DIN, const mwArray &OI3=mwArray::DIN, const mwArray &OI4=mwArray::DIN, const mwArray &OI5=mwArray::DIN, const mwArray &OI6=mwArray::DIN, const mwArray &OI7=mwArray::DIN, const mwArray &OI8=mwArray::DIN, const mwArray &OI9=mwArray::DIN, const mwArray &OI10=mwArray::DIN, const mwArray &OI11=mwArray::DIN, const mwArray &OI12=mwArray::DIN, const mwArray &OI13=mwArray::DIN, const mwArray &OI14=mwArray::DIN, const mwArray &OI15=mwArray::DIN, const mwArray &OI16=mwArray::DIN,
const mwArray &OI17=mwArray::DIN, const mwArray &OI18=mwArray::DIN,const mwArray &OI19=mwArray::DIN, const mwArray &OI20=mwArray::DIN, const mwArray &OI21=mwArray::DIN, const mwArray &OI22=mwArray::DIN, const mwArray &OI23=mwArray::DIN, const mwArray &OI24=mwArray::DIN, const mwArray &OI25=mwArray::DIN, const mwArray &OI26=mwArray::DIN, const mwArray &OI27=mwArray::DIN, const mwArray &OI28=mwArray::DIN, const mwArray &OI29=mwArray::DIN, const mwArray &OI30=mwArray::DIN, const mwArray &OI31=mwArray::DIN, const mwArray &OI32=mwArray::DIN );
  
   
  mwArray field(const char* fieldname) const;
  mwNumericSubArray field(const char* fieldname);

//////////////////////////////////////////////////////////////////////////////
// Misc. member functions

    // Conversion to scalars - only works if the matrix is 1x1.  
    double Double() const;
    inline int Int() const { return (int)Double();}

    // Test all the elements of a matrix against the given real number.
    // If all==1, test to see if all matrix elements are equal to the
    // real number.  If all==0, test to see if any of the elements of the
    // matrix are equal to the given number.

    mwBool EltEqual(double x, mwBool all =1) const;

    // Treat the PR (pointer to real data) of the matrix as a function 
    // pointer. Required by the MATLAB Compiler.

    void *ToFuncPtr() const;

    // If the string flag is on, return a string constructed from the
    // elements of the real part of the matrix.

    mwString ToString() const;

//////////////////////////////////////////////////////////////////////////////
// Matrix size.  Return number and size of dimensions.

    mwBool IsDIN() const { return (data == mwArray::DIN.data); }
    mwBool IsEmpty() const;
    mwBool IsNullMatrix() const;
    mwBool IsString() const;
    mwBool IsUndefined() const;
    mwBool IsUninitialized() const;
    mwBool IsInitialized() const;

    int32 EltCount() const;

    int32 Size() const;
    int32 Size(int32 dim) const;
    int32 Size(int32* dims, int maxdims=2) const;

    // Set the class variable line_width, which affects matrix
    // printing.  See Write().

    static void SetLineWidth(int32 i) { line_width = i; }
    static int32 GetLineWidth() { return line_width; }

    // Implement copy-on-write semantics
    void Unshare();
    inline void UnshareCpp() { if ( data->GetRefCount() > 1 ) UnshareCpp_(); }

    void Uninitialize();

    void CopyInputArg(const mwArray &a);

    void MakeDIN();

    void EqAns( const mwArray &a, mwBool print_flag=0);
    void EqPrintAns( const mwArray &a) {EqAns(a, 1);}

protected:

     // Number of characters between carriage returns
     static int32 line_width; 

    // Turn a real-only matrix into a matrix with both real and imaginary
    // components.
    void BecomeComplex();

    // Make a real copy
    mwArray *Copy(mwBool copy_real =1, mwBool copy_imag = 0) const; 

    void Assign(const mwArray &a);

private:
    void AssignLastValue();
    void UnshareCpp_();

    // Make a MATLAB matrix from an array of doubles

    static MatlabMatrix *MakeMatrix(Dimension, Dimension, double *,
                                    double * =0);
    MatrixRef *ReadString(istream&);
    MatrixRef *ReadCharMatrix(istream&);
    void InitFromString(const char *str);

    void WriteMatrix(ostream&) const;

    // Implemented this way to take advantage of existing MATLAB functions

    MatrixRef *data;

}; // class mwArray




// 
// Order matters! Do not rearrange the order of these functions.  Since
// they are declared above without a linkage class, they must be declared 
// inline before their first use.
//

/////////////////////////////////////////////////////////////////////////////
// Overload the new and delete operators for mwArray.  These have to
// appear first, because some of the other inline functions call them.

inline void * mwArray::operator new(size_t size)
{
    assert(size == sizeof(mwArray));
    return mxMalloc(size);
}

inline void mwArray::operator delete(void *ptr)
{
    mxFree(ptr);
}

/////////////////////////////////////////////////////////////////////////////
// Data extraction. Must appear before the constructors because the
// constructors call GetData().

// Special, efficient extraction of a scalar
inline double mwArray::x(int32 i) const
{ 
    MatlabMatrix *m;
    double *d;
    if (data && (m=data->data) != 0) //<------------------------------------------------------------------------------ 
    {
	d = mxGetPr(m);
	return *(d+i);
    }  
    else MLM_THROW0(mwDomainError, "Extraction from NULL matrix.");
    return 0; // To fool stupid compilers
}

#if 0
// Change the MatlabMatrix the mwArray refers to. 
inline void mwArray::SetData(MatlabMatrix *d)
{
    if (data && data->DecrementRefCount() == 0) delete data;
    data = new MatrixRef(d);
}
#endif

// Very dangerous function.  Allows you to circumvent the automatic
// memory management scheme built into the library. Only necessary in
// very special circumstances.  Please consult the C++ Math Library
// User's Guide before using this function.

inline MatlabMatrix * mwArray::FreezeData(void) 
{
    MatlabMatrix *save =0;
    if (data)
        if (data->count == 1)
	{
	    save=data->data; 
	    data->data=0;
	    data->count=0;
	    delete data;
	    data=0;
	}
        else
        {
            save = mxDuplicateArray(data->data);
        }

    return save;
}

//////////////////////////////////////////////////////////////////////////////
// Matrix size.  Return number and size of dimensions.

// A matrix is empty if any dimension is zero

inline mwBool mwArray::IsEmpty() const
{
    return (GetData() == 0 || mxGetNumberOfElements(GetData()) == 0);
}

// A matrix is a string if it has the string flag set. A NULL matrix
// is not a string matrix.

inline mwBool mwArray::IsString() const
{
    return( GetData() && mxIsChar(GetData()) );
}

inline mwBool mwArray::IsUninitialized() const
{
    return (mwBool) mclIsUninitialized(GetData());
}

inline mwBool mwArray::IsInitialized() const
{
    return !IsUninitialized();
}

inline mwBool mwArray::IsUndefined() const
{ 
    return (mwBool) (data == mwArray::UNDEFINED.data);
}

// Return the number of elements in the matrix

inline int32 mwArray::EltCount() const
{
    MatlabMatrix *matrix = GetData();
    int cnt = 0;

    if (matrix) cnt = ( mxGetNumberOfElements(matrix));
    return cnt;
}

// Return the number of dimensions 

inline int32 mwArray::Size() const { return mxGetNumberOfDimensions(GetData()); } 

// Return the size of the Nth dimension. Currently, only inquiries about
// the size of dimension 1 or dimension 2 are legal.

inline int32 mwArray::Size(int32 dim) const        
{
    MatlabMatrix *matrix = GetData();
    if (matrix != 0) {
        if (dim > Size()) {
            return 1;
        }
        const int *dimarray = mxGetDimensions(GetData());
        return dimarray[dim-1];
    }
    return 0;
}

// Return the size of each dimension, using the space provided.  Return
// the number of dimensions.  If maxdims is specified, remaining dimensions
// (if any) are folded into last dimension.  (Default for maxdims is 2).

inline int32 mwArray::Size(int32* dims, int maxdims) const 
{
    int i, size = Size();
    const int* dimarray = mxGetDimensions(GetData());
    int ndims = size>maxdims?maxdims:size;
    for (i = 0; i < ndims; i++) {
        dims[i] = (int32)dimarray[i];
    }
    // If there are additional dimensions, fold them into the last dim
    if (size > maxdims) {
        int last = maxdims-1;
        for (; i < size; i++) {
            dims[last] *= (int32)dimarray[i];
        }
    } else if (maxdims > size) {
        // If we asked for more than the actual number of dims, fill in trailing
        // dims with 1s
        for(; i < maxdims; i++) {
            dims[i] = 1;
        }
    }
    return size;
}

//////////////////////////////////////////////////////////////////////////////
// Constructors + Destructor
//

// Destructor. Check the reference count; if it is zero, delete the 
// MatlabMatrix associated with this mwArray.
inline mwArray::~mwArray()
{
  if (data && (--(data->count)) == 0) { 
    delete data;
    data = 0;
  }
}


class mwEmptySqBracket
{
public:
  mwEmptySqBracket() { nullindex = 0; };
private:
  int nullindex;
};

inline mwArray::mwArray(const mwEmptySqBracket &br)
{
  (void)br;
  MatlabMatrix *m = mxCreateDoubleMatrix( 0, 0, mxREAL );
  data = MatrixRef::Create(m);
  data->IncrementRefCount();
  assert(data != 0);
} 

// Build a matrix from a string.  Don't forget to set the string flag in
// the MATLAB matrix structure.

inline mwArray::mwArray(const char *str)
    : data(0)
{
    InitFromString(str);
    assert(data != 0);
}

inline mwArray::mwArray(mwString str)
    : data(0)
{
    InitFromString(str);
    assert(data != 0);
}

// Copy constructor. Don't copy the matrix data, just increment the
// reference count.

inline mwArray::mwArray(const mwArray &mtrx)
    : data(0) 
{
    data = mtrx.data;
    assert(data != 0);
    if (data) (data->count)++;
}

// Build a mwArray from a MatlabMatrix. If freeflg == 0, the matrix 
// won't be freed automatically

inline mwArray::mwArray(const MatlabMatrix *mtrx, mwBool freeflg)
    : data(0)
{
    if (mtrx == 0) mtrx = mclGetUninitializedArray();

    data = MatrixRef::Create(mtrx, freeflg);
        
    assert(data != 0);
}

// Create a ramp. Emulates the behaviour of MATLAB's colon operator.
// Special test case for uses that produce a NULL matrix, e.g., 10:1:2

inline mwArray::mwArray(double start, double step, double stop)
    : data(0)
{
    data = MatrixRef::Create(mlfColon(mwArray(start).GetData(),
                                      mwArray(step).GetData(),
                                      mwArray(stop).GetData()));
    assert(data != 0);
}

// Build an mwArray from an mwArrayIndex. Necessary because of
// the interchangability of matrices and indices in MATLAB.

inline mwArray::mwArray(const mwArrayIndex &idx)
{
    mwArray m(idx.ToMatrix());
    data = m.data;
    assert(data != 0);
    data->IncrementRefCount();
}

// Create a cell array from a list of strings (used by compiler for
// converting argc/argv to a cell)
inline mwArray::mwArray(int size, const char **strings)
{
    data = MatrixRef::Create(mclCreateCellFromStrings(size, strings));
    assert(data != 0);
}

// Include mwNumericSubArray here to get the order of inline function
// defs right
#include "nsubarry.h"

// Build an mwArray from an mwNumericSubArray. Though it may not
// be obvious at first, this routine triggers the indexing code. All of
// the subscripting operators (see below) return an mwNumericSubArray 
// object. The mwNumericSubArray object "remembers" the subscripting
// operation, but doesn't actually compute it until necessary. This trick
// is required in order to allow subscripting operations to appear on
// the left hand side of an assignment statement.
//
// This routine computes the result of a subscripting operation that
// is on the right hand side of an assignment statement, or part of
// an expression where no assignment is involved.
inline mwArray::mwArray(const mwNumericSubArray & a)
{
    data = MatrixRef::Create(a.ApplyIndex());
    assert(data != 0);
}

inline mwArray::mwArray(MatrixRef *matref)
{
    data = matref;
    data->IncrementRefCount();
}

inline mwArray::mwArray(mxFunctionPtr f, const char *name )
{
  data = MatrixRef::Create(mclCreateSimpleFunctionHandle(f, name) );
}

inline mwArray mwArray::field(const char* fieldname) const
{
    return mwNumericSubArray((mwArray*)this, fieldname);
}

inline mwNumericSubArray mwArray::field(const char* fieldname) 
{
    return mwNumericSubArray(this, fieldname);
}

/////////////////////////////////////////////////////////////////////////////
// The input and output operators. Inline for efficiency.

inline ostream& operator<<(ostream &os, const mwArray& m)
{
    m.Write(os);
    return os;
}    

inline istream &operator>>(istream &is, mwArray &m)
{
    m.Read(is);
    return is;
}

inline ostream& operator<<(ostream &os, const mwNumericSubArray &a)
{
    os << (mwArray)a;
    return os;
}

// Insert this class into an output stream to change the linewidth on
// the fly.   For example:
//
//    cout << mwOutputLineWidth(40) << matrix1 << endl << matrix2 << endl
//         << mwOutputLineWidth(80) << matrix3 << endl;
//
// matrix1 and matrix2 print using 40-character wide lines and matrix3
// prints using 80-character wide lines.  Negative or zero line widths
// are illegal.

class mwOutputLineWidth 
{
public:

    mwOutputLineWidth(int32 i);
    friend inline ostream& operator<<(ostream& os, const mwOutputLineWidth&);

private:

    int32 width;
};

inline mwOutputLineWidth::mwOutputLineWidth(int32 i)
    : width(i) 
{
    if (width <= 0) 
    {
	width = 75;
	MLM_THROW1(mwRangeError, \
		   "Line width must be positive: %d isn't.",\
		   width)
    }
}

inline ostream& operator<<(ostream& os, const mwOutputLineWidth& w)
{
   mwArray::SetLineWidth(w.width);
   return os;
}

inline void mwArray::Print(const char *name) const
{
    mclPrintArray(GetData(), name);
}


//////////////////////////////////////////////////////////////////////////////
// Indexing. Overload the () operator to provide multi-dimensional indexing.
// Currently, only one and two dimensional indexing is supported.
    
// Need to include this here so that we can call its constructor in inlined functions
#include "varargin.h"

inline mwArray mwArray::operator()(const mwVarargin &s) const
{
    return mwNumericSubArray((mwArray*)this, s, mlfARRAY);
}

inline mwNumericSubArray mwArray::operator()(const mwVarargin &s)
{
    return mwNumericSubArray(this, s, mlfARRAY);
}


#ifndef BORLAND
// Borland 5.0 crashes (internal compiler error) if these functions are
// declared inline.
inline mwArray mwArray::operator()(const mwArray &a1, const mwArray &a2) const
{
	return mwNumericSubArray((mwArray*)this, mwVarargin(a1, a2), mlfARRAY);
}

inline mwNumericSubArray mwArray::operator()(const mwArray &a1, const mwArray &a2)
{
	return mwNumericSubArray((mwArray*)this, mwVarargin(a1, a2), mlfARRAY);
}

inline mwArray mwArray::operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3) const
{
	return mwNumericSubArray((mwArray*)this, mwVarargin(a1, a2, a3), mlfARRAY);
}

inline mwNumericSubArray mwArray::operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3)
{
	return mwNumericSubArray((mwArray*)this, mwVarargin(a1, a2, a3), mlfARRAY);
}
#endif

//////////////////////////////////////////////////////////////////////////////
// Misc. member functions

// Treat the PR (pointer to real data) of the matrix as a function 
// pointer. Required by the MATLAB Compiler.

inline void * mwArray::ToFuncPtr() const
{ 
    MatlabMatrix *ptr = GetData();
    double *pr = 0;
    void *ret = 0;
    if (ptr) { pr = mxGetPr(ptr); if (pr) ret = ((void *)(pr)); }
    return ret;
}

// If the string flag is on, return a string constructed from the
// elements of the real part of the matrix.

inline mwString mwArray::ToString() const
{
    int mn;
    int32 dims[2];
    char *str;

    Size(dims);
    mn = (int)(dims[0]*dims[1]);
    str = new char[mn+1];

    mxGetString(GetData(), str, mn+1);
    return mwString(str, 0);
}

// This class is used by the library to force an input
// to be an mwArray (rather than a type which may be cast to an mwArray)
// in order to prevent ambiguous function overloads.
class mwMustBeArray
{
public:
    mwMustBeArray(const mwArray &a) : rep(a){;}
    mwMustBeArray(const mwNumericSubArray &a) : rep(a){;}
    MatlabMatrix *GetData() { return rep.GetData(); }
private:
    const mwArray rep;
};

#ifndef USE_MW_PREFIX
typedef mwArray Matrix;
#endif

#endif

