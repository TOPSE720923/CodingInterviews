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
            ; //�׳��쳣��������������
    	if (count % 2 == 0)
            return (p.top() + q.top()) / 2.0;
        else
            return p.top();
    }

private:
	priority_queue<int, vector<int>, less<int> > p; //���
??? priority_queue<int, vector<int>, greater<int> > q; //С��
    int count;//ͳ���ܹ����ֵĸ����������Ѵ�С�ĺ�
};