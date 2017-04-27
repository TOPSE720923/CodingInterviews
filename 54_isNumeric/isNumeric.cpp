class Solution {
inline bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';

    }
	//�ж������� 1e-2  1e+2 �Ƿ�Ϸ�����e�ַ���ʼcheck 
    bool checkE(char* string, int& index, int size)
    {
        
         ++index; //����e����E 
        if (index  == size) //e������E����û���ַ��˲��Ϸ� 
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

            if (string[index] == '.') //����С����. ����ʼ�ж� 
            {
                ++index;
                if (index == size) //С�����û�����ˣ����Ϸ� 
                    return false;
                    
                while (index < size && isDigit(string[index]))
                    ++index;
                if (index == size) //1.22662�Ϸ� 
                {
                    return true;
                }
                else //1.226e+2������� 
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
