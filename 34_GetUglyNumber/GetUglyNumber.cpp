//class Solution {
//public:
//	int GetUglyNumber_Solution(int index)
//	{
//		if (index <= 6)
//			return index;
//
//		vector<int> v;
//		v.resize(index + 1, 0);
//		for (int i = 1; i <= 6; i++)
//		{
//			v[i] = i;
//		}
//
//		int n2 = 0; 
//		int n3 = 0; 
//		int n5 = 0; 
//
//		for (int i = 7; i <= index; ++i)
//		{
//			int size = i;
//			bool flag2 = true;
//			bool flag3 = true;
//			bool flag5 = true;
//
//			for (int j = 1; j < size; ++j)
//			{
//			
//				if (flag2 && 2 * v[j] > v[size - 1])
//				{
//					n2 = 2 * v[j];
//					flag2 = false;
//					break;
//				}
//
//				if (flag3 && 3 * v[j] > v[size - 1])
//				{
//					n3 = 3 * v[j];
//					flag3 = false;
//				}
//				if (flag5 && 5 * v[j] > v[size - 1])
//				{
//					n5 = 5 * v[j];
//					flag5 = false;
//				}
//
//			}
//			v[i] = FindMin(n2, n3, n5);
//		}
//
//		return v[index];
//	}
//
//	int FindMin(int a, int b, int c)
//	{
//		return min(min(a, b), c);
//	}
//};


class Solution {
public:
	int GetUglyNumber_Solution(int index)
	{
		if (index <= 0)
			return 0;
		if (index == 1)
			return 1;

		vector<int> v(index + 1, 0);
		v[1] = 1;

		int index2 = 1;
		int index3 = 1;
		int index5 = 1;

		for (int i = 2; i <= index; ++i)
		{
			v[i] = min(min(2 * v[index2], 3 * v[index3]), 5 * v[index5]);
			if (v[i] == 2 * v[index2])
				index2++;
			if (v[i] == 3 * v[index3])
				index3++;
			if (v[i] == 5 * v[index5])
				index5++;
		}	
		return v[index];
	}


	
};



int main()
{
	Solution s;
	cout << s.GetUglyNumber_Solution(8) << endl;
	


	return 0;
}
