/* $Revision: 1.2 $ */
// Copyright (c) 1995-1998, The MathWorks, Inc. All Rights Reserved.
// mwstr.h
// Peter Webb, Dec. 1996
//
// The mwString class is a very simple string class that allows strings to
// be passed around without fear of memory leaks.  By default the constructor 
// makes dynamic copies of the argument it is given. The destructor always
// deallocates the string data.
//
// The class is completely defined in this header file; there is no
// associated .cpp file.  All the functions are inline.

class mwString
{
public:
    mwString();
    mwString(char *s, int dup =1);
    mwString(const mwString &s);
    ~mwString();

    mwString &operator=(const mwString &s);
    operator char *() const;
    int Length()      const;

    int operator==(const mwString &other) const;
    int operator!=(const mwString &other) const;

private:

    int len;
    char *str;
};

// Create a NULL, zero-length string.

inline mwString::mwString() : len(0), str(0) {}

// String constructor.  If dup is 1, which it is by default, make a new copy
// of the string data.

inline mwString::mwString(char *s, int dup)
  : len(0), str(0)
{
    if (s)
    {
	if (dup) str = strdup(s);
	else str = s;
	len = strlen(s);
    }
}

// Copy constructor. Make a new copy of the string data.

inline mwString::mwString(const mwString &s)
  : len(s.len), str(0)
{
    if (s.str) str = strdup(s.str);
}

// Assignment operator. Make a new copy of the string data.

inline mwString& mwString::operator=(const mwString &s)
{
    if (str) delete [] str;
    if (s.str) str = strdup(s.str);
    len = s.len;
    return *this;
}

inline mwString::operator char *() const
{
    return str;
}

inline int mwString::Length() const
{
    return len;
}

// Always delete the string data.  No memory leaks.
inline mwString::~mwString()
{
    if (str) delete [] str;
}

// String comparison.  Null strings are equal.
inline int mwString::operator==(const mwString &other) const
{ 
    return (((!str && !other.str) || (len == 0 && other.len == 0)) ||
	    (str && other.str && len == other.len && !strcmp(str, other.str)));
}
    
inline int mwString::operator!=(const mwString &other) const
{
    return !operator==(other);
}

