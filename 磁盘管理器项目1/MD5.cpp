#include <iostream>
#include <fstream>

#include "MD5.h"



//初m始化static成员
int MD5::s[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,  12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

MD5::MD5()
{
	Init();
}


void MD5::Init()
{
	for (int i = 0; i < 64; ++i)
	{
		k[i] = (uint32)(abs(sin(i + 1.0)) * pow(2.0, 32));
	}
	Reset();
}


void MD5::Reset()
{
	_a = 0x67452301; 
	_b = 0xefcdab89; 
	_c = 0x98badcfe; 
	_d = 0x10325476;
	memset(_chunk, 0, 64);
	lastByte = 0;
	allBytes = 0;
}


void MD5:: CalMD5(uint32* chunk)
{
	int a = _a, b =_b, c =_c, d = _d;
	int m, g;

	for (int i = 0; i < 64; i++)
	{
		if (0 <= i && i < 16)
		{
			m=F(b, c, d);
			g = i;
		}
		else if (i < 32)
		{
			m = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i < 48)
		{
			m = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else
		{
			m = I(b, c, d);
			g = (7 * i) % 16;
		}
		int temp = d;
		d = c;
		c = b;
		b = b + LeftShift((a + m + k[i] + chunk[g]), s[i]);
		a = temp;
	}
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}


void MD5::CalFinalMD5()
{
	char* p = _chunk + lastByte;
	*p++ = 0x80;
	int remain = 64 - lastByte - 1;
	if (remain < 8)
	{
		memset(p, 0, remain);
		CalMD5((uint32*)_chunk);
		memset(_chunk, 0, 64);
	}
	else
	{
		memset(p, 0, remain);
	}
	unsigned long long allBites = allBytes;
	allBites *= 8;
	((unsigned long long*)_chunk)[7] = allBites;
	CalMD5((uint32*)_chunk);
}


std::string MD5::Change(uint32 n)
{
	static std::string strmap = "0123456789abcdef";
	std::string ret;
	//获取每一个字节数据
	for (int i = 0; i < 4; ++i)
	{
		int cur = (n >> (i * 8)) & 0xff;
		//数据转成16进制字符
		std::string curR;
		//除以16获取高位，模16获取低位,字节内不逆序
		curR += strmap[cur / 16];
		curR += strmap[cur % 16];		
		ret += curR;
	}
	return ret;	
}


std::string MD5::GetstringMD5(const std:: string& str)
{
	if (str.empty())
	{
		Change(_a).append(Change(_b)).append(Change(_c)).append(Change(_d));
	}
	allBytes = str.size();
	uint32 chunknum = allBytes / 64;
	const char* strptr = str.c_str();
	for (int i = 0; i < chunknum; ++i)
	{
		memcpy(_chunk, strptr + i * 64, 64);
		CalMD5((uint32*)_chunk);
	}
	lastByte + allBytes % 64;
	memcpy(_chunk, strptr + chunknum * 64, lastByte);
	CalFinalMD5();
	return Change(_a).append(Change(_b)).append(Change(_c)).append(Change(_d));
}




std::string MD5::GetFilesMD5(const char* filePath)
{
	std::ifstream fin(filePath,std::ifstream::binary);
	if (!fin.is_open())
	{
		std::cout << filePath;
		perror("file open failed!");
		return "";
	}
	while (!fin.eof())
	{
		/*//全部读进来，空间换时间
		fin.seekg(0, fin.end);
		uint32 length = fin.tellg();
		fin.seekg(0, fin.beg);
		char* allData = new char[length];
		fin.read(allData, length);*/

		//每次读取一块数据 时间换空间
		fin.read(_chunk, 64);
		if (64 != fin.gcount())
		{
			break;
		}
		allBytes += 64;
		CalMD5((uint32*)_chunk);
	}
	lastByte = fin.gcount();
	allBytes += lastByte;
	CalFinalMD5();
	return Change(_a).append(Change(_b)).append(Change(_c)).append(Change(_d));
}





//int main()
//{
//	long size = GetFileSize("1.txt");
//	long length = size * 8;
//	long weishu=Add(length);
//	ofstream file;
//	file.open("1.txt", ios::ate|ios::binary);
//	file.close();
//	return 0;
//}