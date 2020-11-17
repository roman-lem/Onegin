#include <stdio.h>
#include <stdlib.h>

/**
	* @brief This func compare strings
	*
	*	@param str1 - Pointer on first string
	*
	* @param str2 - Pointer on second string
	*
	* @return 1, if first second higher, -1, if second, 0, if it same
	*/

int StrCmp(const void* str1, const void* str2);

/**
	* @brief This func check, that param is letter
	*
	*	@param ch - Char
	*
	* @return 1, if ch is letter, 0, if ch isn't letter
	*/

int isLetter(char ch);

/**
	* @brief This func capitalize letter
	*
	*	@param ch - Char
	*
	* @return ASCII code of capital letter, -1, if ch isn't letter
	*/

int Upper(char ch);

//=================================================================================================