#include <iostream>
#include <vector>

using namespace std; 





//法一 
int MoreThanHalfNum_Solution(vector<int>& numbers) 
{
	if (numbers.empty())
		return 0;
	int tmp = numbers[0];
    int count = 1;
    int size = numbers.size();
    for (int i = 1; i < size; ++i)
    {
    	if (numbers[i] == tmp)
            count++;
        else
        {
			count--;
            if (count == 0)
            {
                tmp = numbers[i];
                count = 1;
            }
		}
        
    }
	count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (numbers[i] == tmp)
            count++;
    }
    if (count * 2 > size)
        return tmp;
    else
        return 0;
}

//法二 

//int Partition(vector<int>& v, int beg, int end)
//{
//	
//	int left = beg;
//	int right = end;
//	while (left < right)
//	{
//		while (v[left] < v[end] && left < right)
//		{
//			++left;
//		}
//		while (v[right] > v[end] && left < right)
//		{
//			--right;
//		}
//		swap(v[left++], v[right--]);
//	}
//	swap(v[left], v[end]);
//	return left;
//}
//
//int MoreThanHalfNum_Solution(vector<int>& numbers)
//{
//	int size = numbers.size();
//	int beg = 0;
//	int end = size - 1;
//	int mid = size >> 1;
//	int index = Partition(numbers, beg, end);
//	while (index != mid)
//	{
//		if (index > mid)
//			index = Partition(numbers, beg, index - 1);
//		else
//			index = Partition(numbers, index + 1, end);
//	}
//
//
//	int tmp = numbers[index];
//	int count = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		if (numbers[i] == tmp)
//			count++;
//	}
//	if (count * 2 > size)
//		return tmp;
//	else
//		return 0;
//}


//用map
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
		int size = numbers.size();
		map<int, int> m;
        for (int i = 0; i < size; ++i)
        {
            m[numbers[i]]++;
        }
        map<int, int>::iterator it = m.begin();
        while (it != m.end())
        {
            if (2 * it->second > size)
            {
                return it->first;
            }
            ++it;
        }
        return 0;
    } 

