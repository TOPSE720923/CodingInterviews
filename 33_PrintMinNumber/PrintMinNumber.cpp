#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
	static bool compare(const string& s1, const string& s2)
	{
		return s1 + s2 < s2 + s1;
	}



	string PrintMinNumber(vector<int>& numbers)
	{
		vector<string> v;
		for (int i = 0; i < (int)numbers.size(); ++i)
		{
			stringstream ss;
			ss << numbers[i];
			v.push_back(ss.str());
		}

		sort(v.begin(), v.end(), compare);

		string ret;
		for (int i = 0; i < (int)v.size(); ++i)
		{
			ret += v[i];
		}
		return ret;
	}
};


int main()
{

	int a[] = { 3, 32, 321 };
	vector<int> v(a, a + 3);
	Solution s;

	cout << s.PrintMinNumber(v)<<endl;


	return 0;
}

