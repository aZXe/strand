/* $Revision: 1.17 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc.
// feval.h
//
// MATLAB C++ Math Library support for the MATLAB Compiler's use of feval.
#ifndef _feval_h
#define _feval_h 1

#include "mcccpp.h"
#include "varargout.h"

extern "C" {
  typedef int (*mwFevalFcnPtr)(mlfFuncp, int, mxArray**, int, mxArray**);
}

// This class is used to initialize the math library's feval function table.
// Use of the FEVAL_TABLE macros causes static instances of the class to be 
// created. DO NOT manually create instances of this class.
class mwFevalInit {
private:
  static mlfFuncTabEnt *list;
  static int next;
  static int maxlist;
public:
  mwFevalInit();
  mwFevalInit(const char* name, mlfFuncp func, mwFevalFcnPtr fp);
};

#define DECLARE_FEVAL_TABLE
#define END_FEVAL_TABLE static mwFevalInit _mwFevalInit_;
#define FEVAL_ENTRY(name)\
static mwFevalInit __##name##_feval(#name, (mlfFuncp)name, mwFevalFcn(name));

class mwLocalFunctionTable{
public:
  mwLocalFunctionTable( mexLocalFunctionTable lft ) {
    priv_lft = mclSetCurrentLocalFunctionTable(lft);
  }
  ~mwLocalFunctionTable() { 
    mclSetCurrentLocalFunctionTable(priv_lft);
  }
private:
  mexLocalFunctionTable priv_lft;
};

class mwFunctionTableInit {
  public:
    mwFunctionTableInit(size_t size, mexFunctionTableEntry *f);
};

mwArray feval(mwVarargout vout, mxFunctionPtr fcn, const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN,
 const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN);

mwArray feval(mwVarargout vout, const mwArray &fcn, const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN,
const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN);


// _AUTOGEN_

mwArray feval(mwArray *RO1, const mwArray &fcn);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5, const mwArray &RI6);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5, 
              const mwArray &RI6);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5, const mwArray &RI6);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5, 
              const mwArray &RI6);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5, const mwArray &RI6, 
              const mwArray &RI7);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5, 
              const mwArray &RI6, const mwArray &RI7);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5, const mwArray &RI6, 
              const mwArray &RI7);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5, 
              const mwArray &RI6, const mwArray &RI7);

mwArray feval(mwArray *RO1, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5, const mwArray &RI6, 
              const mwArray &RI7, const mwArray &RI8);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5, 
              const mwArray &RI6, const mwArray &RI7, 
              const mwArray &RI8);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, const mwArray &fcn, 
              const mwArray &RI1, const mwArray &RI2, 
              const mwArray &RI3, const mwArray &RI4, 
              const mwArray &RI5, const mwArray &RI6, 
              const mwArray &RI7, const mwArray &RI8);

mwArray feval(mwArray *RO1, mwArray *RO2, 
              mwArray *RO3, mwArray *RO4, 
              const mwArray &fcn, const mwArray &RI1, 
              const mwArray &RI2, const mwArray &RI3, 
              const mwArray &RI4, const mwArray &RI5, 
              const mwArray &RI6, const mwArray &RI7, 
              const mwArray &RI8);


typedef mwArray (*mwFuncp0in1out)();
typedef mwArray (*mwFuncp0in2out)(mwArray *);
typedef mwArray (*mwFuncp0in3out)(mwArray *,mwArray *);
typedef mwArray (*mwFuncp0in4out)(mwArray *,mwArray *,mwArray *);
typedef mwArray (*mwFuncp0in5out)(mwArray *,mwArray *,mwArray *,mwArray *);
typedef mwArray (*mwFuncp1in1out)(mwArray);
typedef mwArray (*mwFuncp1in2out)(mwArray *,mwArray);
typedef mwArray (*mwFuncp1in3out)(mwArray *,mwArray *,mwArray);
typedef mwArray (*mwFuncp1in4out)(mwArray *,mwArray *,mwArray *,mwArray);
typedef mwArray (*mwFuncp1in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray);
typedef mwArray (*mwFuncp2in1out)(mwArray,mwArray);
typedef mwArray (*mwFuncp2in2out)(mwArray *,mwArray,mwArray);
typedef mwArray (*mwFuncp2in3out)(mwArray *,mwArray *,mwArray,mwArray);
typedef mwArray (*mwFuncp2in4out)(mwArray *,mwArray *,mwArray *,mwArray,mwArray);
typedef mwArray (*mwFuncp2in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray,mwArray);
typedef mwArray (*mwFuncp3in1out)(mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp3in2out)(mwArray *,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp3in3out)(mwArray *,mwArray *,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp3in4out)(mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp3in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp4in1out)(mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp4in2out)(mwArray *,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp4in3out)(mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp4in4out)(mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp4in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp5in1out)(mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp5in2out)(mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp5in3out)(mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp5in4out)(mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp5in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp6in1out)(mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp6in2out)(mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp6in3out)(mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp6in4out)(mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp6in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp7in1out)(mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp7in2out)(mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp7in3out)(mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp7in4out)(mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp7in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp8in1out)(mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp8in2out)(mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp8in3out)(mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp8in4out)(mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);
typedef mwArray (*mwFuncp8in5out)(mwArray *,mwArray *,mwArray *,mwArray *,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray,mwArray);


extern "C" {
    int mwFeval0in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval0in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval0in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval0in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval0in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval1in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval1in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval1in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval1in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval1in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval2in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval2in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval2in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval2in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval2in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval3in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval3in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval3in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval3in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval3in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval4in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval4in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval4in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval4in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval4in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval5in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval5in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval5in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval5in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval5in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval6in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval6in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval6in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval6in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval6in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval7in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval7in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval7in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval7in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval7in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval8in1out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval8in2out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval8in3out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval8in4out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
    int mwFeval8in5out( mlfFuncp pFunc, int nlhs, mxArray **lhs,int nrhs, mxArray **rhs );
}


inline mwFevalFcnPtr mwFevalFcn(mwFuncp0in1out){return mwFeval0in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp0in2out){return mwFeval0in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp0in3out){return mwFeval0in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp0in4out){return mwFeval0in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp0in5out){return mwFeval0in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp1in1out){return mwFeval1in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp1in2out){return mwFeval1in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp1in3out){return mwFeval1in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp1in4out){return mwFeval1in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp1in5out){return mwFeval1in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp2in1out){return mwFeval2in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp2in2out){return mwFeval2in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp2in3out){return mwFeval2in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp2in4out){return mwFeval2in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp2in5out){return mwFeval2in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp3in1out){return mwFeval3in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp3in2out){return mwFeval3in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp3in3out){return mwFeval3in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp3in4out){return mwFeval3in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp3in5out){return mwFeval3in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp4in1out){return mwFeval4in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp4in2out){return mwFeval4in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp4in3out){return mwFeval4in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp4in4out){return mwFeval4in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp4in5out){return mwFeval4in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp5in1out){return mwFeval5in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp5in2out){return mwFeval5in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp5in3out){return mwFeval5in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp5in4out){return mwFeval5in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp5in5out){return mwFeval5in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp6in1out){return mwFeval6in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp6in2out){return mwFeval6in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp6in3out){return mwFeval6in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp6in4out){return mwFeval6in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp6in5out){return mwFeval6in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp7in1out){return mwFeval7in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp7in2out){return mwFeval7in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp7in3out){return mwFeval7in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp7in4out){return mwFeval7in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp7in5out){return mwFeval7in5out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp8in1out){return mwFeval8in1out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp8in2out){return mwFeval8in2out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp8in3out){return mwFeval8in3out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp8in4out){return mwFeval8in4out;}
inline mwFevalFcnPtr mwFevalFcn(mwFuncp8in5out){return mwFeval8in5out;}
#endif //_feval_h
