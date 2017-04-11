#include <iostream>

using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if (n <= 0)
            return 0;
       	else if (n <= 9)
            return 1;
        
        int count = 0;
        int base = 1;
        
        int round = n;
        int weight = 0;
      
      	//534
      	//base = 1, 53 * 1 + 1
		//base = 10, 5 * 10 + 10
      	//base = 100, 0 * 100 + 100
      
      	//count = 54 + 60 + 100
        while (round > 0)
        {
            weight = round % 10;
            round /= 10;
            
            count += round * base;
            
            if (weight == 1)
            {
                count += n % base + 1;
            } 
            else if (weight > 1)
            {
                count += base;
            }
 			    
            base *= 10;
        }
        return count;
       
    }
};


int main()
{
	
	Solution s;
	cout << s.NumberOf1Between1AndN_Solution(534) << endl;
	return 0;
}



