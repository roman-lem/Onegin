#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "./library/WorkWithFiles.h"
#include "./library/SortText.h"

/**
	* @mainpage Onegin
	*
	* @author Roman Lem
	*
	* @version 1.0
	*
	* @brief This program can sort text files alphabetically.
	*/

int main(){

	char* InputText = "./sours/Onegin.txt";
	char* OutputText = "Sorted.txt";

	char* fileBuf = NULL;

	char** pToStr = NULL;

	int nOfStr = 0;
	
	pToStr = ReadInBuf(pToStr, fileBuf, InputText, &nOfStr);

	qsort(pToStr, nOfStr, sizeof(*pToStr), StrCmp);

	PutToFile(OutputText, pToStr, nOfStr);

	free(fileBuf);

	free(pToStr);

	return 0;
}