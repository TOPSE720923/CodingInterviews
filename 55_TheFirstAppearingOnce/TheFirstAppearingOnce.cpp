class Solution
{
public:
    Solution()
        : s ("")
    {
        for (int i = 0; i < 256; ++i)
            hash[i] = 0;
    }

    void Insert(char ch)
    {
        s.push_back(ch);
        hash[ch]++;
            
    }

     char FirstAppearingOnce()
     {
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (hash[s[i]] == 1)
                return s[i];
        }
        return '#';
     }
private:
     int hash[256];
     string s;

};