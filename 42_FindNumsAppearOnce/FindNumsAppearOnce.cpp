class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int size = data.size();
        
        int num = 0;
        for (int i = 0; i < size; ++i)
        {
            num ^= data[i];
        }
        
 		//找到最后一位不为0的位置
        //形似000..11..10000
        int x = 1;
  		while ((num & x) == 0)
        {
            x <<= 1;
        }
        
        
        *num1 = 0;
        *num2 = 0;
        for (int i = 0; i < size; ++i)
        {
            if (data[i] & x)
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
};
