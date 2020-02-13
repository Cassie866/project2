#include "fileManager.h"
#include "fileuntil.h"


void FileManager::scanDisk(const std::string& path)
{
	_files.clear();
	searchDisk(path, _files);
	getMd5toFiles();
	getCopyList();
}

void FileManager::getMd5toFiles()
{
	_md5toFiles.clear();
	for (const auto& f : _files)
	{
		_md5.Reset();
		_md5toFiles.insert(make_pair(_md5.GetFilesMD5(f.c_str()), f));
	}
}

void FileManager::getCopyList()
{
	_filestoMd5.clear();
	auto it = _md5toFiles.begin();
	while (it !=_md5toFiles.end())
	{
		if (_md5toFiles.count(it->first) > 1)
		{
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second)
			{
				_filestoMd5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			it = pairIt.second;
		}
		else
		{
			_files.erase(it->second);
			it = _md5toFiles.erase(it);
		}
	}
}




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



void FileManager::showCopyList()
{
	
}
void FileManager::showAllFile()
{

}
