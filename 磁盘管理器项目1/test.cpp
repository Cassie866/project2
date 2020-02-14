#include <iostream>
#include "MD5.h"


void testchange()
{
	MD5 md5;
	uint32 n = 0x23456789;
	std::cout << md5.Change(n) << std::endl;
}


void testStringMD5()
{
	MD5 md5;
	std::string str = "123456789abcdefg";
	std::cout << md5.GetstringMD5(str) << std::endl;
}


void testFileMD5()
{
	MD5 md5;
	const char* filepath1 = "1.txt";
	const char* filepath2 = "2.txt";
	std::cout << md5.GetstringMD5(filepath1) << std::endl;
	std::cout << md5.GetstringMD5(filepath2) << std::endl;
}


//int main()
//{
//	//testStringMD5();
//	//testFileMD5();
//	//testchange();
//	return 0;
//}