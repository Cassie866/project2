#pragma once
#include "fileManager.h"
#include <iostream>

class FileManagerTool
{
public:
	void sacnner();
	void deletebyMD5();
	void deletebyName();
	void deleteAllCopy();
	void deleteFuzzMatchCopy();
	void showCopy();
	void showAllFiles();
private:
	FileManager _fm;
};