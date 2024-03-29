#ifndef __mlmif_h__
#define __mlmif_h__ 1

inline mwArray _colonobj(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlx_colonobj(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray _license_checkout(mwVarargout varargout, const mwVarargin &in1, 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlx_license_checkout(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray _license_checkout(const mwVarargin &in1, const mwArray 
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
	mlx_license_checkout(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline void _system(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlx_system(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray abs(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxAbs(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray acos(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxAcos(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray acosh(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxAcosh(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void add_block(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxAdd_block(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void add_line(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxAdd_line(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray all(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxAll(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray and_func(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxAnd(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray any(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxAny(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray applescript(mwVarargout varargout, const mwVarargin &in1, const 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxApplescript(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray applescript(const mwVarargin &in1, const mwArray 
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
	mlxApplescript(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray asin(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxAsin(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray asinh(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxAsinh(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray assignin(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxAssignin(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray atan(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxAtan(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray atanh(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxAtanh(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray atan2(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxAtan2(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray balance(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxBalance(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray balance(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxBalance(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray beep(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxBeep(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bitand_func(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxBitand(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bitcmp(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxBitcmp(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bitget(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxBitget(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bitset(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxBitset(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bitshift(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxBitshift(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bitor_func(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxBitor(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray bitxor(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxBitxor(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray builtin(mwVarargout varargout, const mwVarargin 
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
	mlxBuiltin(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray builtin(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxBuiltin(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray callstats(mwVarargout varargout, const mwVarargin &in1, const 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxCallstats(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray callstats(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxCallstats(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray cat(const mwArray &in1=mwArray::DIN, const mwVarargin 
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
	mlxCat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vcd(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxCd(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray cd(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxCd(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Ncd(int nargout, const mwArray &in1)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNCd(nargout, prhs[0]);
}

inline mwArray ceil(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxCeil(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cell(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxCell(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cell2struct(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxCell2struct(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cellhorzcat(const mwVarargin &in1, const mwArray 
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
	mlxCellhorzcat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray char_func(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxChar(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray chdir(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxChdir(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray chol(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxChol(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray chol(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxChol(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray cholinc(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxCholinc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cholinc(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxCholinc(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray cholupdate(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxCholupdate(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cholupdate(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxCholupdate(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray classname(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxClassName(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void clc()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxClc(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray clock_func()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxClock(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void close_system(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxClose_system(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray colon(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxColon(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray computer()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxComputer(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray computer(mwArray *out1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1]={0};
	mlxComputer(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray conj(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxConj(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray conv2(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxConv2(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cos(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxCos(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ctranspose(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxCtranspose(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cosh(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxCosh(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cumprod(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxCumprod(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cumsum(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxCumsum(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray cputime()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxCputime(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void dbclear(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDbclear(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void dbcont()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxDbcont(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void dbdown()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxDbdown(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void dbquit()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxDbquit(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray dbstack()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxDbstack(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray dbstack(mwArray *out1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1]={0};
	mlxDbstack(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray dbstatus(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDbstatus(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void dbstep(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDbstep(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void dbstop(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDbstop(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void dbtype(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDbtype(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void dbup()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxDbup(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void delete_func(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxDelete(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void delete_block(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDelete_block(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void delete_line(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxDelete_line(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray det(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDet(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray diag(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxDiag(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void diary(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDiary(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray diff(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxDiff(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vdir(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDir(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray dir(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDir(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Ndir(int nargout, const mwArray &in1)
{
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	return mlfNDir(nargout, prhs[0]);
}

inline void disp(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDisp(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray dongarra(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDongarra(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray double_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxDouble(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray dos(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxDos(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray dos(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxDos(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void echo(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxEcho(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray edt(mwVarargout varargout, const mwVarargin &in1, const mwArray 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxEdt(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray edt(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const 
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
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxEdt(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray end(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxEnd(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray eig(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxEig(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray eig(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxEig(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray eps()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxEps(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray eq(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxEq(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void error(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxError(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray errorstat()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxErrorstat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void errortrap(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxErrortrap(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray eval(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
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
	mlxEval(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray eval(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxEval(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray evalc(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
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
	mlxEvalc(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray evalc(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxEvalc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline void Vevalin(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxEvalin(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray evalin(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
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
	mlxEvalin(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray evalin(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxEvalin(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nevalin(int nargout, mwVarargout varargout, const mwArray 
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
	mlxEvalin(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray exist(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxExist(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void exit()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxExit(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray exp(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxExp(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray expm(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxExpm(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray eye(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxEye(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fclose(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFclose(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void Vfeature(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFeature(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray feature(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFeature(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Nfeature(int nargout, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	MatlabMatrix *prhs[2];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	prhs[1] = (!in2.IsDIN())?in2.GetData():(MatlabMatrix*)(NULL);
	return mlfNFeature(nargout, prhs[0], prhs[1]);
}

inline mwArray fieldnames(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFieldnames(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fields(mwVarargout varargout, const mwVarargin &in1, const 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxFields(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray fields(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxFields(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray feof(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFeof(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ferror(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFerror(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ferror(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxFerror(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray feval(mwVarargout varargout, const mwVarargin 
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
	mlxFeval(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray feval(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxFeval(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray fft(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxFft(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fftn(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFftn(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fftw(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFftw(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fgets(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFgets(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fgets(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxFgets(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray filter(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[5];
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
	        }
	      }
	    }
	  }
	}
	mlxFilter(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray filter(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[5];
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
	        }
	      }
	    }
	  }
	}
	mlxFilter(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray find(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFind(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray find(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFind(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray find(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN)
{
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
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFind(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray find_system(mwVarargout varargout, const mwVarargin 
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
	mlxFind_system(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray find_system(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxFind_system(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray findstr(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFindstr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray finite(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFinite(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fix(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFix(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray floor(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFloor(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray flops(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFlops(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void format(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxFormat(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray fopen(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxFopen(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fopen(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxFopen(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray fopen(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
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
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxFopen(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline void Vfprintf(const mwArray &in1=mwArray::DIN, const mwVarargin 
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
	mlxFprintf(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray fprintf(const mwArray &in1=mwArray::DIN, const mwVarargin 
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
	mlxFprintf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Nfprintf(int nargout, const mwArray &in1=mwArray::DIN, const 
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
	int nlhs = nargout;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(1 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  varargin.GetArrayBuffer(prhs + 1);
	  nrhs += varargin.Size();
	}
	mlxFprintf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray fread(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxFread(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fread(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxFread(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray fschange(mwVarargout varargout, const mwVarargin &in1, const 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxFschange(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray fschange(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxFschange(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray fscanf(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxFscanf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray fscanf(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxFscanf(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray fseek(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxFseek(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ftell(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFtell(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray full(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFull(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray func2str(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFunc2str(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray functions(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxFunctions(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray functionscalled(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[5];
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
	        }
	      }
	    }
	  }
	}
	mlxFunctionscalled(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray functionscalled(mwArray *out1, const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[5];
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
	        }
	      }
	    }
	  }
	}
	mlxFunctionscalled(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray functionscalled(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
&in5=mwArray::DIN)
{
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
	MatlabMatrix *prhs[5];
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
	        }
	      }
	    }
	  }
	}
	mlxFunctionscalled(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray fwrite(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxFwrite(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ge(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxGe(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray get_param(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxGet_param(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray getenv(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxGetenv(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray gt(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxGt(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray hcreate(mwVarargout varargout, const mwVarargin &in1, const 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHcreate(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray hcreate(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHcreate(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray help(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxHelp(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void home()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxHome(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray hess(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxHess(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray hess(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxHess(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray horzcat(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHorzcat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray hregister(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxHregister(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray i()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxI(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray j()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxJ(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ifftn(const mwArray &in1, const mwArray &in2=mwArray::DIN)
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
	mlxIfftn(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ifft(const mwArray &in1, const mwArray &in2=mwArray::DIN, const 
mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxIfft(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray imag(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxImag(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray inf()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxInf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void inferiorto(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxInferiorto(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray inmem()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxInmem(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray inmem(mwArray *out1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1]={0};
	mlxInmem(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray input(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxInput(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray inputname(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxInputname(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray int8_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxInt8(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray int16_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxInt16(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray int32_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxInt32(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray inv(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxInv(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isa(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxIsa(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isequal(const mwArray &in1=mwArray::DIN, const mwVarargin 
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
	mlxIsequal(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isempty(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsempty(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isfinite(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsfinite(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isglobal(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsglobal(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isjava(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxIsjava(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray issparse(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIssparse(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ischar(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIschar(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray islogical(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIslogical(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isstr(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsstr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isstudent()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxIsstudent(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isinf(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsinf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isletter(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsletter(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isnan(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsnan(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isreal(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsreal(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isruntime()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxIsruntime(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray isspace(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxIsspace(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray java(mwVarargout varargout, const mwVarargin &in1, const mwArray 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxJava(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray java(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxJava(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray java_array(const mwVarargin &in1, const mwArray 
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
	mlxJava_array(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray java_method(const mwVarargin &in1, const mwArray 
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
	mlxJava_method(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray java_object(const mwVarargin &in1, const mwArray 
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
	mlxJava_object(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray javaArray(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxJavaArray(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray javaMethod(const mwVarargin &in1, const mwArray 
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
	mlxJavaMethod(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray javaObject(const mwVarargin &in1, const mwArray 
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
	mlxJavaObject(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void keyboard()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxKeyboard(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray lastwarn(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLastwarn(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray lasterr(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLasterr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray length(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLength(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ldivide(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxLdivide(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray le(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxLe(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray license()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxLicense(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray linmod(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxLinmod(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray linmod(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxLinmod(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray linmod(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
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
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxLinmod(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray linmod(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN, const mwArray &in4=mwArray::DIN)
{
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
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxLinmod(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray log(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLog(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray log2(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLog2(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray log2(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLog2(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray logical(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLogical(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void lookfor(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLookfor(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray lower(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxLower(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray lt(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxLt(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ltitr(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxLtitr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray lu(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxLu(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray lu(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxLu(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray lu(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN)
{
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
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxLu(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray luinc(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxLuinc(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray luinc(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxLuinc(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray luinc(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
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
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxLuinc(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray macprint(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxMacprint(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray mactools(mwVarargout varargout, const mwVarargin &in1, const 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxMactools(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray mactools(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxMactools(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline void Vmatlabpath(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxMatlabpath(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray matlabpath(mwVarargout varargout, const mwVarargin 
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
	mlxMatlabpath(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray matlabpath(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxMatlabpath(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray Nmatlabpath(int nargout, mwVarargout varargout, const mwVarargin 
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
	mlxMatlabpath(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}

inline mwArray matlabroot()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxMatlabroot(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void mbchar(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMbchar(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void mbint(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMbint(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void mbreal(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMbreal(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void mbscalar(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMbscalar(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void mbvector(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMbvector(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray methods(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMethods(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray mexext()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxMexext(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray mfilename()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxMfilename(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray mimofr(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[5];
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
	        }
	      }
	    }
	  }
	}
	mlxMimofr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray minus(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxMinus(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void mislocked(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMislocked(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void mlock()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxMlock(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray mldivide(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxMldivide(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray mpower(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxMpower(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray mrdivide(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxMrdivide(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray mtimes(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxMtimes(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray more(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMore(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void munlock(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxMunlock(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray nan()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxNan(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray nargin(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxNargin(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray nargout(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxNargout(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ndims(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxNdims(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ne(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxNe(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray neq(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxNeq(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void new_system(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxNew_system(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray norm(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxNorm(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray not_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxNot(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray numel(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxNumel(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray ones(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxOnes(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void open_system(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxOpen_system(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray or_func(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxOr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void pack()
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxPack(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void pause(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxPause(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline void pfile(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxPfile(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray permute(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxPermute(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray pi()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxPi(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray plus(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxPlus(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray pow2(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxPow2(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray prod(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxProd(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray power(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxPower(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray qr(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQr(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray qr(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQr(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray qr(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
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
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQr(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray qrupdate(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxQrupdate(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray qrupdate(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[4];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	      if (!in4.IsDIN()) {
	        prhs[nrhs++] = in4.GetData();
	      }
	    }
	  }
	}
	mlxQrupdate(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void quit(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxQuit(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray qz(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQz(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray qz(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQz(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray qz(mwArray *out1, mwArray *out2, const mwArray &in1=mwArray::DIN, 
const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
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
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQz(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray qz(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
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
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQz(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray qz(mwArray *out1, mwArray *out2, mwArray *out3, mwArray *out4, 
const mwArray &in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
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
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxQz(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}


inline void Vrand_func(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxRand(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray rand_func(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxRand(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Nrand_func(int nargout, const mwVarargin &in1=mwVarargin::DIN, 
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
	mlxRand(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline void Vrandn(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxRandn(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray randn(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxRandn(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray Nrandn(int nargout, const mwVarargin &in1=mwVarargin::DIN, const 
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
	mlxRandn(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray rcond(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxRcond(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray rdivide(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxRdivide(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray real(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxReal(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray rehash(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxRehash(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray rem(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxRem(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray reshape(const mwArray &in1=mwArray::DIN, const mwVarargin 
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
	mlxReshape(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray round(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxRound(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void runtime(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxRuntime(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray schur(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSchur(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray schur(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSchur(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void set_param(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSet_param(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray sign(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSign(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sim(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSim(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sim(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSim(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sim(mwArray *out1, mwArray *out2, const mwArray 
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
	mlxSim(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray simget(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSimget(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray simset(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSimset(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sin(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSin(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray single_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSingle(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sinh(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSinh(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray size(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
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
	mlxSize(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray size(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSize(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray size2d(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSize2d(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray size2d(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxSize2d(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void sldebug(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSldebug(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray sort(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSort(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sort(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxSort(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sparse(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray 
&in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray 
&in6=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[6];
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
	          }
	        }
	      }
	    }
	  }
	}
	mlxSparse(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sparsfun(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxSparsfun(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sparsfun(mwArray *out1, const mwVarargin &in1=mwVarargin::DIN, 
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
	mlxSparsfun(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sparsfun(mwArray *out1, mwArray *out2, const mwVarargin 
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
	mlxSparsfun(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray sparsfun(mwArray *out1, mwArray *out2, mwArray *out3, const 
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
	mlxSparsfun(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray sparsfun(mwArray *out1, mwArray *out2, mwArray *out3, mwArray 
*out4, const mwVarargin &in1=mwVarargin::DIN, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSparsfun(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	if (out4 != NULL) *out4 = plhs[4];
	return plhs[0];
}




inline mwArray sprintf(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
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
	mlxSprintf(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sqrt(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSqrt(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sscanf(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSscanf(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray sscanf(mwArray *out1, const mwArray &in1=mwArray::DIN, const 
mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSscanf(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray sscanf(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
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
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSscanf(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray sscanf(mwArray *out1, mwArray *out2, mwArray *out3, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN, const mwArray 
&in3=mwArray::DIN)
{
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
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSscanf(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	if (out3 != NULL) *out3 = plhs[3];
	return plhs[0];
}


inline mwArray str2func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxStr2func(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray strrep(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxStrrep(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray strcmp(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxStrcmp(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray strcmpi(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxStrcmpi(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray strncmp(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxStrncmp(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray strncmpi(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxStrncmpi(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray struct_func(const mwVarargin &in1, const mwArray 
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
	mlxStruct(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray struct2cell(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxStruct2cell(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray subsasgn(const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN, const mwArray &in3=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[3];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	    if (!in3.IsDIN()) {
	      prhs[nrhs++] = in3.GetData();
	    }
	  }
	}
	mlxSubsasgn(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray subsindex(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxSubsindex(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray subsref(mwVarargout varargout, const mwArray &in1=mwArray::DIN, 
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
	mlxSubsref(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray subsref(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSubsref(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray sum(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSum(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void superiorto(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxSuperiorto(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray svd(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxSvd(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray svd(mwArray *out1, const mwArray &in1=mwArray::DIN, const mwArray 
&in2=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxSvd(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray svd(mwArray *out1, mwArray *out2, const mwArray 
&in1=mwArray::DIN, const mwArray &in2=mwArray::DIN)
{
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
	MatlabMatrix *prhs[2];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	  if (!in2.IsDIN()) {
	    prhs[nrhs++] = in2.GetData();
	  }
	}
	mlxSvd(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray system_dependent(const mwVarargin &in1, const mwArray 
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
	mlxSystem_dependent(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray system_dependent(mwArray *out1, const mwVarargin &in1, const 
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
	mlxSystem_dependent(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray system_dependent(mwArray *out1, mwArray *out2, const mwVarargin 
&in1, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const 
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
&in32=mwArray::DIN)
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
	mlxSystem_dependent(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	if (out2 != NULL) *out2 = plhs[2];
	return plhs[0];
}


inline mwArray tan(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxTan(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray tanh(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxTanh(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray times(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxTimes(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray transpose(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxTranspose(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray trmginput(mwVarargout varargout, const mwVarargin &in1, const 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxTrmginput(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray trmginput(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxTrmginput(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray tril(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxTril(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray triu(const mwArray &in1=mwArray::DIN, const mwArray 
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
	mlxTriu(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline void type(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxType(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray uint8_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUint8(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray uint16_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUint16(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray uint32_func(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUint32(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray uminus(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUminus(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray unaryminus(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUnaryminus(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray uplus(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUplus(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray upper(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUpper(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray unix_func(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUnix(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray unix_func(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxUnix(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray version()
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1]={0};
	mlxVersion(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray version(mwArray *out1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1]={0};
	mlxVersion(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray vertcat(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxVertcat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray vms(const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxVms(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray vms(mwArray *out1, const mwArray &in1=mwArray::DIN)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxVms(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline void Vwarning(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 0;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxWarning(nlhs, plhs, nrhs, prhs);
	if (plhs[0] != NULL) mxDestroyArray(plhs[0]);
}


inline mwArray warning(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxWarning(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray warning(mwArray *out1, const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[2];
	plhs[0] = NULL;
	if (out1 != NULL) {
	  plhs[nlhs++]=NULL;
	}
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxWarning(nlhs, plhs, nrhs, prhs);
	if (out1 != NULL) *out1 = plhs[1];
	return plhs[0];
}


inline mwArray Nwarning(int nargout, mwArray *out1, const mwArray &in1)
{
	int nlhs = nargout;
	MatlabMatrix *plhs[2];
	MatlabMatrix *prhs[1];
	prhs[0] = (!in1.IsDIN())?in1.GetData():(MatlabMatrix*)(NULL);
	plhs[0] = mlfNWarning(nargout, nargout>1?&plhs[1]:(MatlabMatrix**)NULL, 
prhs[0]);
	if (nlhs > 1) {
	  if (out1 != NULL) *out1 = plhs[1];
	}
	return plhs[0];
}

inline mwArray which(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxWhich(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray who(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const 
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
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxWho(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray whos(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxWhos(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray what(const mwArray &in1)
{
	int nrhs = 0;
	int nlhs = 1;
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	MatlabMatrix *prhs[1];
	if (!in1.IsDIN()) {
	  prhs[nrhs++] = in1.GetData();
	}
	mlxWhat(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


inline mwArray xlate(mwVarargout varargout, const mwVarargin &in1, const mwArray 
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
	int nlhs = varargout.Nargout();
	mwList<MatlabMatrix *, 10> _plhs(nlhs+0);
	MatlabMatrix **plhs = _plhs.GetData();
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxXlate(nlhs, plhs, nrhs, prhs);
	varargout.AssignOutputs(nlhs, plhs);
	return varargout.GetReturnValue();
}


inline mwArray xlate(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, 
const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray 
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
	MatlabMatrix *plhs[1];
	plhs[0] = NULL;
	mwList<MatlabMatrix *, 10> _prhs(0 + varargin.Size());
	mxArray **prhs = _prhs.GetData();
	varargin.GetArrayBuffer(prhs + 0);
	nrhs += varargin.Size();
	mlxXlate(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}

inline mwArray zeros(const mwVarargin &in1=mwVarargin::DIN, const mwArray 
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
	mlxZeros(nlhs, plhs, nrhs, prhs);
	return plhs[0];
}


#endif /* __mlmif_h__ */
