#include <iostream>

#include "MD5.h"
using namespace std;


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


string MD5::Change(uint32 n)
{
	static string strmap = "0123456789abcdef";
	string ret;
	//获取每一个字节数据
	for (int i = 0; i < 64; ++i)
	{
		int cur = (n >> (i * 8)) & 0xff;
		//数据转成16进制字符
		string curR;
		//除以16获取高位，模16获取低位,字节内不逆序
		curR += strmap[cur / 16];
		curR += strmap[cur % 16];
		ret += curR;
	}
	return ret;	
}


string MD5::GetstringMD5(const string& str)
{}




string MD5::GetFilesMD5(const char* f)
{}



//long GetFileSize(const std::string& file_name)
//{
//	std::ifstream in(file_name.c_str());
//	in.seekg(0, std::ios::end);
//	long size = in.tellg();
//	in.close();
//	return size;
//}
//
////1.添加填充位，添加bit长度
//long Add(long length)
//{
//	int yushu = length % 512;
//	int weishu = 0;
//	//计算需要填充的位数
//	if (yushu < 448)
//	{
//		weishu = 512 - yushu - 64;
//	}
//	else
//	{
//		weishu = 512 + 512 - yushu - 64;
//	}
//
//	return weishu;
//	//文件按位填充b位，第一位填充1，其余为0
//   //在文件后面再追加64位，填充原始文件长度
//}
//
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