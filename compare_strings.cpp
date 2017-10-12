#ifndef COMPARE_STRINGS_CPP_
#define COMPARE_STRINGS_CPP_

#include "compare_strings.hpp"
#include <iostream>

/***************************************************************************************************
*
*   Function Name:		CompareStrings
*
*   Purpose:			default constructor
*
*	Updated Parts:		set default size is equal to double size of contentLength
*						allocate dynamic char*[] _output
*
*   Input Parameters:	none
*
*   Output parameters:	none
*
*   Return Value:		none
*
***************************************************************************************************/

CompareStrings::CompareStrings(){
	 size = 2 * contentLength;
	_output = new char[size];
		
	}

/***************************************************************************************************
*
*   Function Name:		CompareStrings
*
*   Purpose:			constructor
*
*	Updated Parts:		set dynamic char*[] _output size: the sum of the length of string1 plus the length of string2
*						allocate dynamic char*[] _output
*
*   Input Parameters:	int str1Len: the length of string1
*						int str2Len: the length of string2
*
*   Output parameters:	none
*
*   Return Value:		none
*
***************************************************************************************************/
CompareStrings::CompareStrings(int str1Len, int str2Len){
	
	size = str1Len + str2Len; 
	/**
	 allocate new memory for output array, size = str1Len + str2Len;
	 */
	_output = new char[size];

	}

/***************************************************************************************************
*
*   Function Name:		~CompareStrings
*
*   Purpose:			destructor. de-allocate the memory
*
*	Updated Parts:		The destructor is used to deallocate char*[] output. Reason: 
*						Avoid a memory leak and free up memory
*						Previous version does not have destructor, the reason:
*						Since char*[] for storing two strings does not use “new” keyword to allocate it, 
*						it is only the pointer * _str1 point to the local parameter, therefore, as long as 
*						the program finishes running, the memory used for global variable *_str will be freed 
*						at runtime completion. If there is destructor inside the CompareStrings, it would show errors:
*						 no memory needs to be freed.
*						 
*
*   Input Parameters:	none
*
*   Output parameters:	none
*
*   Return Value:		none
*
***************************************************************************************************/

CompareStrings::~CompareStrings(){
	delete[] _output;
	
}


/***************************************************************************************************
*
*   Function Name:		sigmaStrcmp
*
*   Purpose:			compare two strings using their ASCII values
*						compare two substrings up to the number of characters as the shortest string
*
*	Algorithm Ideas:	Assuming two strings have different lengths
*						compare the first comStrlen size of characters,
*						the reason: 
*									1) in comStrlen, if one string is greater than or less than the other,
*										then return -1 or 1. no further comparison is needed.
*										within comStrlen comparison, if commonCmpResult == 0, continue comparison.
*									2) check input string length, if one string is greater than 
*									the other string, then return 1; 
*									if one string is equal to the other string, then return 0
*									if one string is less than the other string, then -1
*	Updated Parts:		combine parts of comparison in previous main.cpp into this method
*						passing by reference as local parameters
*
*
*   Input Parameters:	char* str1: input char array 1
*						char* str2: input char array 2
*						int str1Len: input length of string 1
*						int str2Len: input length of string 2
*						
*
*   Output parameters:  int: -1, 0, 1
*
*   Return Value:		returns an integer greater than, equal to or less than 0
*
***************************************************************************************************/

int CompareStrings::sigmaStrcmp(char* str1, char* str2, int str1Len, int str2Len){

	/**
		comparing two lengths, since two strings lengths may differ, choose the smaller length as common length
		compare two strings within common length
	*/
	int commonLength = str1Len < str2Len ? str1Len: str2Len;

	/**
		initialize local variable cmpValue.
	*/
	int cmpValue = 0;
	int commonCmpResult = 0;
	
	for (int i = 0; i < commonLength; ++i){
		cmpValue = str1[i] - str2[i];
	if (cmpValue < 0)
		return -1;
	if (cmpValue > 0)
		return 1;
	}

	if ( commonCmpResult == 0){
		if(str1Len < str2Len){
			return -1;
		}else if (str1Len > str2Len){
			return 1;
		}
	}

	return 0;
	
}

/***************************************************************************************************
*
*   Function Name:		string_invert
*
*   Purpose:			invert / reverse the entire string with given length
*
*	Algorithm Ideas:	1) could create an empty, append each character from end to beginning to the new string.
*						2) I did not use 1) algorithm idea, due to memory saving, apply reverse on original input string.
*						divide the array into two parts, swap the front values with back values.
*						even though the char array with odd length, the middle index value swap its own value with itself
*	
*	Updated Parts: 		None
*					
*   Input Parameters:	char *str: the string to be inverted
*						
*						int strLen: the string with known length
*						
*   Output parameters:  char *str: reverse the input string, and output this string
*
*   Return Value:		returns a string which is inverted
*
***************************************************************************************************/

char* CompareStrings::string_invert(char *str, int strLen){
	
	char tempChar = '\0';
	
	for(int i = 0; i < (strLen / 2); ++i){
		tempChar = str[i];
		str[i] = str[strLen - i - 1];
		str[strLen - i - 1] = tempChar;
	}
	return str;
}

/***************************************************************************************************
*
*   Function Name:		string_inverted_concatenated
*
*   Purpose:			invert / reverse 2 strings with given lengths,
*						then append string 2 to string 1
*	
*	Updated Parts:		change from non input parameter to multiple parameters inputs
*						passing by reference as local parameters
*											
*   Input Parameters:	char* str1: input char array 1
*						char* str2: input char array 2
*						int str1Len: input length of string 1
*						int str2Len: input length of string 2
*						
*   Output parameters:  string str1: reverse on input string, concatenate to the string 1
*
*   Return Value:		returns a string which is inverted
*
***************************************************************************************************/

std::string CompareStrings::string_inverted_concatenated(char* str1, char* str2, int str1Len, int str2Len){
	/**
		invert two strings
	*/
	str1 = string_invert(str1, str1Len);
	str2 = string_invert(str2, str2Len);

	/**
		concatenate string 2 to string 1
	*/
	int i = 0;
	for(; i < str1Len; ++i){
		_output[i] = str1[i];
	}

	for(; i < size; ++i){
		_output[i] = str2[i - str1Len];
	}

	return _output;
}

/***************************************************************************************************
*
*   Function Name:		string_merge
*
*   Purpose:			merge two strings
*
*	Updated Parts:		change from non input parameter to multiple parameters inputs
*						passing by reference as local parameters
*
*   Algorithm Ideas:	assuming two strings have different lengths
*						steps:
*							1) start with empty string
*							2) compare two strings length, pick the smaller length (common length)
*							3) due to the common length, loop through two strings, merge the length with equal to common length strings
*							4) append the rest of the larger length of string to the output string
*						
*   Input Parameters:	char* str1: input char array 1
*						char* str2: input char array 2
*						int str1Len: input length of string 1
*						int str2Len: input length of string 2
*
*   Output parameters:  string outMerge: a string is merged from string1 and string2
*
*   Return Value:		returns a string which is inverted
*
***************************************************************************************************/
std::string CompareStrings::string_merge(char* str1, char* str2, int str1Len, int str2Len){
	/**
		compare two strings length, pick the smaller length as common length
	*/
	int commonLen = str1Len < str2Len ? str1Len : str2Len;
	
	/**
		merge 2 strings with given length
	*/
	int index1 = 0;
	int index2 = 0;
	int i = 0; 
	
	int doubleSize = 2 * commonLen; 
	for(; i < doubleSize; ++i){
		if(i % 2 == 0){
			_output[i] = str1[index1++];
		}else{
			_output[i] = str2[index2++];
		}
	}

	/**
		append the rest of the larger length of string to the output string
	*/
	if(commonLen < str1Len){

		for(i = commonLen; i < str1Len; ++i){
			_output[i + commonLen] = str1[i];
		}

	}else if(commonLen < str2Len){
		for(i = commonLen; i < str2Len; ++i){
			_output[i + commonLen] = str2[i];
		}

	}

	return _output;		

}

/***************************************************************************************************
*
*   Function Name:		string_inverted_merge
*
*   Purpose:			invert two strings then merge
*
*	Updated Parts:		change from non input parameter to multiple parameters inputs
*						passing by reference as local parameters
*						
*   Input Parameters:	char* str1: input char array 1
*						char* str2: input char array 2
*						int str1Len: input length of string 1
*						int str2Len: input length of string 2
*						
*   Output parameters:  string outMerge: a string is merged from string1 and string2
*
*   Return Value:		returns a string which is inverted
*
***************************************************************************************************/

std::string CompareStrings::string_inverted_merge(char* str1, char* str2, int str1Len, int str2Len){
	/**
		invert two strings
	*/
	str1 = string_invert(str1, str1Len);
	str2 = string_invert(str2, str2Len);	

	/**
		merge two strings, return
	*/

	return string_merge(str1, str2, str1Len, str2Len);
}



#endif //COMPARE_STRINGS_CPP_