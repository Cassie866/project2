#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
#include  "MD5.h"

class FileManager
{
public:
	void scanDisk(const std::string& path);
	void getMd5toFiles();
	void getCopyList();

	//���е�ɾ��Ҫ��֤һ���ļ������ڸ���
	void deleteByName(const std::string& name);
	void deleteByMD5(const std::string& md5);
	void deleteAllCopy();
	void deleteByMatchName(const std::string& matchName);

	void showCopyList();
	void showAllFile();

private:
	std::unordered_set<std::string> _files;
	std::unordered_multimap<std::string, std::string>_md5toFiles;
	std::unordered_map<std::string, std::string>_filestoMd5;
	MD5 _md5;
};