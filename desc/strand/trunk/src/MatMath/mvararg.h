// $Revision: 1.10 $
// Copyright (c) 1995-1998, The MathWorks, Inc. All Rights Reserved.
#ifndef _mvararg_h
#define _mvararg_h

#include "dblmtrx.h"


mwArray cellhcat(const mwVarargin &in1, const mwArray &in2=mwArray::DIN, const mwArray &in3=mwArray::DIN, const mwArray &in4=mwArray::DIN, const mwArray &in5=mwArray::DIN, const mwArray &in6=mwArray::DIN, const mwArray &in7=mwArray::DIN, const mwArray &in8=mwArray::DIN, const mwArray &in9=mwArray::DIN, const mwArray &in10=mwArray::DIN, const mwArray &in11=mwArray::DIN, const mwArray &in12=mwArray::DIN, const mwArray &in13=mwArray::DIN,
const mwArray &in14=mwArray::DIN, const mwArray &in15=mwArray::DIN, const mwArray &in16=mwArray::DIN, const mwArray &in17=mwArray::DIN, const mwArray &in18=mwArray::DIN, const mwArray &in19=mwArray::DIN, const mwArray &in20=mwArray::DIN, const mwArray &in21=mwArray::DIN, const mwArray &in22=mwArray::DIN, const mwArray &in23=mwArray::DIN, const mwArray &in24=mwArray::DIN, const mwArray &in25=mwArray::DIN, const mwArray &in26=mwArray::DIN,
const mwArray &in27=mwArray::DIN, const mwArray &in28=mwArray::DIN, const mwArray &in29=mwArray::DIN, const mwArray &in30=mwArray::DIN, const mwArray &in31=mwArray::DIN, const mwArray &in32=mwArray::DIN);

void load( const mwArray &file, const char* nm1, mwArray *RO1, const char* nm2=NULL, mwArray *OO2=NULL, const char* nm3=NULL, mwArray *OO3=NULL, const char* nm4=NULL, mwArray *OO4=NULL, const char* nm5=NULL, mwArray *OO5=NULL, const char* nm6=NULL, mwArray *OO6=NULL, const char* nm7=NULL, mwArray *OO7=NULL, const char* nm8=NULL, mwArray *OO8=NULL, const char* nm9=NULL, mwArray *OO9=NULL, const char* nm10=NULL, mwArray *OO10=NULL,
const char* nm11=NULL, mwArray *OO11=NULL, const char* nm12=NULL, mwArray *OO12=NULL, const char* nm13=NULL, mwArray *OO13=NULL, const char* nm14=NULL, mwArray *OO14=NULL, const char* nm15=NULL, mwArray *OO15=NULL, const char* nm16=NULL, mwArray *OO16=NULL );

void loadc_( const mwArray &file, const char* nm1, mwArray *RO1, const char* nm2=NULL, mwArray *OO2=NULL, const char* nm3=NULL, mwArray *OO3=NULL, const char* nm4=NULL, mwArray *OO4=NULL, const char* nm5=NULL, mwArray *OO5=NULL, const char* nm6=NULL, mwArray *OO6=NULL, const char* nm7=NULL, mwArray *OO7=NULL, const char* nm8=NULL, mwArray *OO8=NULL, const char* nm9=NULL, mwArray *OO9=NULL, const char* nm10=NULL, mwArray *OO10=NULL,
const char* nm11=NULL, mwArray *OO11=NULL, const char* nm12=NULL, mwArray *OO12=NULL, const char* nm13=NULL, mwArray *OO13=NULL, const char* nm14=NULL, mwArray *OO14=NULL, const char* nm15=NULL, mwArray *OO15=NULL, const char* nm16=NULL, mwArray *OO16=NULL );

void save( const mwArray &file, const char* nm1, const mwArray &RI1, const char* nm2=NULL, const mwArray &OI2=mwArray::DIN, const char* nm3=NULL, const mwArray &OI3=mwArray::DIN, const char* nm4=NULL, const mwArray &OI4=mwArray::DIN, const char* nm5=NULL, const mwArray &OI5=mwArray::DIN, const char* nm6=NULL, const mwArray &OI6=mwArray::DIN, const char* nm7=NULL, const mwArray &OI7=mwArray::DIN, const char* nm8=NULL,
const mwArray &OI8=mwArray::DIN, const char* nm9=NULL, const mwArray &OI9=mwArray::DIN, const char* nm10=NULL, const mwArray &OI10=mwArray::DIN, const char* nm11=NULL, const mwArray &OI11=mwArray::DIN, const char* nm12=NULL, const mwArray &OI12=mwArray::DIN, const char* nm13=NULL, const mwArray &OI13=mwArray::DIN, const char* nm14=NULL, const mwArray &OI14=mwArray::DIN, const char* nm15=NULL, const mwArray &OI15=mwArray::DIN, const char* nm16=NULL, const mwArray &OI16=mwArray::DIN );

void save( const mwArray &file, const char* mode, const char* nm1, const mwArray &RI1, const char* nm2=NULL, const mwArray &OI2=mwArray::DIN, const char* nm3=NULL, const mwArray &OI3=mwArray::DIN, const char* nm4=NULL, const mwArray &OI4=mwArray::DIN, const char* nm5=NULL, const mwArray &OI5=mwArray::DIN, const char* nm6=NULL, const mwArray &OI6=mwArray::DIN, const char* nm7=NULL, const mwArray &OI7=mwArray::DIN, const char* nm8=NULL, const mwArray &OI8=mwArray::DIN,
const char* nm9=NULL, const mwArray &OI9=mwArray::DIN, const char* nm10=NULL, const mwArray &OI10=mwArray::DIN, const char* nm11=NULL, const mwArray &OI11=mwArray::DIN, const char* nm12=NULL, const mwArray &OI12=mwArray::DIN, const char* nm13=NULL, const mwArray &OI13=mwArray::DIN, const char* nm14=NULL, const mwArray &OI14=mwArray::DIN, const char* nm15=NULL, const mwArray &OI15=mwArray::DIN, const char* nm16=NULL, const mwArray &OI16=mwArray::DIN );

#endif //_mvararg_h
