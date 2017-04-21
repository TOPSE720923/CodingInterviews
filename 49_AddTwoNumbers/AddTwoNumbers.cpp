int Add(int num1, int num2)
{

	int carryFlag = 0;
	int sum = num1;

	while (num2 != 0)
	{
		sum = num1 ^ num2; //求和不算进位
		carryFlag = (num1 & num2) << 1;//求进位
		
		num1 = sum;
		num2 = carryFlag;
	}
	return sum;
}