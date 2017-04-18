
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string ReverseSentence(string s) 
{
	reverse(s.begin(), s.end());

	int size = s.size();
	int beg = 0;
	for (int end = 0; end <= size; ++end)
	{
		if (end == size)
		{
			reverse(s.begin() + beg, s.begin() + end);
			break;
		}

		if (s[end] == ' ')
		{
			reverse(s.begin() + beg, s.begin() + end);
			beg = ++end;
		}
	}

	return s;
}


int main()
{

	string s = "i am happy";
	ReverseSentence(s); 
	cout << s << endl; 

	return 0;
}
