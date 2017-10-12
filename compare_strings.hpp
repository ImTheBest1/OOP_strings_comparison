/**********************************************************************************************
	
	12Sigma Interview Project

	CompareString.h(Version1.1)
	Purpose: Create a String Object, implements two strings' comparison


	Member fuctions:	CompareString();		// default constructor
						CompareString(const char *str1, const char *str2)	//constructor
						sigmaStrcmp(const char *str1, const char *str2, int comStrlen)	// compare two strings
						string_invert(char *str, int strLen)	// reverse string
						string_inverted_concatenated(char *cstr1, char *cstr2, int inStr1Len, int inStr2Len)
						string_merge(char *str1, const char *str2, int inStr1Len, int inStr2Len)
						string_inverted_merge(char *str1, char *str2, int inStr1Len, int inStr2Len)

	@ author: Miaomiao Zhang

***************************************************************************************************/

#ifndef COMPARE_STRINGS_HPP_
#define COMPARE_STRINGS_HPP_
#define contentLength 1024

#include <iostream>

/***************************************************************************************************
*
*   Class Name:		CompareStrings
*
*   Purpose:		wrap two strings as an object, then compare two members in the object
*
***************************************************************************************************/

class CompareStrings
{
public:
	// default constructor
	CompareStrings();

	// constructor
	CompareStrings(int str1Len, int str2Len);

	// destructor
	~CompareStrings();


	// compare two strings with known lengths
	int sigmaStrcmp(char* str1, char* str2, int str1Len, int str2Len);

	// invert one string
	char* string_invert(char *str, int strLen);

	// invert two strings, and append string 2 to string 1. Example: abcdef and uvwxyz, would be displayed as fedcbazyxwvu
	std::string string_inverted_concatenated(char* str1, char* str2, int str1Len, int str2Len);

	// merge string 1 with string 2. Example: abcdef and abcdef, would be displayed as aabbccddeeff.
	std::string string_merge(char* str1, char* str2, int str1Len, int str2Len);

	// invert two strings, then merge inverted strings together. Example: uvwxyz and abcdef, would be displayed as zfyexdwcvbua
	std::string string_inverted_merge(char* str1, char* str2, int str1Len, int str2Len);

private:
	// data members
	 char *_output;	// allocate memory for output string 
	 int size;	// store output length of return string
	


};

#include "compare_strings.cpp"

#endif //COMPARE_STRINGS_HPP_