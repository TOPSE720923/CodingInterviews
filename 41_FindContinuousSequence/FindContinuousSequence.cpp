class Solution {
public:
   vector<vector<int> > FindContinuousSequence(int sum)
	{
		int end = (sum >> 1) + 1;
		int first = 1;
		int second = 2;

		int mySum = first + second;
		vector<vector<int> > vv;


		while (first <= end - 1 && second <= end)
		{
			if (mySum < sum)
			{
				++second;
				mySum += second;
			}
			else if (mySum > sum)
			{
				mySum -= first;
				first++;
			}
			else
			{
				vector<int> v;
				for (int i = first; i <= second; ++i)
					v.push_back(i);
				vv.push_back(v);
				
				second++;
				mySum += second;
			}
		}

		return vv;
	}

    
    
    void PushBackInV(vector<vector<int> >& v, int index, int beg, int end)
    {
        for (int i = beg; i <= end; ++i)
            v[index].push_back(i);
    }
};