#pragma once
#include <iostream>
#include <io.h>
#include <string>
#include <unordered_set>

void searchDir(const std::string& path, std::unordered_set<std::string>subFiles)
{
	std::string matchFile = path + "\\" + "*.*";
	_finddata_t fileAttr;
	long handle = _findfirst(matchFile.c_str(), &fileAttr);
	if (handle == -1)
	{
		perror("search failed!");
		std::cout << matchFile << std::endl;
		return;
	}
	do
	{
		if (fileAttr.attrib & _A_SUBDIR)
		{
			//当前为目录，继续搜索
			searchDir(path + "\\" + fileAttr.name, subFiles);
		}
		else
		{
			subFiles.push_back(file)
		}
	} while (_findnext(handle, &fileAttr) == 0)

}

void deleteFile(const char* filename)
{
	if (remove(filename) == 0)
	{
		std::cout << "dele file:" << filename << "success!" << std::endl;
	}
	else
	{
		perror("失败");
	}
}
