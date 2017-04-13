


class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int sz = str.size();
		if (sz == 0)
			return -1;
		vector<int> v(256, 0);

		for (int i = 0; i < sz; ++i)
		{
			v[str[i]]++;
		}

		for (int i = 0; i < sz; ++i)
		{
			if (v[str[i]] == 1)
				return i;
		}

		return -1;
	}
};


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int sz = str.size();
        if (sz == 0)
            return -1;
        unordered_map<int, int> um;


        for (int i = 0; i < sz; ++i)
        {
            um[str[i]]++;
        }

        for (int i = 0; i < sz; ++i)
        {
            if (um[str[i]] == 1)
                return i;
        }
        return -1;
    }
};
