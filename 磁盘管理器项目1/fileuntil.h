#pragma once
#include <iostream>
#include <io.h>
#include <string>
#include <unordered_set>


//ɨ�����
void searchDisk(const std::string& path, std::unordered_set<std::string>subFiles);

//ɾ���ļ�
void deleteFile(const char* filename);