/* $Revision: 1.67 $ */
// Copyright (c) 1995-1999, The MathWorks, Inc. All Rights Reserved.
// matmtxif.h
// Peter Webb, July 1995
//
// MATLAB functions/operations of the C++ interface to the MLM and MLT
// libraries.
//

#ifndef matmtxif_h
#define matmtxif_h

#include <stdlib.h>

// HP declares round(), which conflicts with overloaded version
#ifdef  _INCLUDE_HPUX_SOURCE
#define _INCLUDE_HPUX_SOURCE_TEMP
#undef  _INCLUDE_HPUX_SOURCE
#endif
#include <math.h>
#ifdef  _INCLUDE_HPUX_SOURCE_TEMP
#define _INCLUDE_HPUX_SOURCE
#endif

#ifdef MS_WIN_API
#include <strstrea.h>
#else
#include <strstream.h>
#endif

#include "mlmexcpt.h"
#include "varargout.h"

#define Matrix MatlabMatrix

extern "C" {

#include "matlab.h"

} // End extern "C"

#undef Matrix

// Global operators.

#ifdef CONST_OP_ARGUMENTS

#define mwBinaryOp(op, func)                    \
inline mwArray operator op (const mwArray& o1,  \
                            const mwArray& o2)  \
{                                               \
    return func( o1.GetData(), o2.GetData() );  \
}


#define mwUnaryOp(op, func)                     \
inline mwArray operator op (const mwArray& o1)  \
{                                               \
    return func(o1.GetData());                  \
}

#else

#define mwBinaryOp(op, func)                    \
inline mwArray operator op (const mwArray& o1,  \
                            const mwArray& o2)  \
{                                               \
    return func( o1.GetData(), o2.GetData() );  \
}


#define mwUnaryOp(op, func)                     \
inline mwArray operator op (const mwArray& o1)  \
{                                               \
    return func(o1.GetData());                  \
}

#endif //CONST_OP_ARGUMENTS

mwBinaryOp(*, mclMtimes)
mwBinaryOp(+, mclPlus)
mwBinaryOp(/, mclMrdivide)
mwBinaryOp(-, mclMinus)
mwBinaryOp(^, mclMpower)
mwBinaryOp(>, mclGt)
mwBinaryOp(<, mclLt)
mwBinaryOp(>=, mclGe)
mwBinaryOp(<=, mclLe)
mwBinaryOp(==, mclEq)
mwBinaryOp(!=, mclNe)
mwBinaryOp(|, mclOr)
mwBinaryOp(&, mclAnd)

mwUnaryOp(!, mclNot)
mwUnaryOp(~, mclNot)
mwUnaryOp(-, mclUminus)
mwUnaryOp(+, mclUplus)


// Global operators to control interaction with scalars, and prevent
// compilers from performing unwanted random casts
// Global operators to make sure that mwNumericSubArray's stay invisible.
// This frees the user from explicit casts.
//
// This macro defines operations between mwArray's, mwNumericSubArray's
// ints and doubles.  The mwArray and mwNumericSubArray arguments can
// be either const or non-const.  All possible variations are defined.

#ifdef CONST_OP_ARGUMENTS

#define GlobalMatrixOp(op)                                              \
                                                                        \
inline mwArray operator op (int i, const mwArray& mat)                  \
   { return (mwArray(i) op mat); }                                      \
                                                                        \
inline mwArray operator op (char *str, const mwArray& mat)              \
   { return (mwArray(str) op mat); }                                    \
                                                                        \
inline mwArray operator op (const mwArray& mat, int i)                  \
   { return (mat op mwArray(i)); }                                      \
                                                                        \
inline mwArray operator op (double x, const mwArray& mat)               \
   { return (mwArray(x) op mat); }                                      \
                                                                        \
inline mwArray operator op (const mwArray& mat, double x)               \
   { return (mat op mwArray(x)); }                                      \
                                                                        \
inline mwArray operator op (int i, const mwNumericSubArray& sub)        \
   { return (mwArray(i) op mwArray(sub)); }                             \
                                                                        \
inline mwArray operator op (const mwNumericSubArray& sub, int i)        \
   { return (mwArray(sub) op mwArray(i)); }                             \
                                                                        \
inline mwArray operator op (double x, const mwNumericSubArray& sub)     \
   { return (mwArray(x) op mwArray(sub)); }                             \
                                                                        \
inline mwArray operator op (const mwNumericSubArray& sub, double x)     \
   { return (mwArray(sub) op mwArray(x)); }                             \
                                                                        \
inline mwArray operator op (const mwNumericSubArray& sub,               \
                                   const mwArray& d)                    \
{ return (mwArray(sub) op d); }                                         \
                                                                        \
inline mwArray operator op (const mwArray& d,                           \
                                   const mwNumericSubArray& sub)        \
{ return (d op mwArray(sub)); }                                         \
                                                                        \
inline mwArray operator op (const mwNumericSubArray& d,                 \
                                   const mwNumericSubArray& sub)        \
{ return (mwArray(d) op mwArray(sub)); }

#else

// Without const arguments

#define GlobalMatrixOp(op)                                      \
                                                                \
inline mwArray operator op (int i, mwArray mat)                 \
   { return (mwArray(i) op mat); }                              \
                                                                \
inline mwArray operator op (char *str, mwArray mat)             \
   { return (mwArray(str) op mat); }                            \
                                                                \
inline mwArray operator op (mwArray mat, int i)                 \
   { return (mat op mwArray(i)); }                              \
                                                                \
inline mwArray operator op (double x, mwArray mat)              \
   { return (mwArray(x) op mat); }                              \
                                                                \
inline mwArray operator op (mwArray mat, double x)              \
   { return (mat op mwArray(x)); }                              \
                                                                \
inline mwArray operator op (int i, mwNumericSubArray sub)       \
   { return (mwArray(i) op mwArray(sub)); }                     \
                                                                \
inline mwArray operator op (mwNumericSubArray sub, int i)       \
   { return (mwArray(sub) op mwArray(i)); }                     \
                                                                \
inline mwArray operator op (double x, mwNumericSubArray sub)    \
   { return (mwArray(x) op mwArray(sub)); }                     \
                                                                \
inline mwArray operator op (mwNumericSubArray sub, double x)    \
   { return (mwArray(sub) op mwArray(x)); }                     \
                                                                \
inline mwArray operator op (mwNumericSubArray sub,              \
                                   mwArray d)                   \
{ return (mwArray(sub) op d); }                                 \
                                                                \
inline mwArray operator op (mwArray d,                          \
                                   mwNumericSubArray sub)       \
{ return (d op mwArray(sub)); }                                 \
                                                                \
inline mwArray operator op (mwNumericSubArray d,                \
                                   mwNumericSubArray sub)       \
{ return (mwArray(d) op mwArray(sub)); }

#endif //CONST_OP_ARGUMENTS

GlobalMatrixOp(*)
GlobalMatrixOp(/)
GlobalMatrixOp(-)
GlobalMatrixOp(+)
GlobalMatrixOp(^)
GlobalMatrixOp(|)
GlobalMatrixOp(&)

GlobalMatrixOp(>)
GlobalMatrixOp(<)
GlobalMatrixOp(>=)
GlobalMatrixOp(<=)
GlobalMatrixOp(==)
GlobalMatrixOp(!=)

//
// The | operator and & operator require boolean overloads because we do
// not define an overloaded ! operator
//
#if !defined(NO_BUILT_IN_SUPPORT_FOR_BOOL)
#ifdef CONST_OP_ARGUMENTS

inline mwArray operator | (const mwArray &d, bool sb)
{
    return( d | mwArray(sb) );
}
inline mwArray operator | (bool sb, const mwArray &d)
{
    return( mwArray(sb) | d );
}
inline mwArray operator | (const mwNumericSubArray &d, bool sb)
{
    return( d | mwArray(sb) );
}
inline mwArray operator | (bool sb, const mwNumericSubArray &d)
{
    return( mwArray(sb) | d );
}
inline mwArray operator & (const mwArray &d, bool sb)
{
    return( d & mwArray(sb) );
}
inline mwArray operator & (bool sb, const mwArray &d)
{
    return( mwArray(sb) & d );
}
inline mwArray operator & (const mwNumericSubArray &d, bool sb)
{
    return( d & mwArray(sb) );
}
inline mwArray operator & (bool sb, const mwNumericSubArray &d)
{
    return( mwArray(sb) & d );
}

#else
inline mwArray operator | (mwArray d, bool sb)
{
    return( d | mwArray(sb) );
}
inline mwArray operator | (bool sb, mwArray d)
{
    return( mwArray(sb) | d );
}
inline mwArray operator | (mwNumericSubArray d, bool sb)
{
    return( d | mwArray(sb) );
}
inline mwArray operator | (bool sb, mwNumericSubArray d)
{
    return( mwArray(sb) | d );
}
inline mwArray operator & (mwArray d, bool sb)
{
    return( d & mwArray(sb) );
}
inline mwArray operator & (bool sb, mwArray d)
{
    return( mwArray(sb) & d );
}
inline mwArray operator & (mwNumericSubArray d, bool sb)
{
    return( d & mwArray(sb) );
}
inline mwArray operator & (bool sb, mwNumericSubArray d)
{
    return( mwArray(sb) & d );
}
#endif
#endif

// Don't forget the unary operators

inline mwArray operator + (mwNumericSubArray d)
{ return (mwArray(d)); }

inline mwArray operator - (mwNumericSubArray d)
{ return (-mwArray(d)); }

// Other miscellaneous operators

// Prefix
inline mwArray operator++(mwArray &mat)
{
    mat = mat + 1;
    return mat;
}

// Postfix
inline mwArray operator++(mwArray &mat, int)
{
    mat = mat + 1;
    return mat;
}

// Prefix
inline mwArray operator--(mwArray &mat)
{
    mat = mat - 1;
    return mat;
}

// Postfix
inline mwArray operator--(mwArray &mat, int)
{
    mat = mat - 1;
    return mat;
}

// These are macros in some compilers, but they are inline functions here.
#ifdef max
#undef max
#endif
#ifdef isspace
#undef isspace
#endif
#ifdef min
#undef min
#endif
#ifdef ferror
#undef ferror
#endif
#ifdef feof
#undef feof
#endif

#if defined(LNX86) || defined(GLNX86)
#undef finite
#endif

#ifdef NONSTD_KEYWORDS
#ifdef pascal
#undef pascal
#endif
#define pascal pascal_func
#endif

// Avoid possible contention with macros from math.h
#ifdef isfinite
#undef isfinite
#endif
#ifdef isinf
#undef isinf
#endif
#ifdef isnan
#undef isnan
#endif
#ifdef round
#undef round
#endif

#ifdef USE_MW_NAMESPACE
namespace MathWorks {
#endif

#include "mlmif.h"
#include "mltif.h"

// The mwNumericSubArray class makes assignment to sub-arrays much easier,
// but it increases the size of the interface.  Ideally, the operator()
// would only produce an mwNumericSubArray when indexing occurs on the
// left-hand side of an assignment operation.  However, it isn't possible
// to teach C++ this trick.  Therefore, mwNumericSubArrays must be able
// to appear anywhere a matrix can.  This means, in particular, that
// mwNumericSubArray::operator double() must exist.  The introduction of
// such a user-defined conversion to double precision numbers produces an
// ambiguity in the function matching rules.  Whenever an mwNumericSubArray
// appears as an argument to a function has been overloaded to take either a
// double or an mwArray, the compiler can't tell which function to
// call.  Therefore, all such functions must be overloaded to take
// mwNumericSubArrays as well.  Fortunately, this is a relatively small
// set of functions, principally the trig. functions.
//
// When adding functions here, be careful, as each function below is
// potentially recursive; make sure that this is not the only definition
// of the function, i.e. that an overloaded version which takes a
// mwArray or double already exists.

#define SUB(name)\
inline mwArray name(const mwNumericSubArray &sub) \
{ return name(mwArray(sub)); }

// Trigonometric functions
SUB(sin)
SUB(cos)
SUB(tan)
SUB(atan)
SUB(asin)
SUB(acos)
SUB(cosh)
SUB(sinh)
SUB(tanh)
SUB(asinh)
SUB(acosh)
SUB(atanh)

inline mwArray atan2(const mwNumericSubArray &x,
		     const mwNumericSubArray &y)
{ return atan2(mwArray(x), mwArray(y)); }

// Exponents and logarithms
SUB(exp)
SUB(log)
SUB(log10)

// Misc.
SUB(sqrt)
SUB(abs)
SUB(floor)
SUB(ceil)

// Out-of-bounds data

SUB(finite)

#ifndef SGI

SUB(isnan)

#ifdef _SUNMATH_H
// Under Solaris 2.x sunmath.h has a defintion for isinf()
SUB(isinf)
#endif

#endif

#undef SUB

#ifndef TRIVIAL_CASTS_MATCH

// The mathematical functions in the standard C library take doubles.
// Many of them have been overloaded to take mwArray's.  When one of
// these functions is called with an int, some compilers see an ambiguity;
// they incorrectly weigh the trivial cast (int to double) equal to
// the user-defined conversion int to mwArray.  Therefore, provide
// explicit int bindings for all these functions.

#define INT(func) inline double func(int x) { return func((double)x); }

// Trig. functions
INT(sin)
INT(cos)
INT(tan)
INT(atan)
INT(asin)
INT(acos)
INT(cosh)
INT(sinh)
INT(tanh)

#ifdef ARC_H_TRIG
INT(asinh)
INT(acosh)
INT(atanh)
#endif

inline double atan2(int x, int y)    { return atan2((double)x, (double)y); }
inline double atan2(int x, double y) { return atan2((double)x, y); }
inline double atan2(double x, int y) { return atan2(x, (double)y); }

// Exponents and logarithms
INT(exp)
INT(log)
INT(log10)

// Misc.
INT(sqrt)
INT(floor)
INT(ceil)

#endif // TRIVIAL_CASTS_MATCH

inline mwArray cmpstr(const mwArray &s1,
                      const mwArray &s2)
{
    return strcmp(s1, s2);
}


//#ifndef COMPLEX_CLASS_EXISTS
inline mwArray complex(double r, double i)
{ return mwArray(r, i); }
//#endif

inline int gcd(int a, int b)
{
    mwArray a_rhs_(a), b_rhs_(b);
    mwArray result = mlfGcd(0, 0, a_rhs_.GetData(), b_rhs_.GetData());
    return (int)(mwArray(result(1)).Double());
}

inline int gcd(int *c, int *d, int a, int b)
{
    MatlabMatrix *plhs[2], *dres;
    int result;
    mwArray a_rhs_(a), b_rhs_(b);
    dres = mlfGcd(&plhs[0], &plhs[2], a_rhs_.GetData(), b_rhs_.GetData());
    if (*c) *c = (int)(*mxGetPr(plhs[0]));
    if (*d) *d = (int)(*mxGetPr(plhs[1]));
    mxDestroyArray(plhs[0]);
    mxDestroyArray(plhs[1]);
    result = (int)(*mxGetPr(dres));
    mxDestroyArray(dres);
    return result;
}


#ifdef BORLAND
#define MINMAX_INPUT_TYPE mwArray
#else
#define MINMAX_INPUT_TYPE const mwArray &
#endif

inline mwArray max(MINMAX_INPUT_TYPE m1, MINMAX_INPUT_TYPE m2=mwArray::DIN, MINMAX_INPUT_TYPE m3=mwArray::DIN)
{
    MatlabMatrix *prhs[3];
    prhs[0] = m1.GetData();
    if (m2.GetData() == mwArray::DIN.GetData()) {
        prhs[1] = NULL;
    } else {
        prhs[1] = m2.GetData();
    }

    if (m3.GetData() == mwArray::DIN.GetData()) {
        prhs[2] = NULL;
    } else {
        prhs[2] = m3.GetData();
    }

    return mlfMax(NULL, prhs[0], prhs[1], prhs[2]);
}

inline mwArray max(mwArray *OO1, MINMAX_INPUT_TYPE m1, MINMAX_INPUT_TYPE m2=mwArray::DIN, MINMAX_INPUT_TYPE m3=mwArray::DIN)
{
    MatlabMatrix *prhs[3];
    MatlabMatrix *plhs[1]={0};
    prhs[0] = m1.GetData();
    if (m2.GetData() == mwArray::DIN.GetData()) {
        prhs[1] = NULL;
    } else {
        prhs[1] = m2.GetData();
    }

    if (m3.GetData() == mwArray::DIN.GetData()) {
        prhs[2] = NULL;
    } else {
        prhs[2] = m3.GetData();
    }

    MatlabMatrix *result = mlfMax(&plhs[0], prhs[0], prhs[1], prhs[2]);
    if (OO1) *OO1 = plhs[0]; else mxDestroyArray(plhs[0]);
    return result;
}

inline mwArray min(MINMAX_INPUT_TYPE m1, MINMAX_INPUT_TYPE m2=mwArray::DIN, MINMAX_INPUT_TYPE m3=mwArray::DIN)
{
    MatlabMatrix *prhs[3];
    prhs[0] = m1.GetData();
    if (m2.GetData() == mwArray::DIN.GetData()) {
        prhs[1] = NULL;
    } else {
        prhs[1] = m2.GetData();
    }

    if (m3.GetData() == mwArray::DIN.GetData()) {
        prhs[2] = NULL;
    } else {
        prhs[2] = m3.GetData();
    }

    return mlfMin(NULL, prhs[0], prhs[1], prhs[2]);
}

inline mwArray min(mwArray *OO1, MINMAX_INPUT_TYPE m1, MINMAX_INPUT_TYPE m2=mwArray::DIN, MINMAX_INPUT_TYPE m3=mwArray::DIN)
{
    MatlabMatrix *prhs[3];
    MatlabMatrix *plhs[1]={0};
    prhs[0] = m1.GetData();
    if (m2.GetData() == mwArray::DIN.GetData()) {
        prhs[1] = NULL;
    } else {
        prhs[1] = m2.GetData();
    }

    if (m3.GetData() == mwArray::DIN.GetData()) {
        prhs[2] = NULL;
    } else {
        prhs[2] = m3.GetData();
    }

    MatlabMatrix *result = mlfMin(&plhs[0], prhs[0], prhs[1], prhs[2]);
    if (OO1) *OO1 = plhs[0]; else mxDestroyArray(plhs[0]);
    return result;
}

#undef MINMAX_INPUT_TYPE


// Create a matrix from a row major (native C++) array

#ifdef BORLAND
// Borland C++ 5.0 can't compile this if it is inline (internal compiler
// error).
mwArray row2mat(int m, int n, const double *d);
mwArray row2mat(int m, int n, const double *r, const double *c);
#else
inline mwArray row2mat(int m, int n, const double *d)
{
    double *t = (double*)mxMalloc(m * n * sizeof(double));
    int i,j;

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            *((t+(j*m)+i)) = *((d+(i*n)+j));

    mwArray ret(m, n, t, 0, 0);  // Don't copy

    return ret;
}

// Complex matrix
inline mwArray row2mat(int m, int n, const double *r, const double *c)
{
    double *t = (double*)mxMalloc(m*n * sizeof(double));
    double *t1 = (double*)mxMalloc(m*n * sizeof(double));
    int i,j;

    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            *((t+(j*m)+i)) = *((r+(i*n)+j));
            *((t1+(j*m)+i)) = *((c+(i*n)+j));
        }

    mwArray ret(m, n, t, t1, 0);  // Don't copy

    return ret;
}
#endif

#ifdef SOL2
inline mwArray sscanf(char *string,
                      const mwArray &fmt,
                      const mwArray &size)
{
    return mlfSscanf(0, 0, 0, (mwArray(string)).GetData(),
                     fmt.GetData(), size.GetData());
}
inline mwArray sscanf(char *string,
                      char *fmt,
                      const mwArray &size)
{
    return mlfSscanf(0, 0, 0, (mwArray(string)).GetData(),
                     (mwArray(fmt)).GetData(), size.GetData());
}
#endif

inline bool tobool(const mwArray &t_rhs )
{
#ifdef COMPILER_HAS_BOOL
    return(mlfTobool(t_rhs.GetData()) != 0);
#else
    return mlfTobool(t_rhs.GetData());
#endif
}

inline mwArray reallog10(const mwArray &x)
{
    mwArray ret = log10(x);
    if (tobool(imag(ret))) MLM_THROW0(mwRangeError, \
"reallog10() with complex result.");
    return ret;
}

inline mwArray ramp(const mwArray &start,
                    const mwArray &stop)
{
    return mlfColon( start.GetData(), stop.GetData(), NULL );
}

inline mwArray ramp(const mwArray &start,
                    const mwArray &step,
                    const mwArray &stop)
{
    return mlfColon( start.GetData(), step.GetData(), stop.GetData() );
}

inline mwArray iscomplex(const mwArray &m)
{
    return logical(mwArray(mxIsComplex(m.GetData())));
}

inline mwArray sprintf( const mwArray &RI1 )
{
    return mlfSprintf(NULL, RI1.GetData(), NULL );
}

class mwMustBeVarargin
{
public:
  mwMustBeVarargin(const mwVarargin &v) : rep(v) {;}
  mwMustBeVarargin(const mwArray &a) : rep(a) {;}
  mwMustBeVarargin(const mwNumericSubArray &n) : rep(n) {;}
  const mwVarargin &GetData() {return rep;}
private:
  const mwVarargin rep;
};

inline mwArray sprintf(const mwArray &in1, mwMustBeVarargin in2, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN,
const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN,
const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2.GetData(), in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 1;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	prhs[0] = in1.GetData();
	varargin.GetArrayBuffer(prhs + 1);
	nrhs += varargin.Size();
	mlxSprintf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline int size(int *RO1, const mwArray &RI1)
{
    int32 dims[2];
    RI1.Size(dims);

    if (RO1 == NULL) MLM_THROW0(mwDomainError, \
"Output pointer (first arg.) NULL.")

            *RO1 = (int)dims[1];
    return dims[0];
}

inline mwEmptySqBracket empty()
{
  return mwEmptySqBracket();
}

inline mwArray setstr(const mwArray &in1)
{
    mwArray result;
    // This check exists in order to bypass uninitialized variable warning in compiler 1.2 code
    if (in1.IsNullMatrix()) {
        result = char_func(empty());
    } else {
	result = mlfSetstr(in1.GetData());
    }
    return result;
}

int nargin(int varargin, const mwVarargin &args);

void clear(mwArray *var, ...);

mwArray loadstruct(const mwArray &matfile, const mwVarargin &v=mwVarargin::DIN);

inline mwArray cell() {return cell(0,0);}

#define rand rand_func
#define lasterror lasterr

// Backwards compatibility for ode functions

class mwOdeThunk
{
public:
  mwOdeThunk(const mwArray &odefile, const mwArray &param);
  ~mwOdeThunk();
private:
  mexFunctionTableEntry entry;
  mwString name;
};


#define ODEFUNC(func) \
  inline mwArray func(\
               const mwArray &odefile=mwArray::DIN, const mwArray &tspan=mwArray::DIN, \
               const mwArray &y0=mwArray::DIN, const mwArray &options=mwArray::DIN, \
               const mwArray &p=mwArray::DIN)\
  { \
      mwOdeThunk thunk(odefile, p);\
      return N##func(1,NULL, mwVarargout(), odefile, tspan, y0, options, p);\
  }\
  inline mwArray func(mwArray *yout, \
               const mwArray &odefile=mwArray::DIN, const mwArray &tspan=mwArray::DIN, \
               const mwArray &y0=mwArray::DIN, const mwArray &options=mwArray::DIN, \
               const mwArray &p=mwArray::DIN)\
  { \
      mwOdeThunk thunk(odefile, p);\
      return N##func(2,yout, mwVarargout(), odefile, tspan, y0, options, p);\
  }\
  inline mwArray func(mwArray *yout, mwArray *o3, \
               const mwArray &odefile=mwArray::DIN, const mwArray &tspan=mwArray::DIN, \
               const mwArray &y0=mwArray::DIN, const mwArray &options=mwArray::DIN, \
               const mwArray &p=mwArray::DIN)\
  { \
      mwOdeThunk thunk(odefile, p);\
      return N##func(2,yout, mwVarargout(*o3), odefile, tspan, y0, options, p);\
  }\
  inline mwArray func(mwArray *yout, mwArray *o3, mwArray *o4,\
               const mwArray &odefile=mwArray::DIN, const mwArray &tspan=mwArray::DIN, \
               const mwArray &y0=mwArray::DIN, const mwArray &options=mwArray::DIN, \
               const mwArray &p=mwArray::DIN)\
  { \
      mwOdeThunk thunk(odefile, p);\
      return N##func(2,yout, mwVarargout(*o3,*o4), odefile, tspan, y0, options, p);\
  }\
  inline mwArray func(mwArray *yout, mwArray *o3, mwArray *o4, mwArray *o5,\
               const mwArray &odefile=mwArray::DIN, const mwArray &tspan=mwArray::DIN, \
               const mwArray &y0=mwArray::DIN, const mwArray &options=mwArray::DIN, \
               const mwArray &p=mwArray::DIN)\
  { \
      mwOdeThunk thunk(odefile, p);\
      return N##func(2,yout, mwVarargout(*o3,*o4,*o5), odefile, tspan, y0, options, p);\
  }\
  inline mwArray func(mwArray *yout, mwArray *o3, mwArray *o4, mwArray *o5, mwArray *o6,\
               const mwArray &odefile=mwArray::DIN, const mwArray &tspan=mwArray::DIN, \
               const mwArray &y0=mwArray::DIN, const mwArray &options=mwArray::DIN, \
               const mwArray &p=mwArray::DIN)\
  { \
      mwOdeThunk thunk(odefile, p);\
      return N##func(2,yout, mwVarargout(*o3,*o4,*o5,*o6), odefile, tspan, y0, options, p);\
  }

ODEFUNC(ode113)
ODEFUNC(ode15s)
ODEFUNC(ode23)
ODEFUNC(ode23s)
ODEFUNC(ode45)
#undef ODEFUNC

inline mwArray gradient(mwArray *fy, const mwArray &f, const mwArray &hx=mwArray::DIN,
                        const mwArray &hy=mwArray::DIN)
{
    mwArray fx;
    gradient(mwVarargout(fx,*fy), f, hx, hy);
    return fx;
}


inline mwArray mwComplexMatrixFromVector(Dimension r,
                                         Dimension c,
                                         double *real_matrix,
                                         double *imag_matrix = 0)
{
  return mwArray(r, c, real_matrix, imag_matrix, 0);
}

#ifdef USE_MW_NAMESPACE
}
#endif


#endif // matmtxif_h
