
//红黑树的multiset
 
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int>& v, int k)
	{
		multiset<int, greater<int>> m;
		auto vi = v.begin();
		while (vi != v.end())
		{
			int size = m.size();
			if (size < k)
			{
				m.insert(*vi);
			}
			else
			{
				auto beg = m.begin();
				
				if (*vi < *beg)
				{
					//cout << *beg << endl;
					m.erase(beg);

					m.insert(*vi);
				}
			}
			++vi;
		}
		//auto mi = m.begin();
		//while (mi != m.end())
		//{
		//	cout << *mi++ << endl;
		//}
		return vector<int>(m.begin(), m.end());
	}

};



//最大堆做 
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int>& input, int k)
//	{
//		vector<int> v;
//		int sz = input.size();
//		if (sz < k)
//			return v;
//		Heap(input, k);
//		for (int i = k; i < sz; ++i)
//		{
//			if (input[i] < input[0])
//			{
//				input[0] = input[i];
//				Down(input, k, 0);
//			}
//		}
//		for (int i = 0; i < k; ++i)
//		{
//			v.push_back(input[i]);
//		}
//		return v;
//	}
//
//	void Heap(vector<int>& v, int sz)
//	{
//		int size = sz;
//		for (int i = (size - 1 - 1) / 2; i >= 0; --i)
//		{
//			Down(v, sz, i);
//		}
//
//	}
//
//	void Down(vector<int>& v, int sz, int parent)
//	{
//		int child = 2 * parent + 1;
//		int size = sz;
//		while (child < size)
//		{
//			if (child + 1 <size && v[child + 1] > v[child])
//				++child;
//			if (v[child] > v[parent])
//			{
//				swap(v[child], v[parent]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//
//		}
//	}
//};
//

int main()
{
	int a[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	Solution s;
	vector<int> temp = s.GetLeastNumbers_Solution(v, 2);
	for (size_t i = 0; i < temp.size(); ++i)
	{
		cout << temp[i] << endl;
	}


	return 0;
}
