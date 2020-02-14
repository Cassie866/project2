
#include "Tool.h"

void FileManagerTool::sacnner()
{
	std::cout << "������Ҫɨ����ļ��У�" << std::endl;
	std::string path;
	getline(std::cin, path);
	_fm.scanDisk(path);
}

void FileManagerTool::deletebyMD5()
{
	std::cout << "������Ҫɾ���ļ���MD5ֵ��" << std::endl;
	std::string md5;
	std::cin >> md5;
	_fm.deleteByMD5(md5);
}

void FileManagerTool::deletebyName()
{
	std::cout << "������Ҫɾ�����ļ�����" << std::endl;
	std::string f;
	getline(std::cin, f);
	_fm.deleteByName(f);
}

void FileManagerTool::deleteAllCopy()
{
	_fm.deleteAllCopy();
}

void FileManagerTool::deleteFuzzMatchCopy()
{
	std::cout << "������ƥ���ļ�����" << std::endl;
	std::string match;
	getline(std::cin, match);
	_fm.deleteByMatchName(match);
}

void FileManagerTool::showCopy()
{
	_fm.showAllFiles();
}


void FileManagerTool::showAllFiles()
{
	_fm.showAllFiles();
}