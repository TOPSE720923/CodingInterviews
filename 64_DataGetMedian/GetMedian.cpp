class Solution {
    
public:
    Solution()
        : count (0) {}
    
    void Insert(int num)
    {
    	if (count % 2 == 0)
            p.push(num);
        else
            q.push(num);
        count++;
        
        if (!p.empty() && !q.empty())
        {
			int pMax = p.top();
            int qMin = q.top();
            
            if (pMax > qMin)
            {
                p.pop();
                q.pop();
                
                p.push(qMin);
                q.push(pMax);
            }
        }
        
    }

    double GetMedian()
    { 
        if (count == 0)
            ; //抛出异常，或者其他处理
    	if (count % 2 == 0)
            return (p.top() + q.top()) / 2.0;
        else
            return p.top();
    }

private:
	priority_queue<int, vector<int>, less<int> > p; //大堆
??? priority_queue<int, vector<int>, greater<int> > q; //小堆
    int count;//统计总共数字的个数，即两堆大小的和
};