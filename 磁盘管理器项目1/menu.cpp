#include "Tool.h"

void testFM()
{
	FileManager fm;
	std::string path = "D:\\fileManagerTestDir";
	fm.scanDisk(path);
}

void menu()
{
	std::cout << "******************************" << std::endl;
	std::cout<<"1ɨ��      2showall     3showcopy    4nameɾ��      5md5ɾ��     6ȫɾ    7ģ��    0�˳�"<<std::endl;
}


void testFileManagerTool()
{
	FileManagerTool fmt;
	int input;
	do
	{
		menu();
		std::string garbage;
		std::cout << "������ѡ��";
		std::cin >> input;
		getline(std::cin,garbage);
		switch (input)
		{
		case 1:
			fmt.sacnner();
			break;
		case 2:
			fmt.showAllFiles();
			break;
		case 3:
			fmt.showCopy();
			break;
		case 4:
			fmt.deletebyName();
			break;
		case 5:
			fmt.deletebyMD5();
			break;
		case 6:
			fmt.deleteAllCopy();
			break;
		case 7:
			fmt.deleteFuzzMatchCopy();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input != 0);
}


int main()
{
	testFileManagerTool();
	return 0;
}