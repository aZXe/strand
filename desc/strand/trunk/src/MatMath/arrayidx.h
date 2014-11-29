/* $Revision: 1.10 $ */
// Copyright (c) 1995-1998, The MathWorks, Inc. All Rights Reserved.
// arrayidx.h
// Peter Webb, Jan. 1995
//
// The mwArrayIndex class is used to index arrays of high dimension and to
// allow the user to specify ranges of indices.    
// This class provides some of the functionality of MATLAB's colon
// operator.  The default constructor builds an object that is interpreted
// as ":" (i.e. all). 
//
// Indices can take one of four forms, each of which has a constructor
// defined for it below.
//
//    1. A single integer.
//    2. A contigious range of integers, increasing or decreasing.
//    3. A range of integers, separated by a discrete step. 
//    4. An arbitrary-length vector of integers.
//


#ifndef arrayidx_h
#define arrayidx_h

#ifdef GCC
#pragma interface
#endif

#include "matlabmtx.h"
#include "mtrxref.h"

#include <stdlib.h>

class mwNumericSubArray;

class DLL_EXPORT mwArrayIndex
{
public:
    mwArrayIndex();
    mwArrayIndex(double i);
    mwArrayIndex(const mwArrayIndex&);
    mwArrayIndex(const mwArray & start, const mwArray & stop);        // start:stop
    mwArrayIndex(const mwArray & start, const mwArray & step, const mwArray & stop);  // start:step:stop
    mwArrayIndex(const mwArray &);
    mwArrayIndex(const mwNumericSubArray &);
    ~mwArrayIndex();

    mwArrayIndex &operator=(const mwArrayIndex&);
    mwArrayIndex &operator=(const mwArray &);

    mwBool operator==(const mwArrayIndex&) const;
    mwBool operator!=(const mwArrayIndex &o ) const;

    friend class mwNumericSubArray;
    // Conversion
    mwArray ToMatrix() const;

    // Functions to query an index.
    mwBool IsColonIndex() const;
    int32 Size(const mwArray &, int32) const;
    int32 Size() const;

    // Override operators new and delete

    void *operator new(size_t size);
    void operator delete(void *);

private:
    MatrixRef *rep;
    mwArrayIndex(MatrixRef *matref);
};



typedef mwArrayIndex mwIndex;

inline mwArrayIndex::mwArrayIndex(MatrixRef *matref)
{
    rep = matref;
    rep->IncrementRefCount();
}

#ifndef USE_MW_PREFIX
typedef mwArrayIndex Index;
#endif


inline void *mwArrayIndex::operator new(size_t size)
{
    assert(size == sizeof(mwArrayIndex));
    return mxMalloc(size);
}

inline void mwArrayIndex::operator delete(void *ptr)
{
   mxFree(ptr);
}


inline mwArrayIndex::mwArrayIndex()
{
    rep = MatrixRef::Create(mlfCreateColonIndex());
}

inline mwArrayIndex::mwArrayIndex(const mwArrayIndex& index)
{
    rep = index.rep;
    rep->IncrementRefCount();
}


inline mwArrayIndex::~mwArrayIndex()
{
    if (rep && (rep->DecrementRefCount()) == 0)
    { 
        delete rep;
        rep = 0;
    }
}


inline mwArrayIndex &mwArrayIndex::operator=(const mwArrayIndex &ind)
{
    if (&ind != this) {
        // Increment the ref count first in case both point to the same ref
        ind.rep->IncrementRefCount();
        if (rep && (rep->DecrementRefCount()) == 0) {
            delete rep;
        }
        rep = ind.rep;
    } 
    return *this;
}


inline mwBool mwArrayIndex::IsColonIndex() const
{
    return (mwBool)mlfIsColonIndex(rep->GetData());
}

inline int32 mwArrayIndex::Size() const
{
    if (IsColonIndex())
    MLM_THROW0(mwDomainError, \
            "Need array pointer to determine size of ':'.");
    
    int32 size;

    double *pr = mxGetPr(rep->GetData());

    if (mxIsLogical(rep->GetData())) {
      // Count the nonzero elements
      size = 0;
      for(int i = 0; i < mxGetNumberOfElements(rep->GetData()); i++) {
        size += *pr++ != 0.0;
      }
    } else {
      size = mxGetNumberOfElements(rep->GetData());
    }
    
    return size;
}




#endif
