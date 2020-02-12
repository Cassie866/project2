#pragma once
#include <string>
typedef unsigned int uint32;

class MD5
{
	MD5();

	//λ���㴦����
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

	//ѭ������
	uint32 LeftShift(uint32 n, int shiftn)
	{
		int m = shiftn % 32;
		return (n << m) | (n >> (32 - m));
	}

	void Init();
	void Reset();

	//һ��chunk��MD5����
	void calMD5(uint32*chunk);

	//��������ٽ��м���
	void calFinalMD5();

	//������ת����16�����ַ���
	string change()



	string getstringMD5(const string& str);
	string getFilesMD5(const char* f);

private:
	static int s[64];//ѭ����λ��λ��
	uint32 k[64];//k[i]	
	char chunk[64];//���ݿ�  64�ֽ�
	
	uint32 lastByte;//���һ�����ݵ��ֽ���	
	uint32 allByte;//�����ֽ�����ת����λ
	
	uint32 _a;   //MD5��Ϣ ABCD
	uint32 _b;
	uint32 _c;
	uint32 _d;
};



