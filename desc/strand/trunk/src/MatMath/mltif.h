#ifndef __mltif_h__
#define __mltif_h__ 1

inline mwArray acot(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAcot(prhs[0]);
}


inline mwArray acoth(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAcoth(prhs[0]);
}


inline mwArray acsc(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAcsc(prhs[0]);
}


inline mwArray acsch(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAcsch(prhs[0]);
}


inline mwArray allchild(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAllchild(prhs[0]);
}


inline mwArray angle(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAngle(prhs[0]);
}


inline void Varpackc(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxArpackc(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray arpackc(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxArpackc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray arpackc(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxArpackc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Narpackc(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxArpackc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray asec(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAsec(prhs[0]);
}


inline mwArray asech(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfAsech(prhs[0]);
}


inline mwArray automesh(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxAutomesh(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray axis(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxAxis(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray axis(mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxAxis(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray axis(mwArray *out1, mwArray *out2, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxAxis(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray base2dec(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfBase2dec(prhs[0], prhs[1]);
}


inline mwArray beta(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfBeta(prhs[0], prhs[1], prhs[2]);
}


inline mwArray betacore(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfBetacore(prhs[0], prhs[1], prhs[2]);
}


inline mwArray betainc(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfBetainc(prhs[0], prhs[1], prhs[2]);
}


inline mwArray betaln(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfBetaln(prhs[0], prhs[1]);
}


inline void Vbicg(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicg(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray bicg(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicg(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bicg(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray bicg(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray bicg(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray bicg(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, 
const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	      if (out4 != NULL) {
	        plhs[nlhs++]=NULL;
	      }
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray Nbicg(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicg(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	      }
	    }
	  }
	}
	return plhs[0];
}

inline void Vbicgstab(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicgstab(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray bicgstab(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicgstab(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bicgstab(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicgstab(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray bicgstab(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicgstab(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray bicgstab(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicgstab(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray bicgstab(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	      if (out4 != NULL) {
	        plhs[nlhs++]=NULL;
	      }
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicgstab(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray Nbicgstab(int nargout, mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxBicgstab(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	      }
	    }
	  }
	}
	return plhs[0];
}

inline mwArray bin2dec(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfBin2dec(prhs[0]);
}


inline mwArray bitmax()
{
	return mlfBitmax();
}


inline mwArray blanks(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfBlanks(prhs[0]);
}


inline void Vcalendar(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNCalendar(0, prhs[0], prhs[1]);
}


inline mwArray calendar(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfCalendar(prhs[0], prhs[1]);
}


inline mwArray Ncalendar(int nargout, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNCalendar(nargout, prhs[0], prhs[1]);
}

inline mwArray cart2pol(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfCart2pol(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray cart2pol(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCart2pol(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray cart2pol(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCart2pol(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray cart2sph(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfCart2sph(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray cart2sph(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCart2sph(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray cart2sph(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCart2sph(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray cdf2rdf(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfCdf2rdf(NULL, prhs[0], prhs[1]);
}


inline mwArray cdf2rdf(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCdf2rdf(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void celldisp(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfCelldisp(prhs[0], prhs[1]);
}


inline void Vcellfun(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxCellfun(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray cellfun(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxCellfun(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray cellfun(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxCellfun(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ncellfun(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxCellfun(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray cellstr(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfCellstr(prhs[0]);
}


inline void Vcgs(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxCgs(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray cgs(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxCgs(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cgs(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxCgs(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray cgs(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxCgs(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray cgs(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxCgs(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray cgs(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, 
const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	      if (out4 != NULL) {
	        plhs[nlhs++]=NULL;
	      }
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxCgs(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray Ncgs(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxCgs(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	      }
	    }
	  }
	}
	return plhs[0];
}

inline mwArray funfun_private_colgroup(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_colgroup(prhs[0]);
}


inline mwArray colmmd(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfColmmd(prhs[0]);
}


inline mwArray colperm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfColperm(prhs[0]);
}


inline mwArray compan(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfCompan(prhs[0]);
}


inline void Vcomplex(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxComplex(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray complex(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxComplex(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray complex(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxComplex(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ncomplex(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxComplex(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray cond(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfCond(prhs[0], prhs[1]);
}


inline void Vcondeig(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNCondeig(0, NULL, NULL, prhs[0]);
}


inline mwArray condeig(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfCondeig(NULL, NULL, prhs[0]);
}


inline mwArray condeig(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCondeig(&plhs[1], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray condeig(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCondeig(&plhs[1], &plhs[2], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Ncondeig(int nargout, mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNCondeig(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray condest(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfCondest(NULL, prhs[0], prhs[1]);
}


inline mwArray condest(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfCondest(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray conv(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfConv(prhs[0], prhs[1]);
}


inline mwArray corrcoef(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfCorrcoef(prhs[0], prhs[1]);
}


inline mwArray cot(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfCot(prhs[0]);
}


inline mwArray coth(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfCoth(prhs[0]);
}


inline mwArray cov(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxCov(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cplxpair(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfCplxpair(prhs[0], prhs[1], prhs[2]);
}


inline mwArray cross(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfCross(prhs[0], prhs[1], prhs[2]);
}


inline mwArray csc(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfCsc(prhs[0]);
}


inline mwArray csch(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfCsch(prhs[0]);
}


inline void Vpolyfun_private_cubicmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_cubicmx(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray polyfun_private_cubicmx(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_cubicmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray polyfun_private_cubicmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_cubicmx(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Npolyfun_private_cubicmx(int nargout, mwVarargout varargout, 
const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_cubicmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray cumtrapz(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfCumtrapz(prhs[0], prhs[1], prhs[2]);
}


inline mwArray funfun_private_daeic12(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN)
{
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_daeic12(NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], prhs[7], prhs[8], 
prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], prhs[15]);
}


inline mwArray funfun_private_daeic12(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic12(&plhs[1], NULL, NULL, NULL, NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], 
prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], 
prhs[15]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_daeic12(mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic12(&plhs[1], &plhs[2], NULL, NULL, NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], 
prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], 
prhs[15]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray funfun_private_daeic12(mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic12(&plhs[1], &plhs[2], &plhs[3], NULL, 
NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], 
prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], 
prhs[15]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray funfun_private_daeic12(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic12(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5], prhs[6], prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], 
prhs[13], prhs[14], prhs[15]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray funfun_private_daeic12(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic12(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5], prhs[6], prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], 
prhs[13], prhs[14], prhs[15]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray funfun_private_daeic12(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN)
{
	MatlabMatrix *plhs[7];
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic12(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5], prhs[6], prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], 
prhs[13], prhs[14], prhs[15]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	return plhs[0];
}


inline mwArray funfun_private_daeic12(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN)
{
	MatlabMatrix *plhs[8];
	MatlabMatrix *prhs[16];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic12(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], prhs[0], prhs[1], prhs[2], prhs[3], 
prhs[4], prhs[5], prhs[6], prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], 
prhs[12], prhs[13], prhs[14], prhs[15]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	return plhs[0];
}


inline mwArray funfun_private_daeic3(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN)
{
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_daeic3(NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], prhs[7], prhs[8], 
prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], prhs[15], prhs[16], 
prhs[17], prhs[18], prhs[19]);
}


inline mwArray funfun_private_daeic3(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic3(&plhs[1], NULL, NULL, NULL, NULL, NULL, 
NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], prhs[7], 
prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], prhs[15], 
prhs[16], prhs[17], prhs[18], prhs[19]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_daeic3(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic3(&plhs[1], &plhs[2], NULL, NULL, NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], 
prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], 
prhs[15], prhs[16], prhs[17], prhs[18], prhs[19]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray funfun_private_daeic3(mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic3(&plhs[1], &plhs[2], &plhs[3], NULL, 
NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], 
prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], 
prhs[15], prhs[16], prhs[17], prhs[18], prhs[19]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray funfun_private_daeic3(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic3(&plhs[1], &plhs[2], &plhs[3], &plhs[4], 
NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], 
prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], prhs[14], 
prhs[15], prhs[16], prhs[17], prhs[18], prhs[19]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray funfun_private_daeic3(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic3(&plhs[1], &plhs[2], &plhs[3], &plhs[4], 
&plhs[5], NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], 
prhs[6], prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], 
prhs[14], prhs[15], prhs[16], prhs[17], prhs[18], prhs[19]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray funfun_private_daeic3(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN)
{
	MatlabMatrix *plhs[7];
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic3(&plhs[1], &plhs[2], &plhs[3], &plhs[4], 
&plhs[5], &plhs[6], NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], 
prhs[6], prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], prhs[13], 
prhs[14], prhs[15], prhs[16], prhs[17], prhs[18], prhs[19]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	return plhs[0];
}


inline mwArray funfun_private_daeic3(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN)
{
	MatlabMatrix *plhs[8];
	MatlabMatrix *prhs[20];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	prhs[8] = (!in9.IsDIN())?in9.GetData():(MatlabMatrix*)(NULL);
	prhs[9] = (!in10.IsDIN())?in10.GetData():(MatlabMatrix*)(NULL);
	prhs[10] = (!in11.IsDIN())?in11.GetData():(MatlabMatrix*)(NULL);
	prhs[11] = (!in12.IsDIN())?in12.GetData():(MatlabMatrix*)(NULL);
	prhs[12] = (!in13.IsDIN())?in13.GetData():(MatlabMatrix*)(NULL);
	prhs[13] = (!in14.IsDIN())?in14.GetData():(MatlabMatrix*)(NULL);
	prhs[14] = (!in15.IsDIN())?in15.GetData():(MatlabMatrix*)(NULL);
	prhs[15] = (!in16.IsDIN())?in16.GetData():(MatlabMatrix*)(NULL);
	prhs[16] = (!in17.IsDIN())?in17.GetData():(MatlabMatrix*)(NULL);
	prhs[17] = (!in18.IsDIN())?in18.GetData():(MatlabMatrix*)(NULL);
	prhs[18] = (!in19.IsDIN())?in19.GetData():(MatlabMatrix*)(NULL);
	prhs[19] = (!in20.IsDIN())?in20.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_daeic3(&plhs[1], &plhs[2], &plhs[3], &plhs[4], 
&plhs[5], &plhs[6], &plhs[7], prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5], prhs[6], prhs[7], prhs[8], prhs[9], prhs[10], prhs[11], prhs[12], 
prhs[13], prhs[14], prhs[15], prhs[16], prhs[17], prhs[18], prhs[19]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	return plhs[0];
}


inline mwArray date()
{
	return mlfDate();
}


inline mwArray datenum(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	return mlfDatenum(prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
}


inline void Vdatenummx(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatenummx(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray datenummx(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatenummx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray datenummx(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatenummx(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ndatenummx(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatenummx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray datestr(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfDatestr(prhs[0], prhs[1], prhs[2]);
}


inline void Vdatevec(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNDatevec(0, NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray datevec(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfDatevec(NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray datevec(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDatevec(&plhs[1], NULL, NULL, NULL, NULL, prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray datevec(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDatevec(&plhs[1], &plhs[2], NULL, NULL, NULL, prhs[0], 
prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray datevec(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDatevec(&plhs[1], &plhs[2], &plhs[3], NULL, NULL, prhs[0], 
prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray datevec(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDatevec(&plhs[1], &plhs[2], &plhs[3], &plhs[4], NULL, 
prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray datevec(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDatevec(&plhs[1], &plhs[2], &plhs[3], &plhs[4], &plhs[5], 
prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray Ndatevec(int nargout, mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNDatevec(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, 
nargout>3?&plhs[3]:(MatlabMatrix**)NULL, 
nargout>4?&plhs[4]:(MatlabMatrix**)NULL, 
nargout>5?&plhs[5]:(MatlabMatrix**)NULL, prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	        if (nlhs > 5) {
	          if (out5 != NULL) *out5 = plhs[5];
	        }
	      }
	    }
	  }
	}
	return plhs[0];
}

inline void Vdatevecmx(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatevecmx(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray datevecmx(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatevecmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray datevecmx(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatevecmx(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ndatevecmx(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDatevecmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray dblquad(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxDblquad(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vdeal(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDeal(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray deal(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDeal(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray deal(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDeal(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ndeal(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDeal(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray deblank(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfDeblank(prhs[0]);
}


inline mwArray dec2base(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfDec2base(prhs[0], prhs[1], prhs[2]);
}


inline mwArray dec2bin(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfDec2bin(prhs[0], prhs[1]);
}


inline mwArray dec2hex(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfDec2hex(prhs[0], prhs[1]);
}


inline void Vdeconv(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNDeconv(0, NULL, prhs[0], prhs[1]);
}


inline mwArray deconv(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfDeconv(NULL, prhs[0], prhs[1]);
}


inline mwArray deconv(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDeconv(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Ndeconv(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNDeconv(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray del2(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxDel2(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray delaunay(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfDelaunay(prhs[0], prhs[1], prhs[2]);
}


inline void Vpolyfun_private_delaunayc(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_delaunayc(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray polyfun_private_delaunayc(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_delaunayc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray polyfun_private_delaunayc(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_delaunayc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Npolyfun_private_delaunayc(int nargout, mwVarargout varargout, 
const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_delaunayc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray delaunayn(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfDelaunayn(prhs[0]);
}


inline void Vdmperm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNDmperm(0, NULL, NULL, NULL, prhs[0]);
}


inline mwArray dmperm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfDmperm(NULL, NULL, NULL, prhs[0]);
}


inline mwArray dmperm(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDmperm(&plhs[1], NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray dmperm(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDmperm(&plhs[1], &plhs[2], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray dmperm(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfDmperm(&plhs[1], &plhs[2], &plhs[3], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray Ndmperm(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
const mwArray &in1=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNDmperm(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, 
nargout>3?&plhs[3]:(MatlabMatrix**)NULL, prhs[0]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	    }
	  }
	}
	return plhs[0];
}

inline mwArray dot(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfDot(prhs[0], prhs[1], prhs[2]);
}


inline mwArray dsearch(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDsearch(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vpolyfun_private_dsrchmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_dsrchmx(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray polyfun_private_dsrchmx(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_dsrchmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray polyfun_private_dsrchmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_dsrchmx(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Npolyfun_private_dsrchmx(int nargout, mwVarargout varargout, 
const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_dsrchmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Veigs(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxEigs(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray eigs(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxEigs(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray eigs(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxEigs(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Neigs(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxEigs(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Veigs2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxEigs2(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray eigs2(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxEigs2(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray eigs2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxEigs2(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Neigs2(int nargout, mwVarargout varargout, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxEigs2(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray ellipj(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfEllipj(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray ellipj(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfEllipj(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray ellipj(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfEllipj(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray ellipke(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfEllipke(NULL, prhs[0], prhs[1]);
}


inline mwArray ellipke(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfEllipke(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray eomday(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfEomday(prhs[0], prhs[1]);
}


inline mwArray erf(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfErf(prhs[0]);
}


inline mwArray erfc(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfErfc(prhs[0]);
}


inline void Verfcore(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxErfcore(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray erfcore(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxErfcore(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray erfcore(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxErfcore(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nerfcore(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxErfcore(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray erfcx(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfErfcx(prhs[0]);
}


inline mwArray erfinv(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfErfinv(prhs[0]);
}


inline mwArray etime(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfEtime(prhs[0], prhs[1]);
}


inline mwArray expint(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfExpint(prhs[0]);
}


inline mwArray expm1(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfExpm1(prhs[0]);
}


inline mwArray expm2(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfExpm2(prhs[0]);
}


inline mwArray expm3(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfExpm3(prhs[0]);
}


inline mwArray factor(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFactor(prhs[0]);
}


inline void Vfcnchk(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxFcnchk(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray fcnchk(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxFcnchk(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fcnchk(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxFcnchk(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nfcnchk(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwVarargin &in2=mwVarargin::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxFcnchk(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray fft2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfFft2(prhs[0], prhs[1], prhs[2]);
}


inline mwArray fftshift(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfFftshift(prhs[0], prhs[1]);
}


inline mwArray fgetl(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFgetl(prhs[0]);
}


inline mwArray fileparts(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFileparts(NULL, NULL, NULL, prhs[0]);
}


inline mwArray fileparts(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFileparts(&plhs[1], NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray fileparts(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFileparts(&plhs[1], &plhs[2], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray fileparts(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFileparts(&plhs[1], &plhs[2], &plhs[3], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray filesep()
{
	return mlfFilesep();
}


inline mwArray filter2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfFilter2(prhs[0], prhs[1], prhs[2]);
}


inline mwArray fliplr(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFliplr(prhs[0]);
}


inline mwArray flipud(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFlipud(prhs[0]);
}


inline mwArray fmin(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFmin(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fmin(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFmin(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void Vfminbnd(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFminbnd(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray fminbnd(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFminbnd(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fminbnd(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFminbnd(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray fminbnd(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFminbnd(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray fminbnd(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFminbnd(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray Nfminbnd(int nargout, mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFminbnd(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	    }
	  }
	}
	return plhs[0];
}

inline mwArray fmins(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFmins(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fmins(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxFmins(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void Vfminsearch(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin 
&in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxFminsearch(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray fminsearch(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin 
&in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxFminsearch(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fminsearch(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin 
&in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxFminsearch(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray fminsearch(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxFminsearch(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray fminsearch(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxFminsearch(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray Nfminsearch(int nargout, mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxFminsearch(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	    }
	  }
	}
	return plhs[0];
}

inline mwArray foptions(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFoptions(prhs[0]);
}


inline void Vfreqspace(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNFreqspace(0, NULL, prhs[0], prhs[1]);
}


inline mwArray freqspace(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfFreqspace(NULL, prhs[0], prhs[1]);
}


inline mwArray freqspace(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFreqspace(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nfreqspace(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNFreqspace(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline void frewind(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfFrewind(prhs[0]);
}


inline mwArray fullfile(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxFullfile(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vfunm(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNFunm(0, NULL, prhs[0], prhs[1]);
}


inline mwArray funm(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfFunm(NULL, prhs[0], prhs[1]);
}


inline mwArray funm(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunm(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nfunm(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNFunm(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray funfun_private_funstring(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_funstring(prhs[0]);
}


inline void Vfzero(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwVarargin &in3=mwVarargin::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN)
{
	mwVarargin varargin(in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, 
in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, 
in26, in27, in28, in29, in30, in31, in32, in33, in34);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(2 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    varargin.GetArrayBuffer(prhs + 2);
	    nrhs += varargin.Size();
	  }
	}
	mlxFzero(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray fzero(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwVarargin &in3=mwVarargin::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN)
{
	mwVarargin varargin(in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, 
in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, 
in26, in27, in28, in29, in30, in31, in32, in33, in34);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(2 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    varargin.GetArrayBuffer(prhs + 2);
	    nrhs += varargin.Size();
	  }
	}
	mlxFzero(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fzero(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwVarargin &in3=mwVarargin::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN)
{
	mwVarargin varargin(in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, 
in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, 
in26, in27, in28, in29, in30, in31, in32, in33, in34);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(2 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    varargin.GetArrayBuffer(prhs + 2);
	    nrhs += varargin.Size();
	  }
	}
	mlxFzero(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray fzero(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwVarargin 
&in3=mwVarargin::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN)
{
	mwVarargin varargin(in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, 
in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, 
in26, in27, in28, in29, in30, in31, in32, in33, in34);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(2 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    varargin.GetArrayBuffer(prhs + 2);
	    nrhs += varargin.Size();
	  }
	}
	mlxFzero(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray fzero(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwVarargin 
&in3=mwVarargin::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN)
{
	mwVarargin varargin(in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, 
in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, 
in26, in27, in28, in29, in30, in31, in32, in33, in34);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(2 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    varargin.GetArrayBuffer(prhs + 2);
	    nrhs += varargin.Size();
	  }
	}
	mlxFzero(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray Nfzero(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwVarargin &in3=mwVarargin::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN)
{
	mwVarargin varargin(in3, in4, in5, in6, in7, in8, in9, in10, in11, in12, 
in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, 
in26, in27, in28, in29, in30, in31, in32, in33, in34);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(2 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    varargin.GetArrayBuffer(prhs + 2);
	    nrhs += varargin.Size();
	  }
	}
	mlxFzero(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	    }
	  }
	}
	return plhs[0];
}

inline void Vgamma(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGamma(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray gamma(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGamma(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray gamma(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGamma(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ngamma(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGamma(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray gammainc(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGammainc(prhs[0], prhs[1]);
}


inline void Vgammaln(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGammaln(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray gammaln(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGammaln(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray gammaln(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGammaln(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Ngammaln(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxGammaln(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray gca(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfGca(prhs[0]);
}


inline mwArray gcd(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfGcd(NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray gcd(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfGcd(&plhs[1], NULL, prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray gcd(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfGcd(&plhs[1], &plhs[2], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray gcf()
{
	return mlfGcf();
}


inline mwArray getfield(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxGetfield(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vgmres(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwVarargin &in9=mwVarargin::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN, const mwArray 
&in40=mwArray::DIN)
{
	mwVarargin varargin(in9, in10, in11, in12, in13, in14, in15, in16, in17, 
in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, 
in31, in32, in33, in34, in35, in36, in37, in38, in39, in40);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(8 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                varargin.GetArrayBuffer(prhs + 8);
	                nrhs += varargin.Size();
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxGmres(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray gmres(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwVarargin &in9=mwVarargin::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN, const mwArray 
&in40=mwArray::DIN)
{
	mwVarargin varargin(in9, in10, in11, in12, in13, in14, in15, in16, in17, 
in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, 
in31, in32, in33, in34, in35, in36, in37, in38, in39, in40);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(8 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                varargin.GetArrayBuffer(prhs + 8);
	                nrhs += varargin.Size();
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxGmres(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray gmres(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwVarargin &in9=mwVarargin::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN, const mwArray 
&in40=mwArray::DIN)
{
	mwVarargin varargin(in9, in10, in11, in12, in13, in14, in15, in16, in17, 
in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, 
in31, in32, in33, in34, in35, in36, in37, in38, in39, in40);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(8 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                varargin.GetArrayBuffer(prhs + 8);
	                nrhs += varargin.Size();
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxGmres(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray gmres(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwVarargin 
&in9=mwVarargin::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN)
{
	mwVarargin varargin(in9, in10, in11, in12, in13, in14, in15, in16, in17, 
in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, 
in31, in32, in33, in34, in35, in36, in37, in38, in39, in40);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(8 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                varargin.GetArrayBuffer(prhs + 8);
	                nrhs += varargin.Size();
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxGmres(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray gmres(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwVarargin 
&in9=mwVarargin::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN)
{
	mwVarargin varargin(in9, in10, in11, in12, in13, in14, in15, in16, in17, 
in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, 
in31, in32, in33, in34, in35, in36, in37, in38, in39, in40);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(8 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                varargin.GetArrayBuffer(prhs + 8);
	                nrhs += varargin.Size();
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxGmres(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray gmres(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, 
const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwVarargin 
&in9=mwVarargin::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN)
{
	mwVarargin varargin(in9, in10, in11, in12, in13, in14, in15, in16, in17, 
in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, 
in31, in32, in33, in34, in35, in36, in37, in38, in39, in40);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	      if (out4 != NULL) {
	        plhs[nlhs++]=NULL;
	      }
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(8 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                varargin.GetArrayBuffer(prhs + 8);
	                nrhs += varargin.Size();
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxGmres(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray Ngmres(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwVarargin 
&in9=mwVarargin::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN)
{
	mwVarargin varargin(in9, in10, in11, in12, in13, in14, in15, in16, in17, 
in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, 
in31, in32, in33, in34, in35, in36, in37, in38, in39, in40);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(8 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                varargin.GetArrayBuffer(prhs + 8);
	                nrhs += varargin.Size();
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxGmres(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	      }
	    }
	  }
	}
	return plhs[0];
}

inline mwArray gradient(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
const mwVarargin &in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const 
mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxGradient(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray gradient(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxGradient(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline void Vgriddata(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	mlfNGriddata(0, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5]);
}


inline mwArray griddata(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	return mlfGriddata(NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], 
prhs[4], prhs[5]);
}


inline mwArray griddata(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfGriddata(&plhs[1], NULL, prhs[0], prhs[1], prhs[2], prhs[3], 
prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray griddata(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfGriddata(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2], 
prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Ngriddata(int nargout, mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNGriddata(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2], prhs[3], 
prhs[4], prhs[5]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray hadamard(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfHadamard(prhs[0]);
}


inline mwArray hankel(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfHankel(prhs[0], prhs[1]);
}


inline mwArray hex2dec(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfHex2dec(prhs[0]);
}


inline mwArray hex2num(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfHex2num(prhs[0]);
}


inline mwArray hilb(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfHilb(prhs[0]);
}


inline void Vhistc(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHistc(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray histc(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHistc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray histc(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHistc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nhistc(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHistc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void hold(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfHold(prhs[0]);
}


inline mwArray ifft2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfIfft2(prhs[0], prhs[1], prhs[2]);
}


inline void Vind2sub(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxInd2sub(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray ind2sub(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxInd2sub(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray ind2sub(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxInd2sub(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nind2sub(int nargout, mwVarargout varargout, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxInd2sub(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray inpolygon(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfInpolygon(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray int2str(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfInt2str(prhs[0]);
}


inline mwArray interp1(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxInterp1(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray interp1q(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfInterp1q(prhs[0], prhs[1], prhs[2]);
}


inline mwArray interp2(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxInterp2(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray interpft(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfInterpft(prhs[0], prhs[1], prhs[2]);
}


inline void Vintersect(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNIntersect(0, NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray intersect(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfIntersect(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray intersect(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfIntersect(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray intersect(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfIntersect(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nintersect(int nargout, mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNIntersect(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray invhilb(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfInvhilb(prhs[0]);
}


inline mwArray ipermute(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfIpermute(prhs[0], prhs[1]);
}


inline mwArray iscell(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfIscell(prhs[0]);
}


inline mwArray iscellstr(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfIscellstr(prhs[0]);
}


inline mwArray isfield(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfIsfield(prhs[0], prhs[1]);
}


inline mwArray ishold(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfIshold(prhs[0]);
}


inline mwArray isieee()
{
	return mlfIsieee();
}


inline void Vismembc(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIsmembc(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray ismembc(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIsmembc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray ismembc(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIsmembc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nismembc(int nargout, mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIsmembc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray ismember(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfIsmember(prhs[0], prhs[1], prhs[2]);
}


inline mwArray isnumeric(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfIsnumeric(prhs[0]);
}


inline mwArray isobject(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfIsobject(prhs[0]);
}


inline mwArray ispc()
{
	return mlfIspc();
}


inline mwArray isprime(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfIsprime(prhs[0]);
}


inline mwArray isstruct(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfIsstruct(prhs[0]);
}


inline mwArray isunix()
{
	return mlfIsunix();
}


inline mwArray isvms()
{
	return mlfIsvms();
}


inline mwArray sparfun_private_iterapp(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwVarargin &in5=mwVarargin::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxSparfun_private_iterapp(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sparfun_private_iterchk(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSparfun_private_iterchk(NULL, NULL, prhs[0]);
}


inline mwArray sparfun_private_iterchk(mwArray *out1, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSparfun_private_iterchk(&plhs[1], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sparfun_private_iterchk(mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSparfun_private_iterchk(&plhs[1], &plhs[2], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray sparfun_private_itermsg(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	return mlfSparfun_private_itermsg(prhs[0], prhs[1], prhs[2], prhs[3], 
prhs[4], prhs[5], prhs[6]);
}


inline mwArray kron(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfKron(prhs[0], prhs[1]);
}


inline mwArray lcm(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfLcm(prhs[0], prhs[1]);
}


inline mwArray legendre(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfLegendre(prhs[0], prhs[1], prhs[2]);
}


inline mwArray lin2mu(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfLin2mu(prhs[0]);
}


inline mwArray linspace(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfLinspace(prhs[0], prhs[1], prhs[2]);
}


inline mwArray log10(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfLog10(prhs[0]);
}


inline void Vlogm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNLogm(0, NULL, prhs[0]);
}


inline mwArray logm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfLogm(NULL, prhs[0]);
}


inline mwArray logm(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfLogm(&plhs[1], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nlogm(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNLogm(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray logspace(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfLogspace(prhs[0], prhs[1], prhs[2]);
}


inline void Vlscov(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNLscov(0, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray lscov(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfLscov(NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray lscov(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfLscov(&plhs[1], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nlscov(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNLscov(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline void Vlsqnonneg(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	mlfNLsqnonneg(0, NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], 
prhs[3]);
}


inline mwArray lsqnonneg(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfLsqnonneg(NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1], 
prhs[2], prhs[3]);
}


inline mwArray lsqnonneg(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfLsqnonneg(&plhs[1], NULL, NULL, NULL, NULL, prhs[0], prhs[1], 
prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray lsqnonneg(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfLsqnonneg(&plhs[1], &plhs[2], NULL, NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray lsqnonneg(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfLsqnonneg(&plhs[1], &plhs[2], &plhs[3], NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray lsqnonneg(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfLsqnonneg(&plhs[1], &plhs[2], &plhs[3], &plhs[4], NULL, 
prhs[0], prhs[1], prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray lsqnonneg(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfLsqnonneg(&plhs[1], &plhs[2], &plhs[3], &plhs[4], &plhs[5], 
prhs[0], prhs[1], prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray Nlsqnonneg(int nargout, mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNLsqnonneg(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, 
nargout>3?&plhs[3]:(MatlabMatrix**)NULL, 
nargout>4?&plhs[4]:(MatlabMatrix**)NULL, 
nargout>5?&plhs[5]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2], prhs[3]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	        if (nlhs > 5) {
	          if (out5 != NULL) *out5 = plhs[5];
	        }
	      }
	    }
	  }
	}
	return plhs[0];
}

inline mwArray magic(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfMagic(prhs[0]);
}


inline mwArray mat2str(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfMat2str(prhs[0], prhs[1]);
}


inline void mbcharscalar(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfMbcharscalar(prhs[0]);
}


inline void mbcharvector(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfMbcharvector(prhs[0]);
}


inline void mbintscalar(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfMbintscalar(prhs[0]);
}


inline void mbintvector(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfMbintvector(prhs[0]);
}


inline void mbrealscalar(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfMbrealscalar(prhs[0]);
}


inline void mbrealvector(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfMbrealvector(prhs[0]);
}


inline mwArray mean(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfMean(prhs[0], prhs[1]);
}


inline mwArray median(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfMedian(prhs[0], prhs[1]);
}


inline void Vmeshgrid(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNMeshgrid(0, NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray meshgrid(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfMeshgrid(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray meshgrid(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfMeshgrid(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray meshgrid(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfMeshgrid(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nmeshgrid(int nargout, mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNMeshgrid(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray mkpp(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfMkpp(prhs[0], prhs[1], prhs[2]);
}


inline mwArray mod(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfMod(prhs[0], prhs[1]);
}


inline mwArray mpoles(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfMpoles(NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray mpoles(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfMpoles(&plhs[1], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray mu2lin(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfMu2lin(prhs[0]);
}


inline mwArray nargchk(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfNargchk(prhs[0], prhs[1], prhs[2]);
}


inline mwArray nargoutchk(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfNargoutchk(prhs[0], prhs[1], prhs[2]);
}


inline mwArray nchoosek(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNchoosek(prhs[0], prhs[1]);
}


inline mwArray nextpow2(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNextpow2(prhs[0]);
}


inline mwArray nnls(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfNnls(NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray nnls(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNnls(&plhs[1], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray nnz(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNnz(prhs[0]);
}


inline mwArray nonzeros(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNonzeros(prhs[0]);
}


inline mwArray normest(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNormest(NULL, prhs[0], prhs[1]);
}


inline mwArray normest(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNormest(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray normest1(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin 
&in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxNormest1(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray normest1(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin 
&in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxNormest1(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray normest1(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxNormest1(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray normest1(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwVarargin &in4=mwVarargin::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxNormest1(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray now()
{
	return mlfNow();
}


inline mwArray null(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNull(prhs[0], prhs[1]);
}


inline mwArray num2cell(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNum2cell(prhs[0], prhs[1]);
}


inline mwArray num2str(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNum2str(prhs[0], prhs[1]);
}


inline mwArray numjac(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwVarargin 
&in10=mwVarargin::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN, const mwArray 
&in40=mwArray::DIN, const mwArray &in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxNumjac(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray numjac(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwVarargin 
&in10=mwVarargin::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN, const mwArray 
&in40=mwArray::DIN, const mwArray &in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxNumjac(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray numjac(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwVarargin &in10=mwVarargin::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN, const mwArray 
&in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxNumjac(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray numjac(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwVarargin &in10=mwVarargin::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN, const mwArray 
&in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxNumjac(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray nzmax(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNzmax(prhs[0]);
}


inline mwArray Node113(int nargout, mwArray *out1, mwVarargout varargout, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+1);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxOde113(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	varargout.AssignOutputs(nlhs-2, plhs+2);
	return plhs[0];
}

inline mwArray Node15s(int nargout, mwArray *out1, mwVarargout varargout, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+1);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxOde15s(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	varargout.AssignOutputs(nlhs-2, plhs+2);
	return plhs[0];
}

inline mwArray Node23(int nargout, mwArray *out1, mwVarargout varargout, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+1);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxOde23(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	varargout.AssignOutputs(nlhs-2, plhs+2);
	return plhs[0];
}

inline mwArray Node23s(int nargout, mwArray *out1, mwVarargout varargout, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+1);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxOde23s(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	varargout.AssignOutputs(nlhs-2, plhs+2);
	return plhs[0];
}

inline mwArray Node45(int nargout, mwArray *out1, mwVarargout varargout, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwVarargin 
&in5=mwVarargin::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN)
{
	mwVarargin varargin(in5, in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+1);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(4 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        varargin.GetArrayBuffer(prhs + 4);
	        nrhs += varargin.Size();
	      }
	    }
	  }
	}
	mlxOde45(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	varargout.AssignOutputs(nlhs-2, plhs+2);
	return plhs[0];
}

inline mwArray funfun_private_odearguments(const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_odearguments(NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
}


inline mwArray funfun_private_odearguments(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[7];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], 
prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[8];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], NULL, NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], 
prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[9];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], NULL, NULL, NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], 
prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *plhs[10];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], NULL, NULL, NULL, 
NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *plhs[11];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], NULL, 
NULL, NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, mwArray *out11, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[12];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], 
&plhs[11], NULL, NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], 
prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	if (out11 != NULL) *out11 = plhs[11];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, mwArray *out11, mwArray *out12, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[13];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], 
&plhs[11], &plhs[12], NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], 
prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	if (out11 != NULL) *out11 = plhs[11];
	if (out12 != NULL) *out12 = plhs[12];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, mwArray *out11, mwArray *out12, mwArray 
*out13, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[14];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], 
&plhs[11], &plhs[12], &plhs[13], NULL, NULL, NULL, NULL, prhs[0], prhs[1], 
prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	if (out11 != NULL) *out11 = plhs[11];
	if (out12 != NULL) *out12 = plhs[12];
	if (out13 != NULL) *out13 = plhs[13];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, mwArray *out11, mwArray *out12, mwArray 
*out13, mwArray *out14, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *plhs[15];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], 
&plhs[11], &plhs[12], &plhs[13], &plhs[14], NULL, NULL, NULL, prhs[0], prhs[1], 
prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	if (out11 != NULL) *out11 = plhs[11];
	if (out12 != NULL) *out12 = plhs[12];
	if (out13 != NULL) *out13 = plhs[13];
	if (out14 != NULL) *out14 = plhs[14];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, mwArray *out11, mwArray *out12, mwArray 
*out13, mwArray *out14, mwArray *out15, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN)
{
	MatlabMatrix *plhs[16];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], 
&plhs[11], &plhs[12], &plhs[13], &plhs[14], &plhs[15], NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	if (out11 != NULL) *out11 = plhs[11];
	if (out12 != NULL) *out12 = plhs[12];
	if (out13 != NULL) *out13 = plhs[13];
	if (out14 != NULL) *out14 = plhs[14];
	if (out15 != NULL) *out15 = plhs[15];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, mwArray *out11, mwArray *out12, mwArray 
*out13, mwArray *out14, mwArray *out15, mwArray *out16, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[17];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], 
&plhs[11], &plhs[12], &plhs[13], &plhs[14], &plhs[15], &plhs[16], NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	if (out11 != NULL) *out11 = plhs[11];
	if (out12 != NULL) *out12 = plhs[12];
	if (out13 != NULL) *out13 = plhs[13];
	if (out14 != NULL) *out14 = plhs[14];
	if (out15 != NULL) *out15 = plhs[15];
	if (out16 != NULL) *out16 = plhs[16];
	return plhs[0];
}


inline mwArray funfun_private_odearguments(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, mwArray *out7, mwArray 
*out8, mwArray *out9, mwArray *out10, mwArray *out11, mwArray *out12, mwArray 
*out13, mwArray *out14, mwArray *out15, mwArray *out16, mwArray *out17, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN)
{
	MatlabMatrix *plhs[18];
	MatlabMatrix *prhs[7];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odearguments(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], &plhs[7], &plhs[8], &plhs[9], &plhs[10], 
&plhs[11], &plhs[12], &plhs[13], &plhs[14], &plhs[15], &plhs[16], &plhs[17], 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5], prhs[6]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	if (out7 != NULL) *out7 = plhs[7];
	if (out8 != NULL) *out8 = plhs[8];
	if (out9 != NULL) *out9 = plhs[9];
	if (out10 != NULL) *out10 = plhs[10];
	if (out11 != NULL) *out11 = plhs[11];
	if (out12 != NULL) *out12 = plhs[12];
	if (out13 != NULL) *out13 = plhs[13];
	if (out14 != NULL) *out14 = plhs[14];
	if (out15 != NULL) *out15 = plhs[15];
	if (out16 != NULL) *out16 = plhs[16];
	if (out17 != NULL) *out17 = plhs[17];
	return plhs[0];
}


inline mwArray funfun_private_odeevents(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_odeevents(NULL, NULL, NULL, NULL, NULL, NULL, 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
}


inline mwArray funfun_private_odeevents(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odeevents(&plhs[1], NULL, NULL, NULL, NULL, 
NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_odeevents(mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odeevents(&plhs[1], &plhs[2], NULL, NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray funfun_private_odeevents(mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odeevents(&plhs[1], &plhs[2], &plhs[3], NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray funfun_private_odeevents(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odeevents(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray funfun_private_odeevents(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odeevents(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray funfun_private_odeevents(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[7];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odeevents(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	return plhs[0];
}


inline mwArray odeget(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfOdeget(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray funfun_private_odejacobian(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_odejacobian(NULL, NULL, NULL, NULL, NULL, NULL, 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
}


inline mwArray funfun_private_odejacobian(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odejacobian(&plhs[1], NULL, NULL, NULL, NULL, 
NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_odejacobian(mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odejacobian(&plhs[1], &plhs[2], NULL, NULL, 
NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray funfun_private_odejacobian(mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odejacobian(&plhs[1], &plhs[2], &plhs[3], 
NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray funfun_private_odejacobian(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odejacobian(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], NULL, NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray funfun_private_odejacobian(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odejacobian(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray funfun_private_odejacobian(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, mwArray *out6, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[7];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odejacobian(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], &plhs[6], prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], 
prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	if (out6 != NULL) *out6 = plhs[6];
	return plhs[0];
}


inline mwArray funfun_private_odemass(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_odemass(NULL, NULL, NULL, NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
}


inline mwArray funfun_private_odemass(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odemass(&plhs[1], NULL, NULL, NULL, NULL, 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_odemass(mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odemass(&plhs[1], &plhs[2], NULL, NULL, NULL, 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray funfun_private_odemass(mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odemass(&plhs[1], &plhs[2], &plhs[3], NULL, 
NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray funfun_private_odemass(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odemass(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], NULL, prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray funfun_private_odemass(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[6];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odemass(&plhs[1], &plhs[2], &plhs[3], 
&plhs[4], &plhs[5], prhs[0], prhs[1], prhs[2], prhs[3], prhs[4], prhs[5]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


inline mwArray funfun_private_odemassexplicit(const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN)
{
	MatlabMatrix *prhs[8];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_odemassexplicit(NULL, prhs[0], prhs[1], prhs[2], 
prhs[3], prhs[4], prhs[5], prhs[6], prhs[7]);
}


inline mwArray funfun_private_odemassexplicit(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[8];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	prhs[5] = (!in6.IsDIN())?in6.GetData():(MatlabMatrix*)(NULL);
	prhs[6] = (!in7.IsDIN())?in7.GetData():(MatlabMatrix*)(NULL);
	prhs[7] = (!in8.IsDIN())?in8.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfFunfun_private_odemassexplicit(&plhs[1], prhs[0], prhs[1], 
prhs[2], prhs[3], prhs[4], prhs[5], prhs[6], prhs[7]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_odemxv(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	return mlfFunfun_private_odemxv(prhs[0], prhs[1], prhs[2], prhs[3], 
prhs[4]);
}


inline mwArray odeplot(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwVarargin 
&in4=mwVarargin::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN)
{
	mwVarargin varargin(in4, in5, in6, in7, in8, in9, in10, in11, in12, in13, 
in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, 
in27, in28, in29, in30, in31, in32, in33, in34, in35);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(3 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      varargin.GetArrayBuffer(prhs + 3);
	      nrhs += varargin.Size();
	    }
	  }
	}
	mlxOdeplot(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vodeset(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxOdeset(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray odeset(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxOdeset(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Nodeset(int nargout, const mwVarargin &in1=mwVarargin::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxOdeset(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray funfun_private_odezero(const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwVarargin 
&in10=mwVarargin::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN, const mwArray 
&in40=mwArray::DIN, const mwArray &in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxFunfun_private_odezero(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray funfun_private_odezero(mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwVarargin &in10=mwVarargin::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN, const mwArray 
&in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxFunfun_private_odezero(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray funfun_private_odezero(mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwVarargin &in10=mwVarargin::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN, const mwArray 
&in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxFunfun_private_odezero(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray funfun_private_odezero(mwArray *out1, mwArray *out2, mwArray 
*out3, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwVarargin &in10=mwVarargin::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN, const mwArray &in40=mwArray::DIN, const mwArray 
&in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxFunfun_private_odezero(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray funfun_private_odezero(mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwVarargin 
&in10=mwVarargin::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN, const mwArray 
&in40=mwArray::DIN, const mwArray &in41=mwArray::DIN)
{
	mwVarargin varargin(in10, in11, in12, in13, in14, in15, in16, in17, in18, 
in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, in30, in31, 
in32, in33, in34, in35, in36, in37, in38, in39, in40, in41);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	      if (out4 != NULL) {
	        plhs[nlhs++]=NULL;
	      }
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(9 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              if (!in8.IsDIN()) {
	                prhs[nrhs++] = in8.GetData();
	                if (!in9.IsDIN()) {
	                  prhs[nrhs++] = in9.GetData();
	                  varargin.GetArrayBuffer(prhs + 9);
	                  nrhs += varargin.Size();
	                }
	              }
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxFunfun_private_odezero(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray optimget(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfOptimget(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline void Voptimset(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxOptimset(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray optimset(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxOptimset(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Noptimset(int nargout, const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxOptimset(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray orth(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfOrth(prhs[0]);
}


inline mwArray pascal(const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfPascal(prhs[0], prhs[1]);
}


inline void Vpcg(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxPcg(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray pcg(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxPcg(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray pcg(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxPcg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray pcg(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxPcg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray pcg(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxPcg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray pcg(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, 
const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	      if (out4 != NULL) {
	        plhs[nlhs++]=NULL;
	      }
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxPcg(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray Npcg(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxPcg(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	      }
	    }
	  }
	}
	return plhs[0];
}

inline mwArray pchip(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfPchip(prhs[0], prhs[1], prhs[2]);
}


inline mwArray perms(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfPerms(prhs[0]);
}


inline mwArray pinv(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfPinv(prhs[0], prhs[1]);
}


inline mwArray planerot(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfPlanerot(NULL, prhs[0]);
}


inline mwArray planerot(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPlanerot(&plhs[1], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray pol2cart(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfPol2cart(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray pol2cart(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPol2cart(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray pol2cart(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPol2cart(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray poly(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfPoly(prhs[0]);
}


inline mwArray polyarea(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfPolyarea(prhs[0], prhs[1], prhs[2]);
}


inline void Vpolyder(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNPolyder(0, NULL, prhs[0], prhs[1]);
}


inline mwArray polyder(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfPolyder(NULL, prhs[0], prhs[1]);
}


inline mwArray polyder(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPolyder(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Npolyder(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNPolyder(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline void Vpolyeig(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyeig(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray polyeig(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyeig(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray polyeig(mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyeig(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Npolyeig(int nargout, mwArray *out1, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyeig(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline void Vpolyfit(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNPolyfit(0, NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray polyfit(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfPolyfit(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray polyfit(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPolyfit(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray polyfit(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPolyfit(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Npolyfit(int nargout, mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNPolyfit(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline void Vpolyval(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	mlfNPolyval(0, NULL, prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray polyval(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfPolyval(NULL, prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray polyval(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfPolyval(&plhs[1], prhs[0], prhs[1], prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Npolyval(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNPolyval(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1], prhs[2], prhs[3]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray polyvalm(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfPolyvalm(prhs[0], prhs[1]);
}


inline mwArray ppval(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfPpval(prhs[0], prhs[1]);
}


inline mwArray primes(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfPrimes(prhs[0]);
}


inline mwArray pwd()
{
	return mlfPwd();
}


inline void Vpolyfun_private_qhullmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_qhullmx(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray polyfun_private_qhullmx(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_qhullmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray polyfun_private_qhullmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_qhullmx(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Npolyfun_private_qhullmx(int nargout, mwVarargout varargout, 
const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_qhullmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Vqmr(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxQmr(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray qmr(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxQmr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray qmr(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwVarargin 
&in8=mwVarargin::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN, const mwArray 
&in38=mwArray::DIN, const mwArray &in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxQmr(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray qmr(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxQmr(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray qmr(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxQmr(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray qmr(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, 
const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	      if (out4 != NULL) {
	        plhs[nlhs++]=NULL;
	      }
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxQmr(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray Nqmr(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwVarargin &in8=mwVarargin::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN, const mwArray 
&in33=mwArray::DIN, const mwArray &in34=mwArray::DIN, const mwArray 
&in35=mwArray::DIN, const mwArray &in36=mwArray::DIN, const mwArray 
&in37=mwArray::DIN, const mwArray &in38=mwArray::DIN, const mwArray 
&in39=mwArray::DIN)
{
	mwVarargin varargin(in8, in9, in10, in11, in12, in13, in14, in15, in16, 
in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, in28, in29, 
in30, in31, in32, in33, in34, in35, in36, in37, in38, in39);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[5];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(7 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          if (!in6.IsDIN()) {
	            prhs[nrhs++] = in6.GetData();
	            if (!in7.IsDIN()) {
	              prhs[nrhs++] = in7.GetData();
	              varargin.GetArrayBuffer(prhs + 7);
	              nrhs += varargin.Size();
	            }
	          }
	        }
	      }
	    }
	  }
	}
	mlxQmr(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	      }
	    }
	  }
	}
	return plhs[0];
}

inline mwArray qrdelete(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfQrdelete(NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray qrdelete(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfQrdelete(&plhs[1], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray qrinsert(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfQrinsert(NULL, prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray qrinsert(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfQrinsert(&plhs[1], prhs[0], prhs[1], prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray quad_func(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwVarargin 
&in6=mwVarargin::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN)
{
	mwVarargin varargin(in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36, in37);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(5 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          varargin.GetArrayBuffer(prhs + 5);
	          nrhs += varargin.Size();
	        }
	      }
	    }
	  }
	}
	mlxQuad(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray quad_func(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwVarargin 
&in6=mwVarargin::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN)
{
	mwVarargin varargin(in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36, in37);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(5 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          varargin.GetArrayBuffer(prhs + 5);
	          nrhs += varargin.Size();
	        }
	      }
	    }
	  }
	}
	mlxQuad(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray quad8(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwVarargin 
&in6=mwVarargin::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN)
{
	mwVarargin varargin(in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36, in37);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(5 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          varargin.GetArrayBuffer(prhs + 5);
	          nrhs += varargin.Size();
	        }
	      }
	    }
	  }
	}
	mlxQuad8(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray quad8(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwVarargin 
&in6=mwVarargin::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN, const mwArray 
&in34=mwArray::DIN, const mwArray &in35=mwArray::DIN, const mwArray 
&in36=mwArray::DIN, const mwArray &in37=mwArray::DIN)
{
	mwVarargin varargin(in6, in7, in8, in9, in10, in11, in12, in13, in14, 
in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, in25, in26, in27, 
in28, in29, in30, in31, in32, in33, in34, in35, in36, in37);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(5 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	        if (!in5.IsDIN()) {
	          prhs[nrhs++] = in5.GetData();
	          varargin.GetArrayBuffer(prhs + 5);
	          nrhs += varargin.Size();
	        }
	      }
	    }
	  }
	}
	mlxQuad8(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray randperm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfRandperm(prhs[0]);
}


inline mwArray rank(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRank(prhs[0], prhs[1]);
}


inline void Vrat(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNRat(0, NULL, prhs[0], prhs[1]);
}


inline mwArray rat(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRat(NULL, prhs[0], prhs[1]);
}


inline mwArray rat(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfRat(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nrat(int nargout, mwArray *out1, const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNRat(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray rats(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRats(prhs[0], prhs[1]);
}


inline mwArray reallog(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfReallog(prhs[0]);
}


inline mwArray realmax()
{
	return mlfRealmax();
}


inline mwArray realmin()
{
	return mlfRealmin();
}


inline mwArray realpow(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRealpow(prhs[0], prhs[1]);
}


inline mwArray realsqrt(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfRealsqrt(prhs[0]);
}


inline mwArray rectint(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRectint(prhs[0], prhs[1]);
}


inline void refresh(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfRefresh(prhs[0]);
}


inline mwArray repmat(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfRepmat(prhs[0], prhs[1], prhs[2]);
}


inline mwArray resi2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	return mlfResi2(prhs[0], prhs[1], prhs[2], prhs[3], prhs[4]);
}


inline mwArray residue(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfResidue(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray residue(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfResidue(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray residue(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfResidue(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray rjr(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRjr(prhs[0], prhs[1]);
}


inline mwArray rmfield(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRmfield(prhs[0], prhs[1]);
}


inline mwArray roots(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfRoots(prhs[0]);
}


inline mwArray rosser()
{
	return mlfRosser();
}


inline mwArray rot90(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRot90(prhs[0], prhs[1]);
}


inline mwArray rref(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRref(NULL, prhs[0], prhs[1]);
}


inline mwArray rref(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfRref(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray rsf2csf(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfRsf2csf(NULL, prhs[0], prhs[1]);
}


inline mwArray rsf2csf(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfRsf2csf(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sec(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSec(prhs[0]);
}


inline mwArray sech(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSech(prhs[0]);
}


inline mwArray setdiff(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfSetdiff(NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray setdiff(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSetdiff(&plhs[1], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray setfield(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxSetfield(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vsetxor(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNSetxor(0, NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray setxor(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfSetxor(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray setxor(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSetxor(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray setxor(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSetxor(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nsetxor(int nargout, mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNSetxor(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray shiftdim(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfShiftdim(NULL, prhs[0], prhs[1]);
}


inline mwArray shiftdim(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfShiftdim(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sortrows(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfSortrows(NULL, prhs[0], prhs[1]);
}


inline mwArray sortrows(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSortrows(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray spalloc(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfSpalloc(prhs[0], prhs[1], prhs[2]);
}


inline mwArray spaugment(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfSpaugment(prhs[0], prhs[1]);
}


inline mwArray spconvert(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSpconvert(prhs[0]);
}


inline mwArray spdiags(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfSpdiags(NULL, prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray spdiags(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSpdiags(&plhs[1], prhs[0], prhs[1], prhs[2], prhs[3]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray speye(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfSpeye(prhs[0], prhs[1]);
}


inline mwArray spfun(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfSpfun(prhs[0], prhs[1]);
}


inline mwArray sph2cart(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfSph2cart(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray sph2cart(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSph2cart(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sph2cart(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSph2cart(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray spline(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfSpline(prhs[0], prhs[1], prhs[2]);
}


inline mwArray splncore(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfSplncore(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray spones(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSpones(prhs[0]);
}


inline void Vspparms(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNSpparms(0, NULL, prhs[0], prhs[1]);
}


inline mwArray spparms(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfSpparms(NULL, prhs[0], prhs[1]);
}


inline mwArray spparms(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSpparms(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nspparms(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNSpparms(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray sprand(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfSprand(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray sprandn(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfSprandn(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline mwArray sprandsym(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	MatlabMatrix *prhs[4];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	return mlfSprandsym(prhs[0], prhs[1], prhs[2], prhs[3]);
}


inline void Vsqrtm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	mlfNSqrtm(0, NULL, NULL, prhs[0]);
}


inline mwArray sqrtm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSqrtm(NULL, NULL, prhs[0]);
}


inline mwArray sqrtm(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSqrtm(&plhs[1], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sqrtm(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSqrtm(&plhs[1], &plhs[2], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nsqrtm(int nargout, mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNSqrtm(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray std_func(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfStd(prhs[0], prhs[1], prhs[2]);
}


inline mwArray str2double(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfStr2double(prhs[0]);
}


inline mwArray str2mat(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxStr2mat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray str2num(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfStr2num(prhs[0]);
}


inline mwArray strcat(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxStrcat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray strjust(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfStrjust(prhs[0], prhs[1]);
}


inline mwArray strmatch(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfStrmatch(prhs[0], prhs[1], prhs[2]);
}


inline void Vstrtok(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNStrtok(0, NULL, prhs[0], prhs[1]);
}


inline mwArray strtok(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfStrtok(NULL, prhs[0], prhs[1]);
}


inline mwArray strtok(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfStrtok(&plhs[1], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nstrtok(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNStrtok(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray strvcat(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxStrvcat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sub2ind(const mwArray &in1=mwArray::DIN, const mwVarargin 
&in2=mwVarargin::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN, const mwArray &in33=mwArray::DIN)
{
	mwVarargin varargin(in2, in3, in4, in5, in6, in7, in8, in9, in10, in11, 
in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, in24, 
in25, in26, in27, in28, in29, in30, in31, in32, in33);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxSub2ind(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray subspace(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfSubspace(prhs[0], prhs[1]);
}


inline void Vsvds(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSvds(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray svds(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSvds(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray svds(mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSvds(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray svds(mwArray *out1, mwArray *out2, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSvds(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray svds(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSvds(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray Nsvds(int nargout, mwArray *out1, mwArray *out2, mwArray *out3, 
const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSvds(nlhs, plhs, nrhs, prhs);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	    }
	  }
	}
	return plhs[0];
}

inline void Vsymbfact(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNSymbfact(0, NULL, NULL, NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray symbfact(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfSymbfact(NULL, NULL, NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray symbfact(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSymbfact(&plhs[1], NULL, NULL, NULL, prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray symbfact(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSymbfact(&plhs[1], &plhs[2], NULL, NULL, prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray symbfact(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSymbfact(&plhs[1], &plhs[2], &plhs[3], NULL, prhs[0], 
prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray symbfact(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfSymbfact(&plhs[1], &plhs[2], &plhs[3], &plhs[4], prhs[0], 
prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray Nsymbfact(int nargout, mwArray *out1, mwArray *out2, mwArray 
*out3, mwArray *out4, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNSymbfact(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, 
nargout>3?&plhs[3]:(MatlabMatrix**)NULL, 
nargout>4?&plhs[4]:(MatlabMatrix**)NULL, prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	    if (nlhs > 3) {
	      if (out3 != NULL) *out3 = plhs[3];
	      if (nlhs > 4) {
	        if (out4 != NULL) *out4 = plhs[4];
	      }
	    }
	  }
	}
	return plhs[0];
}

inline mwArray symmmd(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSymmmd(prhs[0]);
}


inline mwArray symrcm(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfSymrcm(prhs[0]);
}


inline mwArray table1(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfTable1(prhs[0], prhs[1]);
}


inline mwArray table2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfTable2(prhs[0], prhs[1], prhs[2]);
}


inline mwArray tempdir()
{
	return mlfTempdir();
}


inline mwArray tempname()
{
	return mlfTempname();
}


inline void tic()
{
	mlfTic();
}


inline void Vtoc()
{
	mlfNToc(0);
}


inline mwArray toc()
{
	return mlfToc();
}


inline mwArray Ntoc(int nargout)
{
	return mlfNToc(nargout);
}

inline mwArray toeplitz(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfToeplitz(prhs[0], prhs[1]);
}


inline mwArray trace(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfTrace(prhs[0]);
}


inline mwArray trapz(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfTrapz(prhs[0], prhs[1], prhs[2]);
}


inline mwArray tsearch(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	return mlfTsearch(prhs[0], prhs[1], prhs[2], prhs[3], prhs[4]);
}


inline void Vpolyfun_private_tsrchmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_tsrchmx(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray polyfun_private_tsrchmx(mwVarargout varargout, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_tsrchmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray polyfun_private_tsrchmx(const mwVarargin &in1=mwVarargin::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_tsrchmx(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Npolyfun_private_tsrchmx(int nargout, mwVarargout varargout, 
const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = nargout + varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPolyfun_private_tsrchmx(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline void Vunion_func(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNUnion(0, NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray union_func(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfUnion(NULL, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray union_func(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnion(&plhs[1], NULL, prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray union_func(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnion(&plhs[1], &plhs[2], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nunion_func(int nargout, mwArray *out1, mwArray *out2, const 
mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNUnion(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline void Vunique(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	mlfNUnique(0, NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray unique(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfUnique(NULL, NULL, prhs[0], prhs[1]);
}


inline mwArray unique(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnique(&plhs[1], NULL, prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray unique(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnique(&plhs[1], &plhs[2], prhs[0], prhs[1]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray Nunique(int nargout, mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNUnique(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
nargout>2?&plhs[2]:(MatlabMatrix**)NULL, prhs[0], prhs[1]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	  if (nlhs > 2) {
	    if (out2 != NULL) *out2 = plhs[2];
	  }
	}
	return plhs[0];
}

inline mwArray unmkpp(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfUnmkpp(NULL, NULL, NULL, NULL, prhs[0]);
}


inline mwArray unmkpp(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnmkpp(&plhs[1], NULL, NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray unmkpp(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnmkpp(&plhs[1], &plhs[2], NULL, NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray unmkpp(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnmkpp(&plhs[1], &plhs[2], &plhs[3], NULL, prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray unmkpp(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfUnmkpp(&plhs[1], &plhs[2], &plhs[3], &plhs[4], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray unwrap(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfUnwrap(prhs[0], prhs[1], prhs[2]);
}


inline mwArray usejava(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfUsejava(prhs[0]);
}


inline mwArray vander(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfVander(prhs[0]);
}


inline mwArray vectorize(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfVectorize(prhs[0]);
}


inline void Vview(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	mlfNView(0, NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray view(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	return mlfView(NULL, prhs[0], prhs[1], prhs[2]);
}


inline mwArray view(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfView(&plhs[1], prhs[0], prhs[1], prhs[2]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nview(int nargout, mwArray *out1, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[3];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNView(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0], prhs[1], prhs[2]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray weekday(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfWeekday(NULL, prhs[0]);
}


inline mwArray weekday(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfWeekday(&plhs[1], prhs[0]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray wilkinson(const mwArray &in1=mwArray::DIN)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfWilkinson(prhs[0]);
}


inline mwArray xor_func(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfXor(prhs[0], prhs[1]);
}


inline mwArray xychk(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxXychk(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray xychk(mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray 
&in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray 
&in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray 
&in12=mwArray::DIN, const mwArray &in13=mwArray::DIN, const mwArray 
&in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray 
&in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray 
&in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray 
&in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray 
&in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray 
&in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray 
&in26=mwArray::DIN, const mwArray &in27=mwArray::DIN, const mwArray 
&in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray 
&in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray 
&in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxXychk(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray xychk(mwArray *out1, mwArray *out2, const mwVarargin 
&in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[3];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxXychk(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray xychk(mwArray *out1, mwArray *out2, mwArray *out3, const 
mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray 
&in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray 
&in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray 
&in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray 
&in13=mwArray::DIN, const mwArray &in14=mwArray::DIN, const mwArray 
&in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray 
&in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray 
&in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray 
&in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray 
&in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray 
&in25=mwArray::DIN, const mwArray &in26=mwArray::DIN, const mwArray 
&in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray 
&in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray 
&in31=mwArray::DIN, const mwArray &in32=mwArray::DIN)
{
	mwVarargin varargin(in1, in2, in3, in4, in5, in6, in7, in8, in9, in10, 
in11, in12, in13, in14, in15, in16, in17, in18, in19, in20, in21, in22, in23, 
in24, in25, in26, in27, in28, in29, in30, in31, in32);
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[4];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	  if (out2 != NULL) {
	    plhs[nlhs++]=NULL;
	    if (out3 != NULL) {
	      plhs[nlhs++]=NULL;
	    }
	  }
	}
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxXychk(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray xyzchk(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	return mlfXyzchk(NULL, NULL, NULL, NULL, NULL, prhs[0], prhs[1], prhs[2], 
prhs[3], prhs[4]);
}


inline mwArray xyzchk(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfXyzchk(&plhs[1], NULL, NULL, NULL, NULL, prhs[0], prhs[1], 
prhs[2], prhs[3], prhs[4]);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray xyzchk(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN)
{
	MatlabMatrix *plhs[3];
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfXyzchk(&plhs[1], &plhs[2], NULL, NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray xyzchk(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN)
{
	MatlabMatrix *plhs[4];
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfXyzchk(&plhs[1], &plhs[2], &plhs[3], NULL, NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray xyzchk(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN)
{
	MatlabMatrix *plhs[5];
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfXyzchk(&plhs[1], &plhs[2], &plhs[3], &plhs[4], NULL, prhs[0], 
prhs[1], prhs[2], prhs[3], prhs[4]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline mwArray xyzchk(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, mwArray *out5, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	MatlabMatrix *plhs[6];
	MatlabMatrix *prhs[5];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	prhs[2] = (!in3.IsDIN())?in3.GetData():(MatlabMatrix*)(NULL);
	prhs[3] = (!in4.IsDIN())?in4.GetData():(MatlabMatrix*)(NULL);
	prhs[4] = (!in5.IsDIN())?in5.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfXyzchk(&plhs[1], &plhs[2], &plhs[3], &plhs[4], &plhs[5], 
prhs[0], prhs[1], prhs[2], prhs[3], prhs[4]);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	if (out5 != NULL) *out5 = plhs[5];
	return plhs[0];
}


#endif /* __mltif_h__ */
