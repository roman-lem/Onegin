#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
	* @brief This func read text from file, and write it to buffer
	*
	*	@param pToStr - Array of pointers on strings
	*
	*	@param fileBuf - Buffer
	*
	*	@param file - File 
	*
	* @param nOfStr - Pointer on variable, where need save number of strings
	*
	* @return New pointer on array of pointers
	*/
char** ReadInBuf(char** pToStr, char* fileBuf, FILE *file, int* nOfStr);

/**
	* @brief Unit test for ReadInBuf()
	*
	*	@note First of all, check that PutToFile() work correctly
	*
	* @note Create file "Test_RIB_Input.txt" and fill it. If was created "Test_RIB_Output.txt" with same content
	*/

void Test_ReadInBuf();

/**
	* @brief This func print strings from pToStr
	*
	*	@param pToStr - Array of pointers on strings
	*
	* @param nOfStr - Number of strings, that need to print
	*/

void PrintFromArr(char** pToStr, int nOfStr);

/**
	* @brief Unit test for PrintFromArr()
	*
	* @return if this func work correctly, it will print "a\nb\nc\nd\ne\n"
	*/

void Test_PrintFromArr();

/**
	* @brief This func write text in file
	*
	*	@param fileName - Name of file
	*
	*	@param pToStr - Array of pointers on strings
	*
	* @param nOfStr - Number of strings, that need to write
	*/

void PutToFile(char* fileName, char** pToStr, int nOfStr);

/**
	* @brief Unit test for PutToFile()
	*
	* @return if this func work correctly, it will create file "Test_PutToFile.txt" and put "a\nb\nc\nd\ne\n" to it
	*/

void Test_PutToFile();