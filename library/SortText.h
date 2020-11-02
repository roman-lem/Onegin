#include <stdio.h>
#include <stdlib.h>

/**
	* @brief This func sort text alphabetaly
	*
	*	@param pToStr - Array of pointers on strings
	*
	* @param begin - Start index of array
	*
	*	@param end - End index of array
	*/

void TextSort(char** pToStr, int begin, int end);

/**
	* @brief Unit test for TextSort()
	*
	* @return it function printf "abcde", if it work correctly
	*/

void Test_TextSort();

/**
	* @brief This func compare strings
	*
	*	@param str1 - Pointer on first string
	*
	* @param str2 - Pointer on second string
	*
	* @return 1, if first second higher, 2, if second, 0, if it same
	*/

int StrCmp(char* str1, char* str2);

/**
	* @brief Unit test for StrCmp()
	*
	* @return 1, if test was passed, else return 0
	*/

int Test_StrCmp();

/**
	* @brief This func check, that param is letter
	*
	*	@param ch - Char
	*
	* @return 1, if ch is letter, 0, if ch isn't letter
	*/

int isLetter(char ch);

/**
	* @brief Unit test for isLetter()
	*
	* @return 1, if test was passed, else return 0
	*/

int Test_isLetter();

/**
	* @brief This func capitalize letter
	*
	*	@param ch - Char
	*
	* @return ASCII code of capital letter, -1, if ch isn't letter
	*/

int Upper(char ch);

/**
	* @brief Unit test for Upper()
	*
	* @return 1, if test was passed, else return 0
	*/

int Test_Upper();

//=================================================================================================