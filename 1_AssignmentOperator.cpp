#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class CMyString
{
public:
	CMyString(const char *pData = nullptr)
	{
		if (pData == nullptr)
		{
			m_pData = new char[1];
			*m_pData = '\0';
		}
		else
		{
			int length = strlen(pData);
			m_pData = new char[length + 1];
			strcpy(m_pData, pData);
		}
	}

	CMyString(const CMyString& other)
		: m_pData(other.m_pData)
	{
		m_pData = new char[strlen(other.m_pData) + 1];
		strcpy(m_pData, other.m_pData);
	}

	CMyString& operator=(const CMyString& other)
	{
		if (this != &other)
		{
			CMyString temp(other);
			swap(temp.m_pData, m_pData);
		}
		return *this;
	}

	~CMyString()
	{
		delete[] m_pData;
		m_pData = nullptr;
	}

	void Print()
	{
		printf("%s\n", m_pData);
	}
private:
	char *m_pData;
};


void Test1()
{
	CMyString str1("hello");
	CMyString str2;
	str2 = str1;
	str2.Print();	
}

// 赋值给自己
void Test2()
{
	const char* text = "Hello world";
	CMyString str1(text);
	str1 = str1;
	str1.Print();
}

// 连续赋值
void Test3()
{
	const char* text = "Hello world";
	CMyString str1(text);
	CMyString str2, str3;
	str2 = str3 = str1;
	str2.Print();
	str3.Print();
}

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}
