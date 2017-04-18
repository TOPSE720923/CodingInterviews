
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;





int main()
{

	string s = "i am happy";
	//yppah ma i
	reverse(s.begin(), s.end());
	
	string::iterator first = s.begin();
	string::iterator second = s.begin();

	//happy am i
	while (second != s.end())
	{
		if (*second == ' ' || *second == '\0')
		{
			reverse(first, second);
			second++;
			first = second;
		}
		++second;
	}
	cout << s << endl; 

	return 0;
}
