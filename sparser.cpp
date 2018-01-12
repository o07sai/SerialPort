//sparser.cpp
//author: o07sai.

#include "StdAfx.h"

#define TOKEN_NUM_HEX		0x1001
#define TOKEN_NUM_OCT		0x1002
#define TOKEN_NUM_DEC		0x1003
#define TOKEN_NUM_BIN		0x1004
#define TOKEN_ERROR			(-1)

#define IS_BLANK(c)			((' ' == c) || ('\t' == c))
#define IS_CHAR(c)			(('_' == c) || (('A' <= c) && ('Z' >= c)) || (('a' <= c) && ('z' >= c)))
#define IS_ALPHA(c)			(('0' <= c) && ('9' >= c))
#define IS_CALC_CHAR(c)		(('(' == c) ||(')' == c) || ('=' == c))
#define IS_TRANS_CHAR(c)	('\\' == c)

#define ARRAY_SIZE(a)		(sizeof(a)/sizeof(a[0]))

int GetTokenString(const char ** ps, char* stoken)
{
	const char* s = *ps;
	int n = 0;
	int transed = 0;

	while(*s)
	{
		if(0 == n)
		{
			if(IS_BLANK(*s))
			{
				s++;
				continue;
			}
			else if(IS_CALC_CHAR(*s))
			{
				*stoken++ = *s++;
				n++;
				break;
			}
		}
		else
		{
			if((!transed) && (IS_CALC_CHAR(*s)))
				break;
		}
		if((!transed) && IS_TRANS_CHAR(*s))
		{
			transed = 1;
			continue;
		}
		else
		{
			transed = 0;
		}
		*stoken++ = *s++;
		n++;
	}
	*stoken = 0;
	*ps = s;
	return n;
}


//end of file.
