#include "file.h"
#include "fileM.hpp"


void FileManager::scannerDir(const std::string& path)
{
	//清理容器
	_files.clear();

	searchDir(path, _files);
	getMd5toFiles();
	getCopyList();


}

void FileManager::getMd5toFiles()
{
	md5toFiles.clear();
	for (const auto& f : _files)
	{
		_md5
	}
}
void FileManager::getCopyList();





//所有的删除，保证一个文件不存在副本
void FileManager::deleteByName(const std::string& name)
{
}

void FileManager::deleteByMD5(const std::string& md5)
{
}
void FileManager::deleteAllCopy()
{
}
void FileManager::deleteByMatchName(const std::string& matchName)
{
}