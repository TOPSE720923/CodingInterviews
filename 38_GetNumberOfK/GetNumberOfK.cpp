class Solution {
public:
    int GetNumberOfK(vector<int> v ,int k) {
		if (v.empty())
            return ;
        int first = GetFirstIndex(v, k);
		int last = GetLastIndex(v, k);
        
        int count = 0;
        if (first != -1 && last != -1)
            count = last - first + 1;
        return count;
        
        
        
    }
    
    int GetFirstIndex(const vector<int>& v, int x)
    {
        int left = 0;
        int right = v.size()-1;
        
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (v[mid] < x)
                left = mid + 1;
            else if (v[mid] > x)
                right = mid - 1;
            else
            {
                if (mid == 0 || v[mid-1] != x)
                    return mid;
                else
                    right = mid - 1;
            }
                
        }
        return -1;
    }
    
    int GetLastIndex(const vector<int>& v, int x)
    {
        int left = 0;
        int right = v.size()-1;
        
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if (v[mid] < x)
                left = mid + 1;
            else if (v[mid] > x)
                right = mid - 1;
            else
            {
                if (mid == v.size()-1 || v[mid+1] != x)
                    return mid;
                else
                    left = mid + 1;
            }
                
        }
        return -1;
    }
};
