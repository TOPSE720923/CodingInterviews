int Add(int num1, int num2)
{

	int carryFlag = 0;
	int sum = num1;

	while (num2 != 0)
	{
		sum = num1 ^ num2; //��Ͳ����λ
		carryFlag = (num1 & num2) << 1;//���λ
		
		num1 = sum;
		num2 = carryFlag;
	}
	return sum;
}