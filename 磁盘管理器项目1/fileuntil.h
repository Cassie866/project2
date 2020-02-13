#pragma once
#include <iostream>
#include <io.h>
#include <string>
#include <unordered_set>


//É¨Ãè´ÅÅÌ
void searchDisk(const std::string& path, std::unordered_set<std::string>subFiles);

//É¾³ıÎÄ¼ş
void deleteFile(const char* filename);