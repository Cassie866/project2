#include "file.h"
#include "fileM.hpp"


void FileManager::scannerDir(const std::string& path)
{
	//��������
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





//���е�ɾ������֤һ���ļ������ڸ���
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