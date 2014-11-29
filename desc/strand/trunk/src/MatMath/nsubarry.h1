/* $Revision: 1.16 $ */
// Copyright (c) 1995-1998, The MathWorks, Inc. All Rights Reserved.
// nsubarry.h
// Peter Webb, Mar. 1995
//
// All indexing operations return a mwNumericSubArray object.  It is
// through instances of this class that the copy-on-write
// semantics of the library are implemented.

#ifndef submtrx_h
#define submtrx_h

#ifdef GCC
#pragma interface
#endif

#include "dblmtrx.h"
#include "stdexcpt.h"
#include "mlmexcpt.h"

class mwVarargin;
class mwArrayIndex;

class DLL_EXPORT mwNumericSubArray
{
public:

    mwNumericSubArray();
    mwNumericSubArray(const mwArrayIndex *idx, int32 num, mwArray *r); 
    mwNumericSubArray(mwArray *r, const mwVarargin &list, int type);
    mwNumericSubArray(int32 i, mwArray *r);
    mwNumericSubArray(int32 i, int32 j, mwArray *r);
    mwNumericSubArray(const mwNumericSubArray &other);
    mwNumericSubArray(mwArray *r, const char* fieldname);
    // Conversion routines.  May fail (throw exception) at runtime,
    // if "origin" array can't be converted to appropriate data
    // type.

    ~mwNumericSubArray();

    double Double();
    inline int Int() { return (int)Double(); }

    // Size 

    int32 Size() const;
    int32 Size(int32 *dim) const;
    int32 Size(int32 dim) const;

    // Conversion to full matrix
    MatlabMatrix *ApplyIndex() const;

    // Overriden assignment operator. Do NOT add overloaded operator=() for
    // char *, as that will cause programs to crash (it removes the Math
    // Library's ability to distinguish between a numeric 0 and NULL char *).

    mwArray operator=(const mwArray&);
    mwArray operator=(const mwNumericSubArray &sub);
    mwArray operator=(const mwEmptySqBracket &br);

    // Override operators new and delete

    void *operator new(size_t size);
    void operator delete(void *);

    mwNumericSubArray &operator()(const mwVarargin &v);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27, const mwArray &a28);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27, const mwArray &a28, const mwArray &a29);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27, const mwArray &a28, const mwArray &a29, const mwArray &a30);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27, const mwArray &a28, const mwArray &a29, const mwArray &a30, const mwArray &a31);

    mwNumericSubArray &operator()(const mwArray &a1, const mwArray &a2, const mwArray &a3, const mwArray &a4, const mwArray &a5, const mwArray &a6, const mwArray &a7, const mwArray &a8, const mwArray &a9, const mwArray &a10, const mwArray &a11, const mwArray &a12, const mwArray &a13, const mwArray &a14, const mwArray &a15, const mwArray &a16, const mwArray &a17, const mwArray &a18, const mwArray &a19, const mwArray &a20, const mwArray &a21, const mwArray &a22, const mwArray &a23, const mwArray &a24, const mwArray &a25, const mwArray &a26, const mwArray &a27, const mwArray &a28, const mwArray &a29, const mwArray &a30, const mwArray &a31, const mwArray &a32);

    mwNumericSubArray &cell(const mwVarargin &RI1, const mwArray &OI2=mwArray::DIN, const mwArray &OI3=mwArray::DIN, const mwArray &OI4=mwArray::DIN, const mwArray &OI5=mwArray::DIN, const mwArray &OI6=mwArray::DIN, const mwArray &OI7=mwArray::DIN, const mwArray &OI8=mwArray::DIN, const mwArray &OI9=mwArray::DIN, const mwArray &OI10=mwArray::DIN, const mwArray &OI11=mwArray::DIN, const mwArray &OI12=mwArray::DIN, const mwArray &OI13=mwArray::DIN, const mwArray &OI14=mwArray::DIN, const mwArray &OI15=mwArray::DIN, const mwArray &OI16=mwArray::DIN, const mwArray &OI17=mwArray::DIN, const mwArray &OI18=mwArray::DIN, const mwArray &OI19=mwArray::DIN, const mwArray &OI20=mwArray::DIN, const mwArray &OI21=mwArray::DIN, const mwArray &OI22=mwArray::DIN, const mwArray &OI23=mwArray::DIN, const mwArray &OI24=mwArray::DIN, const mwArray &OI25=mwArray::DIN, const mwArray &OI26=mwArray::DIN, const mwArray &OI27=mwArray::DIN, const mwArray &OI28=mwArray::DIN, const mwArray &OI29=mwArray::DIN, const mwArray &OI30=mwArray::DIN, const mwArray &OI31=mwArray::DIN, const mwArray &OI32=mwArray::DIN );


    mwNumericSubArray &field(const char* fieldname);

    int EltCount() const; 
    void MultiAssign(mxArray **prhs, int sz);
    
private:

    void InitIndexDef(mlfIndexType type);
    mwListOfRefs indices;
    mlfIndexDef indexDef;
    mwArray *rep; 
    friend class mwOutputArg;
};

// Return number of dimensions.

inline int32 mwNumericSubArray::Size() const
{
    return indices.Length();
}

#endif
