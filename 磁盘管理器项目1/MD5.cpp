#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//class MD5
//{
//	MD5()
//		:A(0x67452301),B(0xefcdab89),C(0x98badcfe),D(0x10325476)
//	{
//		a = A;
//		b = B;
//		c = C;
//		d = D;
//		for (int i=0;i<64;++i)
//		{
//			k[i] = (size_t)(abs(sin(i + 1)) * pow(2, 32));
//		}
//		for (int i = 0; i < 16; i+=4)
//		{
//			s[i] = 7;
//			s[i + 1] = 12;
//			s[i + 2] = 17;
//			s[i + 3] = 22;
//		}
//		for (int i = 16; i < 32; i += 4)
//		{
//			s[i] = 5;
//			s[i + 1] = 9;
//			s[i + 2] = 14;
//			s[i + 3] = 20;
//		}
//		for (int i = 32; i < 48; i += 4)
//		{
//			s[i] = 4;
//			s[i + 1] = 11;
//			s[i + 2] = 16;
//			s[i + 3] = 23;
//		}
//		for (int i = 48; i < 64; i += 4)
//		{
//			s[i] = 6;
//			s[i + 1] = 10;
//			s[i + 2] = 15;
//			s[i + 3] = 21;
//		}
//	}
//
//	//处理函数
//	int F(int& x, int& y, int& z)
//	{
//		return   (x & y) | ((~x) & z);
//	}
//
//	int G(int& x, int& y, int& z)
//	{
//		return   (x & z) | (y & (~z));
//	}
//
//	int H(int& x, int& y, int& z)
//	{
//		return    x ^ y ^ z;
//	}
//
//	int I(int& x, int& y, int& z)
//	{
//		return   y ^ (x | (~z));
//	}
//
//	void Add(long length);
//
//private:
//	int A;
//	int B;
//	int C;
//	int D;
//	int a;
//	int b;
//	int c;
//	int d;
//	std::vector<long>k;
//	std::vector<int>s;
//};
//
//
//
//
//
//
//
//
//
//
////3.按512位数据逐块处理输入信息
////分成大小为512的块
//
//
//
//
//
////
//void Chunk(int m)
//{
//	
//}
//
//
//
//
////F函数处理
//void Fc()
//{
//	int f = 0;
//	int m = 0;
//	for (int j = 0; j < 16; ++j)
//	{
//		m = j;
//		f = F(b, c, d);
//		d = c;
//		c = b;
//		b = b + (a + f + k[i] + chunk[m])<<s[i];
//		a = d;
//	}
//}
//
//void Gc()
//{
//	int g = 0;
//	int m = 0;
//	for (int j = 16; j < 32; ++j)
//	{
//		g = G(b, c, d);
//		d = c;
//		c = b;
//		b = b + shift((a + g + k[i] + chunk[(5 * i + 1) % 16]), s[i]);
//		a = d;
//	}
//}
//
//void Hc()
//{
//	int h = 0;
//	int m = 0;
//	for (int j = 32; j < 47; ++j)
//	{
//		h = H(b, c, d);
//		d = c;
//		c = b;
//		b = b + shift((a + h + k[i] + chunk[(3 * i + 5) % 16]), s[i]);
//		a = d;
//	}
//}
//
//void Ic()
//{
//	int i= 0;
//	int m = 0;
//	for (int j = 48; j < 63; ++j)
//	{
//		i = I(b, c, d);
//		d = c;
//		c = b;
//		b = b + shift((a + i + k[i] + chunk[(7 * i) % 16]), s[i]);
//		a = d;
//	}
//}




//4.摘要输出





long GetFileSize(const std::string& file_name)
{
	std::ifstream in(file_name.c_str());
	in.seekg(0, std::ios::end);
	long size = in.tellg();
	in.close();
	return size;
}

//1.添加填充位，添加bit长度
long Add(long length)
{
	int yushu = length % 512;
	int weishu = 0;
	//计算需要填充的位数
	if (yushu < 448)
	{
		weishu = 512 - yushu - 64;
	}
	else
	{
		weishu = 512 + 512 - yushu - 64;
	}

	return weishu;
	//文件按位填充b位，第一位填充1，其余为0
   //在文件后面再追加64位，填充原始文件长度
}

int main()
{
	long size = GetFileSize("1.txt");
	long length = size * 8;
	long weishu=Add(length);
	ofstream file;
	file.open("1.txt", ios::ate|ios::binary);
	

	file.close();




	return 0;




}