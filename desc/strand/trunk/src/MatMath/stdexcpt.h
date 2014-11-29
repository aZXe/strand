
/* $Revision: 1.17 $ */
// Copyright (c) 1995-1999 The MathWorks, Inc.
// stdexcpt.h
// Peter Webb, Feb. 1995
//
// Copy the C++ standard class library exception hierarchy.  This file will be
// completely replaced when the standard class library ships. 

#ifndef exception_h
#define exception_h

#ifdef GCC
#pragma interface
#endif

#include "mathwork.h"

#include <iostream.h>
#include <string.h>

// Borland C++ 5.3 has collision with std::strdup
#if !defined(__BORLANDC__) ||  (__BORLANDC__ < 0x0530)
extern "C" DLL_EXPORT char *strdup(const char *);
#endif

// Base class for all exceptions. Contains much of the implementation.  
// Subclasses MUST override do_raise().

class DLL_EXPORT mwException
{
public:
  
  
    mwException() : message(0), on_heap(1), file(0), line(0) {;}
    mwException(const char *);
    mwException(const char * msg_arg, int32 line_arg, const char *file_arg);
    mwException(const mwException&);
    mwException &operator=(const mwException&);
    virtual ~mwException();
    virtual const char *post() const         { return 0; }
    virtual const char *what() const         { return message; }
    virtual const char *type() const         { return 0; }
    void raise()                             { do_raise(); }
    virtual const char *source() const       { return file; }
    virtual int where() const                { return line; }

protected:
    mwException(const char *msg, int32 ln, const char * fname, bool heap);
    virtual void do_raise();

    char * message;      // Exception message.
    bool on_heap;        // Indicates if message is allocated on heap.
    char *file;          // File name     
    int line;            // Line number
};

inline ostream &operator<<(ostream &os, const mwException &except)
{
    if (except.type()) os << except.type() << endl;
    const char *file =
      (except.source() ? except.source() : "No File Info.");
    os << "Exception!  File: " << file << ", Line: " 
       << except.where() << endl;
    os << "    " << except.what() << endl;

    // Print exception-class-specific message
    if (except.post() != 0)
      os << except.post() << endl;
    return os;
}

// Logic errors are programmer bugs.  These can always be eliminated by more
// careful coding.

class DLL_EXPORT mwLogicError : public mwException
{
public:
    mwLogicError(const char * msg) : mwException(msg) {}
    mwLogicError(const char * msg_arg, int32 line_arg, const char *file_arg)
      : mwException(msg_arg, line_arg, file_arg) {}
    virtual void do_raise();
    const char *type() const;

    const char *post() const
      { return "Please report this error to The MathWorks."; }

protected:
    mwLogicError(const char *msg, int32 ln, const char * fname,
		 bool use_heap) 
      : mwException(msg, ln, fname, use_heap) {}
};

class DLL_EXPORT mwSubclassResponsibility : public mwLogicError
{
public:
    mwSubclassResponsibility(const char *func) : mwLogicError(func) {}
    mwSubclassResponsibility(const char * msg_arg, int32 line_arg, const
        char *file_arg)
    : mwLogicError(msg_arg, line_arg, file_arg) {}
    virtual void do_raise();
    const char *what() const; 
private:
    static const char *subclass_impl;
};

// Runtime errors occur when the runtime environment differs from that which
// the program expects or requires.

// Generic runtime error
class DLL_EXPORT mwRuntimeError : public mwException       
{
public:
    mwRuntimeError(const char *msg) : mwException(msg) {}
    mwRuntimeError(const char * msg_arg, int32 line_arg,
          const char *file_arg)
    : mwException(msg_arg, line_arg, file_arg) {}
    virtual void do_raise();
    const char* type() const;
protected:
    mwRuntimeError(const char *msg, int32 ln, const char * fname,
          bool use_heap) 
    : mwException(msg, ln, fname, use_heap) {}
};

// Chain two exceptions together
class DLL_EXPORT mwChainError : public mwRuntimeError    
{
public:
    mwChainError(mwException &ex, const char *msg =0);
    mwChainError(mwException &ex, int32 line_arg, const char *file_arg,
		const char *msg = 0);

    virtual void do_raise();
    const char *what() const;
    const char *source() const;  
    int where() const;
      
private:

    mwException except;
};


// Create an mwChainError from another exception.  Allow the creator
// to specify an additional message.  When this exception is printed,
// both the message associated with the contained exception and the
// message specified here will be printed.

inline mwChainError::mwChainError(mwException &ex, const char *msg)
    : mwRuntimeError(0), except(ex) 
{ 
    if (msg)
      if (except.what())
      {
	  message = new char [ strlen(msg) + strlen(except.what()) + 2 ];
	  strcpy(message, except.what());
	  strcat(message, "\n");
	  strcat(message, msg);
      }
      else
      {
	  message = strdup(msg);
      }
    else message = 0;
}


// Create an mwChainError from another exception.  Allow the creator
// to specify an additional message.  In addition, allow the explicit
// specification of file name and line number.  In all other respects,
// behaves like the constructor above.

inline mwChainError::mwChainError(mwException &ex, int32 line_arg,
				  const char *file_arg,
				  const char *msg)
    : mwRuntimeError(0, line_arg, file_arg), except(ex) 
{
    if (msg)
      if (except.what()) 
      {
	  message = new char [ strlen(msg) + strlen(except.what()) + 2 ];
	  strcpy(message, except.what());
	  strcat(message, "\n");
	  strcat(message, msg);
      }
      else 
      {
	  message = strdup(msg);
      }
    else message = 0;
}


inline const char * mwChainError::what() const
{
    if (message) return message; 
    else return except.what();
}

inline const char * mwChainError::source() const
{
    if (mwException::source()) return mwException::source();
    else return except.source();
}

inline int mwChainError::where() const
{ 
    if (mwException::source()) return mwException::where();
    else return except.where();
}

// Unrepresentable result
class DLL_EXPORT mwRangeError : public mwRuntimeError    
{
public:
    mwRangeError(const char *msg) : mwRuntimeError(msg) {}
    mwRangeError(const char * msg_arg, int32 line_arg, const char *file_arg)
    : mwRuntimeError(msg_arg, line_arg, file_arg) {}
    virtual void do_raise();
};

class DLL_EXPORT mwDomainError : public mwRuntimeError    // Incorrect input
{
public:
    mwDomainError(const char *msg) : mwRuntimeError(msg) {}
    mwDomainError(const char * msg_arg, int32 line_arg,
         const char *file_arg)
    : mwRuntimeError(msg_arg, line_arg, file_arg) {}
    virtual void do_raise();
};

class DLL_EXPORT mwOverflowError : public mwRuntimeError
{
public:
    mwOverflowError(const char *msg) : mwRuntimeError(msg) {}
    mwOverflowError(const char * msg_arg, int32 line_arg,
           const char *file_arg)
    : mwRuntimeError(msg_arg, line_arg, file_arg) {}
    virtual void do_raise();
};

// Can't perform operation
class DLL_EXPORT mwIllegalOperation : public mwRuntimeError
{
public:
    mwIllegalOperation(const char *msg) : mwRuntimeError(msg) {}
    mwIllegalOperation(const char * msg_arg, int32 line_arg,
          const char *file_arg)
    : mwRuntimeError(msg_arg, line_arg, file_arg) {}
    virtual void do_raise();
};

class DLL_EXPORT mwBadAlloc : public mwRuntimeError
{
public:

    mwBadAlloc(const char *, int32 ln, const char * fname) 
        : mwRuntimeError(out_of_memory, ln, fname, 0) {}

    virtual void do_raise();
    static const char *out_of_memory;

};

// For undefined variables, used by the MATLAB Compiler only

class DLL_EXPORT mwUndefVar : public mwRuntimeError
{
public:
    mwUndefVar(const char *msg_arg, int32 line_arg, const char *file_arg)
	: mwRuntimeError(0)
    {
        message = new char [ strlen(msg_arg) + 21 ];
        line = (int)line_arg;
	file = strdup(file_arg);
        strcpy(message, "Undefined variable: ");
        strcat(message, msg_arg);
    }
    virtual void do_raise();
};


#ifndef USE_MW_PREFIX
 
typedef mwException Exception;
typedef mwLogicError LogicError;
typedef mwRuntimeError RuntimeError;
typedef mwSubclassResponsibility SubclassResponsibility;
typedef mwChainError ChainError;
typedef mwRangeError RangeError;
typedef mwDomainError DomainError;
typedef mwOverflowError OverflowError;
typedef mwIllegalOperation IllegalOperation;
typedef mwUndefVar UndefVar;
 
#endif
 
#endif
