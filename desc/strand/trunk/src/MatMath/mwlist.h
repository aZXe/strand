/* $Revision: 1.3 $ */
#ifndef _list_h
#define _list_h 1

// This class implements an expandable list.  It is templatized based on the type of objects
// stored in the list, and the default size.  The default size is the number of
// elements the list can hold without having to allocate any memory.  Elements can be
// added to the end of the list using append(), and existing elements can be accessed
// using [] (no bounds checking is done).  This class exists so that classes which need to
// maintain and grow a list of arrays (such as mwNumericSubArray and mwVarargin) can do so
// without needing to worry about memory (especially when exceptions could be thrown).

template <class ELEMENT_TYPE, int DEFSIZE>
class mwList
{
public:
    // create an emtpy list
    mwList(): nelements(0), size(DEFSIZE) 
    {
        elements = elements_local;
    }
    // create a list with listsize elements (elements are unintialized)
    mwList(int listsize) : nelements(listsize), size(DEFSIZE)
    {
        elements = elements_local;
        if (listsize > size) {
            Grow(listsize);
        }
    }
    void append(ELEMENT_TYPE el)
    {
        if (nelements >= size) {
            Grow();
        }
        elements[nelements++] = el;
    }
    ~mwList() {
        if (elements != elements_local) {
            mxFree(elements);
        }
    }
    ELEMENT_TYPE operator[](int idx) const {return elements[idx];}
    int Length() const {return nelements;}
    mwList(const mwList<ELEMENT_TYPE, DEFSIZE> &other) : 
      nelements(other.nelements), size(DEFSIZE)
    {
        elements = elements_local;
        if (nelements >= size) {
            Grow(nelements);
        }
        memcpy(elements, other.elements, nelements*sizeof(ELEMENT_TYPE));
    }
    ELEMENT_TYPE *GetData() {return elements;}
private:
    int nelements;
    int size;
    ELEMENT_TYPE *elements;
    ELEMENT_TYPE elements_local[DEFSIZE];
    void Grow(int newsize = 0) {
        if (newsize == 0) {
            newsize = 2*size;
        }
        if (newsize > size) {
            ELEMENT_TYPE *new_elem = (ELEMENT_TYPE *)mxMalloc(newsize * sizeof(ELEMENT_TYPE));
            memcpy(new_elem, elements, size*sizeof(ELEMENT_TYPE));
            size = newsize;
            if (elements != elements_local) {
                mxFree(elements);
            }
            elements = new_elem;
        }
    }
    mwList<ELEMENT_TYPE, DEFSIZE> &operator=(const mwList<ELEMENT_TYPE, DEFSIZE> &other);    
};

#endif // _list_h
