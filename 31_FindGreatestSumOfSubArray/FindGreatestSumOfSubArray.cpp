class Solution
{
public:
	int FindGreatestSumOfSubArray(const vector<int>& array)
	{
		if (array.empty())
		{
			_isValid = false;
			return 0;
		}

		int sum = 0;
		int max = 0x80000000;
		int size = array.size();
		for (int i = 0; i < size; ++i)
		{
			if (sum <= 0)
			{
				sum = array[i];
			}
			else
			{
				sum += array[i];
			}
			if (sum > max)
				max = sum;
		}
		_isValid = true;
		return max;
	}

	bool _isValid;
};

int main()
{
	vector<int> a = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Solution s;
	cout << s.FindGreatestSumOfSubArray(a);
	return 0;
}

