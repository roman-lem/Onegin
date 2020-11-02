#include "SortText.h"

//-----------------------------

void TextSort(char** pToStr, int begin, int end){

	if(begin < end){
		int left = begin, right = end;
		char* middle = *(pToStr + (left + right) / 2);

		while(left <= right){



			while( StrCmp(middle, *(pToStr + left)) == 1) 
				left++;

			while( StrCmp(middle, *(pToStr + right)) == 2)
				right--;

			if(left <= right){

				char* temp = *(pToStr + left);

				*(pToStr + left) = *(pToStr + right);

				*(pToStr + right) = temp;

				left++;
				right--;
			}
		}

		TextSort(pToStr, begin, right);
		TextSort(pToStr, left,  end);
	}
}

//-----------------------------

void Test_TextSort(){

	char** pToStr = (char**) calloc(5, sizeof(*pToStr));

	*(pToStr + 0) = "e";
	*(pToStr + 1) = "d";
	*(pToStr + 2) = "c";
	*(pToStr + 3) = "b";
	*(pToStr + 4) = "a";

	TextSort(pToStr, 0, 4);

	int i = 0;
	for(i = 0; i < 5; i++){

		printf("%s", *(pToStr + i));
	}

	printf("\n");

	free(pToStr);

	return;
}

//-----------------------------

int StrCmp(char* str1, char* str2){

	int s1 = 0, s2 = 0;
	for(s1 = 0, s2 = 0; ; s1++, s2++){

		if( !isLetter(str1[s1]) && str1[s1] != '\0'){

			s2--;
			continue;
		}

		if( !isLetter(str2[s2]) && str2[s2] != '\0'){

			s1--;
			continue;
		}

		if(str1[s1] == '\0' && str2[s2] == '\0')
			return 0;

		if(str1[s1] == '\0')
			return 1;

		if(str2[s2] == '\0')
			return 2;

		if(Upper(str1[s1]) - Upper(str2[s2]) > 0)
			return 1;

		if(Upper(str1[s1]) - Upper(str2[s2]) < 0)
			return 2;
	}
}

//----------------------------

int Test_StrCmp(){

	char* str1 = "aaaaaa";
	char* str2 = "aaaaaa";

	if(StrCmp(str1, str2) == 0)
		return 1;
	else
		return 0;

	str1 = "aaaaa";
	str2 = "aaaaaa";

	if(StrCmp(str1, str2) == 2)
		return 1;
	else
		return 0;

	str1 = "aaaaaa";
	str2 = "aaaaaz";

	if(StrCmp(str1, str2) == 2)
		return 1;
	else
		return 0;

	str1 = "aaaaaa";
	str2 = "zzzzz";

	if(StrCmp(str1, str2) == 1)
		return 1;
	else
		return 0;

	str1 = "a.a.a/a6a7a";
	str2 = "a a4a a*a5a";

	if(StrCmp(str1, str2) == 0)
		return 1;
	else
		return 0;
}

//----------------------------

int isLetter(char ch){

	if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
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

int Upper(char ch){

	if( !isLetter(ch) )
		return -1;

	if(ch >= 'a' && ch <= 'z')
		return ch - ('a' - 'A');

	return ch;
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