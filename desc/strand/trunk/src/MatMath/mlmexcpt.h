/* $Revision: 1.4 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc.
// mlmexcpt.h
// Peter Webb, Feb. 1995

#ifndef mlmexcpt_h
#define mlmexcpt_h

#include "mathwork.h"

#ifdef GCC
#pragma interface
#endif

#define MLM_EXCEPT_BUF 4096

class DLL_EXPORT mlm_exception
{
public:
    static char *format_buffer(const char *str, ...);
    static char *get_buffer() { return buffer; }

private:

    static char buffer [ MLM_EXCEPT_BUF ];
};

#define MLM_THROW0(type, string)\
{ type _mlm_except_(string, __LINE__, __FILE__); \
  _mlm_except_.do_raise(); }

#define MLM_THROW1(type, string, arg)\
{ type _mlm_except_(mlm_exception::format_buffer(string, arg), __LINE__, __FILE__);\
  _mlm_except_.do_raise(); }

#define MLM_THROW2(type, string, a1, a2)\
{ type _mlm_except_(mlm_exception::format_buffer(string, a1, a2), \
           __LINE__, __FILE__); \
  _mlm_except_.do_raise(); }

#define MLM_THROW3(type, string, a1, a2, a3)\
{ type _mlm_except_(mlm_exception::format_buffer(string, a1, a2, a3), \
           __LINE__, __FILE__); \
  _mlm_except_.do_raise(); }

#define MLM_THROW4(type, string, a1, a2, a3, a4)\
{ type _mlm_except_(mlm_exception::format_buffer(string, a1, a2, a3, a4), \
           __LINE__, __FILE__); \
  _mlm_except_.do_raise(); }

#define MLM_THROW5(type, string, a1, a2, a3, a4, a5)\
{ type _mlm_except_(mlm_exception::format_buffer(string, a1, a2, a3, a4, a5), \
           __LINE__, __FILE__); \
  _mlm_except_.do_raise(); }

#endif
