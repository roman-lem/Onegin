#include "TestSort.h"

//---------------------------------

int Test_StrCmp(){

	char* str1 = "aaaaaa";
	char* str2 = "aaaaaa";

	if(StrCmp(&str1, &str2) == 0)
		return 1;
	else
		return 0;

	str1 = "aaaaa";
	str2 = "aaaaaa";

	if(StrCmp(&str1, &str2) == -1)
		return 1;
	else
		return 0;

	str1 = "aaaaaa";
	str2 = "aaaaaz";

	if(StrCmp(&str1, &str2) == -1)
		return 1;
	else
		return 0;

	str1 = "aaaaaa";
	str2 = "zzzzz";

	if(StrCmp(&str1, &str2) == 1)
		return 1;
	else
		return 0;

	str1 = "a.a.a/a6a7a";
	str2 = "a a4a a*a5a";

	if(StrCmp(&str1, &str2) == 0)
		return 1;
	else
		return 0;
}

//----------------------------

int Test_isLetter(){

	if(isLetter('@'))
		return 0;
	else
		return 1;

	if(isLetter('A'))
		return 1;
	else
		return 0;

	if(isLetter('Z'))
		return 1;
	else
		return 0;

	if(isLetter('['))
		return 0;
	else
		return 1;

	if(isLetter('`'))
		return 0;
	else
		return 1;

	if(isLetter('a'))
		return 1;
	else
		return 0;

	if(isLetter('z'))
		return 1;
	else
		return 0;

	if(isLetter('{'))
		return 0;
	else
		return 1;
}

//----------------------------

int Test_Upper(){

	char ch = 0;
	for(ch = 'a'; ch <= 'z'; ch++){

		if(Upper(ch) != 'A' + (ch - 'a'))
			return 0;
	}

	return 1;
}

//=================================================================================================