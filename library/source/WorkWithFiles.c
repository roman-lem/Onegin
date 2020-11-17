#include "WorkWithFiles.h"

//---------------------------

int sizeOfFile(char* fileName){

	struct stat stBuf;
	
	if(stat(fileName, &stBuf) == -1){

		return -1;
	}

	return stBuf.st_size;
}

//---------------------------

char** ReadInBuf(char** pToStr, char* fileBuf, char* fileName, int* nOfStr){

	FILE *Text = fopen(fileName, "r");

	if(Text == NULL){

		printf("Check existing of file \"%s\"\n", fileName);

		return pToStr;
	}

	int TextSize = sizeOfFile(fileName);

	if(TextSize == -1){

		printf("Imposible to identify size of file %s\n", fileName);
	}

	fileBuf = (char*) calloc(TextSize + 1, sizeof(*fileBuf));
	
	fread(fileBuf, sizeof(char), TextSize, Text);

	fclose(Text);

	pToStr = (char**) calloc(1, sizeof(*pToStr));

	if(pToStr == NULL){

		printf("Dont possible to give memory for array of pointers\n");

		return pToStr;
	}

	*(pToStr) = fileBuf;

	int i = 0, p = 1;
	for(i = 0; i < TextSize; i++){

		if(*(fileBuf + i) == '\n'){

			*(fileBuf + i) = '\0';

			pToStr = (char**) realloc(pToStr, (p + 1) * sizeof(*pToStr));

			*(pToStr + p++) = fileBuf + (i + 1);
		}
	}

	*nOfStr = p - 1;

	return pToStr;
}

//----------------------------

void Test_ReadInBuf(){

	char* InputText = "Test_RIB_Input.txt";
	char* OutputText = "Test_RIB_Output.txt";

	FILE *Text = fopen(InputText, "r");

	if(Text == NULL){

		printf("Oops, smth is wrong. Check existing of file \"%s\"\n", InputText);

		return;
	}

	struct stat stBuf;
	
	if(stat(InputText, &stBuf) == -1){

		printf("Oops, smth is wrong, stat returned (-1)\n");

		return;
	}

	int fileSize = stBuf.st_size;

	char* fileBuf = (char*) calloc(fileSize, sizeof(char));

	if(fileBuf == NULL){

		printf("Dont possible to give memory for buffer of file\n");

		return;
	}

	char** pToStr = (char**) calloc(1, sizeof(*pToStr));

	if(pToStr == NULL){

		printf("Dont possible to give memory for array of pointers\n");

		return;
	}

	int nOfStr = 0;

	pToStr = ReadInBuf(pToStr, fileBuf, InputText, &nOfStr);

	PutToFile(OutputText, pToStr, nOfStr);

	free(fileBuf);

	free(pToStr);

	fclose(Text);

	return;
}

//----------------------------

int StrIsEmpty(char* str){

	int i = 0;
	int flag = 1;
	for(i = 0; *(str + i) != '\0'; i++){

		if( isLetter(*(str + i)) ){

			flag = 0;

			break;
		}
	}

	return flag;
}

//----------------------------

void PrintFromArr(char** pToStr, int nOfStr){

	int i = 0;
	for(i = 0; i < nOfStr; i++){

		printf("%s\n", *(pToStr + i));
	}
}

//-----------------------------

void Test_PrintFromArr(){

	char** pToStr = (char**) calloc(5, sizeof(*pToStr));

	*(pToStr + 0) = "a";
	*(pToStr + 1) = "b";
	*(pToStr + 2) = "c";
	*(pToStr + 3) = "d";
	*(pToStr + 4) = "e";

	PrintFromArr(pToStr, 5);

	free(pToStr);

	return;
}

//-----------------------------

void PutToFile(char* fileName, char** pToStr, int nOfStr){

	FILE *file = fopen(fileName, "w");

	int i = 0;
	char flag = 0;
	for(i = 0; i < nOfStr; i++){

		if( !StrIsEmpty(*(pToStr + i)) ){
			fputs(*(pToStr + i), file);
			fputc('\n', file);
		}
	}

	fclose(file);
}

//-----------------------------

void Test_PutToFile(){

	char** pToStr = (char**) calloc(5, sizeof(*pToStr));

	*(pToStr + 0) = "a";
	*(pToStr + 1) = "b";
	*(pToStr + 2) = "c";
	*(pToStr + 3) = "d";
	*(pToStr + 4) = "e";

	PutToFile("Test_PutToFile.txt", pToStr, 5);

	free(pToStr);

	return;
}