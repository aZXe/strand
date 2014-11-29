/* $Revision: 1.27 $ */
// Copyright (c) 1995-2000, The MathWorks, Inc. All Rights Reserved.
// mcccpp.h
// Peter Webb, Oct. 1996
//
// MATLAB Compiler C++ mode support.

#ifndef mcccpp_h
#define mcccpp_h 1

#include "dblmtrx.h"
#include "matmtxif.h"
#include <string.h>

mwArray get_global(char *s);
void set_global(char *s, const mwArray &mat);
void feval(int nlhs, mwArray plhs[], int nrhs, mwArray prhs[],
           const mwArray &fcn);
void clear_global( const char *name );
void clear_all_globals( void );

inline mwArray mppUndefVar(char *name, int line, char *file)
{
    mwUndefVar ex(name, line, file);
    ex.do_raise();
    return 0;
}

class mwForLoopIterator
{
public:
    mwForLoopIterator();
    void Start(const mwArray &a1, const mwArray &a2=mwArray::DIN, const mwArray &a3=mwArray::DIN);
    int Next(mwArray *out);
    ~mwForLoopIterator() {mclDestroyForLoopIterator_(&iter);}
private:
    mclForLoopIterator iter;
};
    
inline void mwForLoopIterator::Start(const mwArray &a1, const mwArray &a2, const mwArray &a3)
{
    mclForStart(&iter, a1.GetData(), ((!a2.IsDIN())?a2.GetData():(mxArray*)NULL), 
                ((!a3.IsDIN())?a3.GetData():(mxArray*)NULL));
}

inline mwForLoopIterator::mwForLoopIterator()
{
    memset(&iter, 0, sizeof(mclForLoopIterator));
}

inline int mwForLoopIterator::Next(mwArray *out) {
    out->UnshareCpp();
    mxArray *tmp = out->GetData();
    int result = mclForNext(&iter, &tmp);
    if (tmp != out->GetData()) {
        *out = tmp;
    }
    return result;
}

inline bool switchcompare( mwArray switchvar, mwArray casevar )
{
    return (mclSwitchCompare( switchvar.GetData(), casevar.GetData() ));
}

inline bool mwIsUninitializedWarn( const mwArray &in, const char *vname ) 
{
  bool result = false;
  if ( in.IsUninitialized() ) {
    result = true;
    mclUninitWarning( vname );
  }
  return result;
}

inline void mwCheckUndefined( mwArray &in, mclValidateErrorCode errcode, const char *vname  )
{
  if ( in.IsUndefined() ) {
    mclValidateError( errcode, vname );
  }
}

inline mwArray &mwVs_( mwArray &in, mclValidateErrorCode errcode, const char *vname )
{
  mwCheckUndefined( in, errcode, vname );
  if ( in.IsUninitialized() ) {
    mclUninitWarning( vname );
  }
  return in;
}

#ifdef WARNING_FREE_CODE
#define mwVs_(in, errcode, vname) (mwCheckUndefined(in,errcode,vname),in)
#endif

#define mwVsv(in, vname) mwVs_( in, mclFCN_OR_VARIABLE_UNDEFINED, vname )
#define mwVsa(in, vname) mwVs_( in, mclINPUT_UNDEFINED, vname )


#ifndef WARNING_FREE_CODE  
#define mwVve(in,vname) ( mwIsUninitializedWarn( in, vname ) ?                  \
                          mwArray(mxCreateDoubleMatrix(0,0,mxREAL)) : in )
#else
#define mwVve(in,vname) in
#endif

inline mwArray mwVe( const mwArray &in )
{
  if ( in.IsUninitialized() ) {
    return empty();
  } else {
    return in;
  }
}

#ifdef WARNING_FREE_CODE
#define mwVe(in) in
#endif

inline mwArray mwVva( const mwArray &in, mclValidateErrorCode errcode, const char *vname ) {
  if (in.IsUndefined()) {
      mclValidateError( errcode, vname);
  }
  if (mwIsUninitializedWarn(in, vname ))
    return( empty());
  else
    return in;
}

#ifdef WARNING_FREE_CODE
#define mwVva mwVs_
#endif

#define mwVa( in, vname) mwVva( in, mclINPUT_UNDEFINED, vname )
#define mwVv( in, vname) mwVva( in, mclFCN_OR_VARIABLE_UNDEFINED, vname )

inline void mwVo( mwArray *output ) {
  if ( output->IsUndefined() ) {
    *output = mwArray(mclGetUninitializedArray());
  }
}

inline void mwValidateOutput_warn( mwArray &output, int pos, int nargout, const char *vname, const char *fname ) {
  if (output.IsUndefined())
    output.Uninitialize();
  else if (pos <= nargout && output.IsUninitialized()) 
    mclValidateOutputWarning( vname, fname );
}
inline void mwValidateOutput_nowarn( mwArray &output, int pos, int nargout, const char *vname, const char *fname ) {
  if (output.IsUndefined())
    output.Uninitialize();
}
#ifdef WARNING_FREE_CODE
#define mwValidateOutput mwValidateOutput_nowarn
#else
#define mwValidateOutput mwValidateOutput_warn
#endif

void mclCppUninitializeArrays( size_t size, mwArray *pa );

void mclArrayAssign( mwArray *dest, const mwArray &src, const mwArray& sub1 );
void mclArrayAssign( mwArray *dest, const mwArray &src, const mwArray& sub1, const mwArray &sub2 );
mwArray mclArrayRef( const mwArray &dest, const mwArray& sub1 );
mwArray mclArrayRef( const mwArray &dest, const mwArray& sub1, const mwArray &sub2 );

void mclIntArrayAssign( mwArray *dest, const mwArray &src, int sub1 );
void mclIntArrayAssign( mwArray *dest, const mwArray &src, int sub1, int sub2 );
mwArray mclIntArrayRef( const mwArray &dest, int sub1 );
mwArray mclIntArrayRef( const mwArray &dest, int sub1, int sub2 );


inline int mclForIntEnd(const mwArray &e)
{
  return mclForIntEnd(e.GetData());
}

inline int mclForIntIntEnd(int s, int i, const mwArray &e)
{
  return mclForIntIntEnd( s, i, e.GetData());
}

inline int mclLengthInt(const mwArray &e)
{
  return mclLengthInt(e.GetData());
}

inline bool mclEqBool(const mwArray &x1, const mwArray &x2) {
    return mclEqBool(x1.GetData(), x2.GetData());
}

inline bool mclNeBool(const mwArray &x1, const mwArray &x2) {
    return mclNeBool(x1.GetData(), x2.GetData());
}

inline bool mclGeBool(const mwArray &x1, const mwArray &x2) {
    return mclGeBool(x1.GetData(), x2.GetData());
}

inline bool mclGtBool(const mwArray &x1, const mwArray &x2) {
    return mclGtBool(x1.GetData(), x2.GetData());
}

inline bool mclLeBool(const mwArray &x1, const mwArray &x2) {
    return mclLeBool(x1.GetData(), x2.GetData());
}

inline bool mclLtBool(const mwArray &x1, const mwArray &x2) {
    return mclLtBool(x1.GetData(), x2.GetData());
}

inline bool mclNotBool(const mwArray &x) {
    return mclNotBool(x.GetData());
}

mwArray mclCppExecMexFile(const char * fcn_name, 
			  int nargout_, 
			  mwArray varargin);

#endif
