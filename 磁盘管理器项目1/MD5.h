#pragma once
#include <string>
typedef unsigned int uint32;

class MD5
{
	MD5();

	//位运算处理函数
	uint32 F(uint32 x, uint32 y, uint32 z)
	{
		return   (x & y) | ((~x) & z);
	}

	uint32 G(uint32 x, uint32 y, uint32 z)
	{
		return   (x & z) | (y & (~z));
	}

	uint32 H(uint32 x, uint32 y, uint32 z)
	{
		return    x ^ y ^ z;
	}

	uint32 I(uint32 x, uint32 y, uint32 z)
	{
		return   y ^ (x | (~z));
	}

	//循环左移
	uint32 LeftShift(uint32 n, int shiftn)
	{
		int m = shiftn % 32;
		return (n << m) | (n >> (32 - m));
	}

	void Init();
	void Reset();

	//一个chunk的MD5运算
	void calMD5(uint32*chunk);

	//进行填充再进行计算
	void calFinalMD5();

	//把整数转换成16进制字符串
	string change()



	string getstringMD5(const string& str);
	string getFilesMD5(const char* f);

private:
	static int s[64];//循环移位的位数
	uint32 k[64];//k[i]	
	char chunk[64];//数据块  64字节
	
	uint32 lastByte;//最后一块数据的字节数	
	uint32 allByte;//总体字节数，转换成位
	
	uint32 _a;   //MD5信息 ABCD
	uint32 _b;
	uint32 _c;
	uint32 _d;
};



