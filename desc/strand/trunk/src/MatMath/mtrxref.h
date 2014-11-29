/* $Revision: 1.8 $ */
#ifndef _mtrxref_h
#define _mtrxref_h 1

extern "C" {
#include "matlab.h"
}
#include "matlabmtx.h"
#include "mathwork.h"    // Global typedefs and defines
#include "mlmexcpt.h"    // mlm_exception and MLM_THROW() macros
#include "stdexcpt.h"    // mwException hierarchy
#include "mwlist.h"


// The MatrixRef class makes the implementation of mwArray more
// efficient.  Every mwArray object points to a MatrixRef object.
// MatrixRef objects contain a pointer to a MatlabMatrix and a count of
// how many mwArray objects are pointing to it.  When mwArray
// objects are copied, only the pointer to the MatrixRef object is 
// copied, not the underlying matrix itself.
//

class MatrixRef
{
public:

    friend class mwArray;
    friend class mwNumericSubArray;
    friend class mwOutputArg;

    // Constructors, destructor
    ~MatrixRef();
    static MatrixRef *Create(const MatlabMatrix *m, mwBool fflag=1);

    // Override operators new and delete
    inline void *operator new(size_t size);
    inline void operator delete(void *ptr);

    // Return the MatlabMatrix associated with this object
    MatlabMatrix *GetData() const;

    // Increment, decrement, query reference count
    int32 IncrementRefCount(int32 inc =1);
    int32 DecrementRefCount(int32 dec =1);
    int32 GetRefCount();

private:
    // Copying forbidden. 
    MatrixRef &operator=(const MatrixRef& mr);
    MatrixRef(MatlabMatrix* m, mwBool fflag);
    MatrixRef(const MatrixRef& mr) ;
    MatrixRef();
    MatlabMatrix *data;    // The referred to matrix
    int32 count;           // The reference count
    mwBool free_flag;      // Free the data in the destructor?
};

// 
// Order matters! Do not rearrange the order of these functions.  Since
// they are declared above without a linkage class, they must be declared 
// inline before their first use.
//

// Override new and delete
inline void * MatrixRef::operator new(size_t size)
{
    assert(size == sizeof(MatrixRef));
    return mclSafeMalloc(size);
}

inline void MatrixRef::operator delete(void *ptr)
{
    mclSafeFree(ptr);
}



// Constructor. By default, the free flag is set, which means the destructor,
// when invoked on this object, will attempt to free the MatlabMatrix.

inline MatrixRef::MatrixRef(MatlabMatrix *m, mwBool fflag)
  : data(m), count(1), free_flag(fflag) {}


// This function uses a mwSafeMatrixPointer to ensure correct cleanup of 
// the matrix.
inline MatrixRef *MatrixRef::Create(const MatlabMatrix *m, mwBool fflag)
{
    if ( fflag ) {
      m = mclCppOwnsArray((mxArray*)(m));
    }
    return (new MatrixRef((mxArray*)m, fflag));
}


// Destructor.  Throws an exception if the destroyed object has a non-zero
// reference count. This usually indicates memory corruption of some kind.

inline MatrixRef::~MatrixRef() 
{ 
    assert( count == 0 );
    if ( free_flag == 1) {
      mclDestroyArray(data);
    }
    data = 0;
}

// Return the MatlabMatrix associated with this MatrixRef object

inline MatlabMatrix * MatrixRef::GetData() const
{
    return data;
}

// Increment, decrement and query the reference count.

inline int32 MatrixRef::IncrementRefCount(int32 inc)
{
    return( count += inc );
}

inline int32 MatrixRef::DecrementRefCount(int32 dec)
{
    return( count -= dec );
}

inline int32 MatrixRef::GetRefCount()
{
    return count;
}

class mwListOfRefs
{
public:
    mwListOfRefs(){;}
    void addRef(MatrixRef *ref);
    ~mwListOfRefs();
    MatrixRef *operator[](int ref) const;
    int Length() const {return refs.Length();}
    mwListOfRefs(const mwListOfRefs &other);
private:
    mwList<MatrixRef *, 10> refs;
    mwListOfRefs &operator=(const mwListOfRefs &other);    
};

inline MatrixRef *mwListOfRefs::operator[](int ref) const
{
    return refs[ref];
}

inline void mwListOfRefs::addRef(MatrixRef *ref)
{
    ref->IncrementRefCount();
    refs.append(ref);
}
    

#endif // _mtrxref_h




