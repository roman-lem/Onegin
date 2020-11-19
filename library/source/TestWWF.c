#include "TestWWF.h"

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

int Test_StrIsEmpty(){

	if(!StrIsEmpty(""))
		return 1;

	if( StrIsEmpty("aabb"))
		return 1;

	if(!StrIsEmpty("1234567890!@#$%^&*()-_=+[{]}\\|'\";:/?.>,<"))  //this is all suspicious symbols
		return 1;

	return 0;
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

//===============================================================================================================================