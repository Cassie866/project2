
#include "Tool.h"

void FileManagerTool::sacnner()
{
	std::cout << "请输入要扫描的文件夹：" << std::endl;
	std::string path;
	getline(std::cin, path);
	_fm.scanDisk(path);
}

void FileManagerTool::deletebyMD5()
{
	std::cout << "请输入要删除文件的MD5值：" << std::endl;
	std::string md5;
	std::cin >> md5;
	_fm.deleteByMD5(md5);
}

void FileManagerTool::deletebyName()
{
	std::cout << "请输入要删除的文件名：" << std::endl;
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
	std::cout << "请输入匹配文件名：" << std::endl;
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