
void SetNum(vector<int>& v, int n, int index)
{
	if (n == 1)
		v[index]++;
	else
	{
		for (int i = 1; i <= 6; i++)
		{
			SetNum(v, n - 1, index + i);
		}
	}
}


void Fun(int n)
{
	if (n <= 0)
		return;

	vector<int> v(6 * n + 1, 0);
	//һ������
	if (n == 1)
	{
		for (int i = 1; i <= 6; ++i)
		{
			v[i]++;
		}

		for (int i = 0; i < (int)v.size(); ++i)
		{
			cout << i << "���ֵĴ���:" << v[i] << endl;
		}
		return;
	}
	//�������
	for (int i = 1; i <= 6; ++i)
	{
		SetNum(v, n, i);
	}

	for (int i = 0; i < (int)v.size(); ++i)
	{
		cout << i << "���ֵĴ���:" << v[i] << endl;
	}

}



int main()
{
	Fun(3);
	return 0;
}
