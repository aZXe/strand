/* $Revision: 1.10 $ */
#ifndef _varargout_h
#define _varargout_h 1
#include "dblmtrx.h"
#include "nsubarry.h"
#include "stdexcpt.h"
#include <string.h>


// This class allows the mwVarargout class constructor to have default arguments which are either
// mwArrays or mwNumericSubArrays.
class mwOutputArg 
{
public:
    mwOutputArg(): data(NULL) {;}
    mwOutputArg(const mwArray &a) : data((void*)(&a)), type(ARRAY), size(1) {;}
    mwOutputArg(const mwNumericSubArray &a) : data((void*)(&a)), type(SUBARRAY), size(a.EltCount()) {;} 
    mwOutputArg(const mwOutputArg &other) : data(other.data), size(other.size), type(other.type){;}
    static mwOutputArg DOUT;
private:
    void SingleAssign(const mwArray &a) {
        if (type == ARRAY) {
            *((mwArray*)data) = a;
        } else {
            *((mwNumericSubArray*)data) = a;
        }
    }
    void MultiAssign(mxArray **prhs, int sz) {
        assert(type != ARRAY);
        ((mwNumericSubArray*)data)->MultiAssign(prhs, sz);
    }
    // needed by feval and mwVarargout::AssignOutputs
    mwArray GetReturnValue();
    int Size() const {return size;}
    int size;
    void *data;
    enum {ARRAY, SUBARRAY} type;
    friend class mwVarargout;
};

// This class only exists for use by the special mwVarargout constructors for ans and value cases.
class mwVarargoutType
{
public:
    mwVarargoutType() : type(0) {;}
private:
    char type;
    friend class mwVarargout;
};

// The mwVarargoutClass implements Matlab's varargout functionality in the C++ math library
class mwVarargout
{
public:
    mwVarargout(const mwOutputArg &RI1, const mwOutputArg &OI2=mwOutputArg::DOUT, const mwOutputArg &OI3=mwOutputArg::DOUT, 
		const mwOutputArg &OI4=mwOutputArg::DOUT, const mwOutputArg &OI5=mwOutputArg::DOUT, 
		const mwOutputArg &OI6=mwOutputArg::DOUT, const mwOutputArg &OI7=mwOutputArg::DOUT, 
		const mwOutputArg &OI8=mwOutputArg::DOUT, const mwOutputArg &OI9=mwOutputArg::DOUT, 
		const mwOutputArg &OI10=mwOutputArg::DOUT, const mwOutputArg &OI11=mwOutputArg::DOUT, 
		const mwOutputArg &OI12=mwOutputArg::DOUT, const mwOutputArg &OI13=mwOutputArg::DOUT, 
		const mwOutputArg &OI14=mwOutputArg::DOUT, const mwOutputArg &OI15=mwOutputArg::DOUT, 
		const mwOutputArg &OI16=mwOutputArg::DOUT, const mwOutputArg &OI17=mwOutputArg::DOUT, 
		const mwOutputArg &OI18=mwOutputArg::DOUT, const mwOutputArg &OI19=mwOutputArg::DOUT, 
		const mwOutputArg &OI20=mwOutputArg::DOUT, const mwOutputArg &OI21=mwOutputArg::DOUT, 
		const mwOutputArg &OI22=mwOutputArg::DOUT, const mwOutputArg &OI23=mwOutputArg::DOUT, 
		const mwOutputArg &OI24=mwOutputArg::DOUT, const mwOutputArg &OI25=mwOutputArg::DOUT, 
		const mwOutputArg &OI26=mwOutputArg::DOUT, const mwOutputArg &OI27=mwOutputArg::DOUT, 
		const mwOutputArg &OI28=mwOutputArg::DOUT, const mwOutputArg &OI29=mwOutputArg::DOUT, 
		const mwOutputArg &OI30=mwOutputArg::DOUT, const mwOutputArg &OI31=mwOutputArg::DOUT, 
		const mwOutputArg &OI32=mwOutputArg::DOUT );
    mwVarargout(const mwVarargout &v, const mwOutputArg &RI1, const mwOutputArg &OI2=mwOutputArg::DOUT, 
		const mwOutputArg &OI3=mwOutputArg::DOUT, const mwOutputArg &OI4=mwOutputArg::DOUT, 
		const mwOutputArg &OI5=mwOutputArg::DOUT, const mwOutputArg &OI6=mwOutputArg::DOUT, 
		const mwOutputArg &OI7=mwOutputArg::DOUT, const mwOutputArg &OI8=mwOutputArg::DOUT, 
		const mwOutputArg &OI9=mwOutputArg::DOUT, const mwOutputArg &OI10=mwOutputArg::DOUT, 
		const mwOutputArg &OI11=mwOutputArg::DOUT, const mwOutputArg &OI12=mwOutputArg::DOUT, 
		const mwOutputArg &OI13=mwOutputArg::DOUT, const mwOutputArg &OI14=mwOutputArg::DOUT, 
		const mwOutputArg &OI15=mwOutputArg::DOUT, const mwOutputArg &OI16=mwOutputArg::DOUT, 
		const mwOutputArg &OI17=mwOutputArg::DOUT, const mwOutputArg &OI18=mwOutputArg::DOUT, 
		const mwOutputArg &OI19=mwOutputArg::DOUT, const mwOutputArg &OI20=mwOutputArg::DOUT, 
		const mwOutputArg &OI21=mwOutputArg::DOUT, const mwOutputArg &OI22=mwOutputArg::DOUT, 
		const mwOutputArg &OI23=mwOutputArg::DOUT, const mwOutputArg &OI24=mwOutputArg::DOUT, 
		const mwOutputArg &OI25=mwOutputArg::DOUT, const mwOutputArg &OI26=mwOutputArg::DOUT, 
		const mwOutputArg &OI27=mwOutputArg::DOUT, const mwOutputArg &OI28=mwOutputArg::DOUT, 
		const mwOutputArg &OI29=mwOutputArg::DOUT, const mwOutputArg &OI30=mwOutputArg::DOUT, 
		const mwOutputArg &OI31=mwOutputArg::DOUT, const mwOutputArg &OI32=mwOutputArg::DOUT );
    mwVarargout():nargout(0), value_only(0) {InitCell();}
    mwArray AssignOutputs();
    void AssignOutputs(int nlhs, mxArray **plhs);
    mwArray &GetCell() { return output_cell; }
    int Nargout() const {return nargout;}
    mwArray GetReturnValue(); 
    static const mwVarargoutType VALUE;
    static const mwVarargoutType ANS;
    mwArray operator()(const mwArray &a) const {return output_cell(a);}
    mwNumericSubArray operator()(const mwArray &a) {return output_cell(a);}
    mwArray cell(const mwArray &a) const {return output_cell.cell(a);}
    mwNumericSubArray cell(const mwArray &a) {return output_cell.cell(a);}
private:
    mwList<mwOutputArg, 10> outputs;
    mwArray output_cell;
    int value_only;
    mwArray dummy_arg;
    int nargout;
    friend mwArray feval(mwVarargout vout, mxFunctionPtr fcn, const mwVarargin &in1, const mwArray &in2, 
			 const mwArray &in3, const mwArray &in4, const mwArray &in5, const mwArray &in6, 
			 const mwArray &in7, const mwArray &in8, const mwArray &in9, const mwArray &in10, 
			 const mwArray &in11, const mwArray &in12, const mwArray &in13, const mwArray &in14, 
			 const mwArray &in15, const mwArray &in16, const mwArray &in17, const mwArray &in18, 
			 const mwArray &in19, const mwArray &in20, const mwArray &in21, const mwArray &in22, 
			 const mwArray &in23, const mwArray &in24, const mwArray &in25, const mwArray &in26, 
			 const mwArray &in27, const mwArray &in28, const mwArray &in29, const mwArray &in30, 
			 const mwArray &in31, const mwArray &in32);
    int append(const mwOutputArg& out);
    int Size() const { return outputs.Length(); }
    friend mwVarargout mwAnsVarargout();
    friend mwVarargout mwValueVarargout();
    mwVarargout(const mwVarargoutType &vtype);
    void InitCell(void);
};

inline mwVarargout mwAnsVarargout() {return mwVarargout(mwVarargout::ANS);}
inline mwVarargout mwValueVarargout() {return mwVarargout(mwVarargout::VALUE);}

#endif // _varargout_h
