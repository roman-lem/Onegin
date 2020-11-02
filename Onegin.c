#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "./library/WorkWithFiles.h"
#include "./library/SortText.h"

/**
	* @mainpage Onegin
	*
	*	@author Roman Lem
	*
	*	@version 1.0
	*
	*	@brief This program can sort text files alphabetically.
	*/

int main(){

	char* InputText = "./sours/Onegin.txt";
	char* OutputText = "Sorted.txt";

  FILE *Text = fopen(InputText, "r");

  if(Text == NULL){

  	printf("Oops, smth is wrong. Check existing of file \"%s\"\n", InputText);

  	return 0;
  }

	struct stat stBuf;
	
	if(stat(InputText, &stBuf) == -1){

		printf("Oops, smth is wrong, stat returned (-1)\n");

		return 0;
	}

	int fileSize = stBuf.st_size;

	char* fileBuf = (char*) calloc(fileSize, sizeof(char));

	if(fileBuf == NULL){

		printf("Dont possible to give memory for buffer of file\n");

		return 0;
	}

	char** pToStr = (char**) calloc(1, sizeof(*pToStr));

	if(pToStr == NULL){

		printf("Dont possible to give memory for array of pointers\n");

		return 0;
	}

	int nOfStr = 0;

	pToStr = ReadInBuf(pToStr, fileBuf, Text, &nOfStr);

  TextSort(pToStr, 0, nOfStr);

  PutToFile(OutputText, pToStr, nOfStr);

	free(fileBuf);

	free(pToStr);

	fclose(Text);

  return 0;
}