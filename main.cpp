/**********************************************************************************************
	
	12Sigma Interview Project (Updated version)

	main.cpp (Version1.1)
	Purpose: Write an object-oriented C++ console application that compare two strings without using 
			STL libraries. 
			return a string that satisfies the following requirements: 
			 1) if input string 1 < input string 2, return a string that invertes and concatenates the two input strings
				Example: abcdef and uvwxyz, would be displayed as fedcbazyxwvu
			 2) if input string 1 == input string 2, return a string that merges the two input strings
				Example: abcdef and abcdef, would be displayed as aabbccddeeff
			 3) if input string 1 > input string 2, return a string that invertes and merges the two input strings
				Example: uvwxyz and abcdef, would be displayed as zfyexdwcvbua
	
 	
	Member fuctions:	main();		// main function
	@ author: Miaomiao Zhang

***************************************************************************************************/

#include "compare_strings.hpp"
#include <iostream>


/***************************************************************************************************
*
*   Function Name:		userConsoleInput
*
*   Purpose:			requests two string inputs from user
*
*   Input Parameters:	a String strName. strName prints to console to prompt user as to whether
*						this is their first time entering a input string or second time entering an input string
*
*   Output parameters:	a String str. return str which is user input
*
*   Return Value:		returns the string the user entered
*
***************************************************************************************************/
std::string userConsoleInput(const std::string strName){
	std::string str;
	std::cout << "Enter the " << strName << " string: \n";

/**
	using getline() instead of cin>>str. since cin >> str only reads sequence of characters without any white space,
	user may input white space for input string 
*/

	if(getline(std::cin, str)){
		return str;
	}else{
		// error
		std::cout <<"Error: Getline fail to allocate memory. It is invalid input, quit the system. " << std::endl;
		exit(1);
		}



} // #end std::string userConsoleInput




/***************************************************************************************************
*
*   Function Name:		main
*
*   Purpose:			sigmaCompareStrings project main function
*
*   Input Parameters:	none
*
*   Output parameters:		int 0
*
*   Return Value:		return int 0, The value is the exit code of your program
***************************************************************************************************/

int main(){

	// inStr means input_string, inStr1 & inStr2 from user input
	std::string inStr1 = userConsoleInput("first");
	std::string inStr2 = userConsoleInput("second");
	
	
	/** 
		get the length of two strings. in order to use them as input parameters later.
		Character array does not offer much built-in functions to manipulate strings without #include <cstring>
		String class defines a number of functionalities which allow the for the manipulation of strings.
		get the string length without using #include <string>
	*/
	int _inStr1Len  = inStr1.length();
	int _inStr2Len = inStr2.length();


	/**
		create two dynamic char arrays which converted from input string
		The reason: Implementation of character array is faster than std::string 
		Strings are slower when compared to implementation than character array
	*/

	char *_cinStr1 = &(inStr1[0]);
	char *_cinStr2 = &(inStr2[0]);

	/**
		create CompareStrings object, passing by pointer
	*/
	CompareStrings _strings(_inStr1Len, _inStr2Len);

	/**
		comparing two strings, the value either -1, 1 or 0
	*/
	int commonCmpResult = _strings.sigmaStrcmp(_cinStr1, _cinStr2, _inStr1Len, _inStr2Len);

	/**
		output string to the console
	*/
	std::string outputString;
	 switch(commonCmpResult){
	 	// string 1 is less than string 2
	 	case (-1):
	  		outputString =  _strings.string_inverted_concatenated(_cinStr1, _cinStr2, _inStr1Len, _inStr2Len);
	  		std::cout << "\nResults: string 1 < string 2, outputString: " << outputString << std::endl;
	  		break;
	  	// string 1 is equal to string 2
	 	case (0):
	  		outputString = _strings.string_merge(_cinStr1, _cinStr2, _inStr1Len, _inStr2Len);
	  		std::cout << "\nResults: string 1 = string 2, outputString: " << outputString << std::endl;
	  		break;
	  	// string 1 is greater than string 2
	 	case (1): 
	  		outputString = _strings.string_inverted_merge(_cinStr1, _cinStr2, _inStr1Len, _inStr2Len);
	  		std::cout << "\nResults: string 1 > string 2, outputString: " << outputString << std::endl;
	  		break;
	 }

	 /** 
			under two lines of assignment commented out, 
			the reason is:
			the pointer doesnt allocated in the memeory, using "new" keyboard to allocate in the memory.
			as long as get out of the program, the pointer is being freed.
			if still using delete[] _cinStr1, then will shows errors.
			
			// delete [] _cinStr1;
			// delete [] _cinStr2;
	*/

	

return 0;

} //#end int main()