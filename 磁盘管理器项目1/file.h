#pragma once
#include <string>
#include <unordered_set>
#include <unordered_map>
class FileManager
{
public:
	void scannerDir(const std::string& path);
	
	getMd5toFiles();
	getCopyList();


	//所有的删除，保证一个文件不存在副本
	void deleteByName(const std::string& name);
	void deleteByMD5(const std::string& md5);
	void deleteAllCopy();
	void deleteByMatchName(const std::string& matchName);

private:
	std::unordered_set<std::string> _files;
	std::unordered_multimap<std::string, std::string>md5toFiles;
	std::unordered_map<std::string, std::string>_filestoMd5;

	MD5 _md5;
};