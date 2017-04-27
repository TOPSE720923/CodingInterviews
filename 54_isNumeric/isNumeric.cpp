class Solution {
inline bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';

    }
	//判断类似于 1e-2  1e+2 是否合法，从e字符开始check 
    bool checkE(char* string, int& index, int size)
    {
        
         ++index; //忽略e或者E 
        if (index  == size) //e或者是E后面没有字符了不合法 
             return false;

        if (string[index] == '+' || string[index] == '-')
        {
              ++index;
            if (index == size)
                 return false;
        }   
        while (index < size && isDigit(string[index]))
             ++index;
        if (index == size)
            return true;
        else
            return false;

    }

public:
    bool isNumeric(char* string)
    {
        int size = strlen(string);
        if (size <= 0)
            return false;
 
        int index = 0;
        if (string[0] == '+' || string[0] == '-')
        {
            if (size == 1)
                return false;
            ++index;
        }
        else if (isDigit(string[0]))
        {
            ++index;
        }
        else
        {
            return false;
        }


        while (index < size)
        {
            while (index < size && isDigit(string[index]))
                ++index;
            
            if (index == size)
                return true;

            if (string[index] == '.') //遇到小数点. ，开始判断 
            {
                ++index;
                if (index == size) //小数点后没数字了，不合法 
                    return false;
                    
                while (index < size && isDigit(string[index]))
                    ++index;
                if (index == size) //1.22662合法 
                {
                    return true;
                }
                else //1.226e+2这种情况 
                {
 
                    if (string[index] == 'e' || string[index] == 'E')
                        return checkE(string, index, size);
                    else
                        return false;
                }
            }
            else if (string[index] == 'e' || string[index] == 'E')
            {
                return checkE(string, index, size);
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }

};
