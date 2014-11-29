// $Revision: 1.5 $ 
#ifndef _varargin_h
#define _varargin_h 1

class mwVarargin
{
public: 
    void Append(const mwVarargin &v);
    mwArray ToArray() const;
    int Size() const { return list.Length();}
    mwVarargin(int i) {list.addRef(mwArray(i).data);}
    mwVarargin(double d) {list.addRef(mwArray(d).data);}
    mwVarargin(const char* c) {list.addRef(mwArray(c).data);}
    mwVarargin(const mwArray &array);
    mwVarargin(const mwArrayIndex &idx);
    mwVarargin(const mwNumericSubArray &sub);
    mwVarargin(const mwEmptySqBracket &idx);
    mwVarargin(const mwVarargin &v, const mwArray &a2 = mwArray::DIN, const mwArray &a3 = mwArray::DIN, const mwArray &a4 = mwArray::DIN, const mwArray &a5=mwArray::DIN, const mwArray &a6 = mwArray::DIN, const mwArray &a7 = mwArray::DIN, const mwArray &a8 = mwArray::DIN, const mwArray &a9 = mwArray::DIN, const mwArray &a10 = mwArray::DIN, const mwArray &a11=mwArray::DIN, const mwArray &a12=mwArray::DIN, const mwArray &a13 = mwArray::DIN,
                              const mwArray &a14 = mwArray::DIN, const mwArray &a15=mwArray::DIN, const mwArray &a16 = mwArray::DIN, const mwArray &a17 = mwArray::DIN, const mwArray &a18 = mwArray::DIN, const mwArray &a19 = mwArray::DIN, const mwArray &a20 = mwArray::DIN,const mwArray &a21=mwArray::DIN, const mwArray &a22=mwArray::DIN, const mwArray &a23 = mwArray::DIN, const mwArray &a24 = mwArray::DIN, const mwArray &a25=mwArray::DIN,
                              const mwArray &a26 = mwArray::DIN, const mwArray &a27 = mwArray::DIN, const mwArray &a28 = mwArray::DIN, const mwArray &a29 = mwArray::DIN, const mwArray &a30 = mwArray::DIN,const mwArray &a31 = mwArray::DIN, const mwArray &a32=mwArray::DIN);
    int GetNumElts(int i) const;
    void GetArrayBuffer(mxArray **buf) const;
    mwVarargin() {;}
    static mwVarargin DIN;
private:
    int addRef(const mwArray &ref);
    mwListOfRefs list;
    friend class mwNumericSubArray;
};

#endif // _varargin_h

