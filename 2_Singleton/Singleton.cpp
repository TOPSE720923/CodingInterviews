#include <iostream>

using namespace std;

 
class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new Singleton();
		}
		return _instance;
	}

private:
	Singleton()
	{}

private:
	static Singleton *_instance;
};


int main()
{
	return 0;
} 
