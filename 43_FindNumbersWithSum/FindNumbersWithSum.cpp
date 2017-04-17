class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int left = 0;
        int right = array.size() - 1;
        
        vector<int> v;
        
        while (left < right)
        {
            if (array[left] + array[right] > sum)
                --right;
            else if (array[left] + array[right] < sum)
                ++left;
            else
            {
                v.push_back(array[left]);
                v.push_back(array[right]);
    			break;
            }
        }
        
       
        return v;
    }
};
