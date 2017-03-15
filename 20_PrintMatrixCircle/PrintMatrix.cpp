#include <iostream>
using namespace std;



void PrintMC(int **matrix, int rows, int cols, int index)
{
	int endX = cols - 1 - index;
	int endY = rows - 1 - index;
	for (int i = index; i <= endX; ++i)
		cout << matrix[index][i] << " ";

	if (index < endY)
	{
		for (int j = index + 1; j <= endY; ++j)
			cout << matrix[j][endX] << " ";
	}

	if (index < endY && index < endX)
	{
		for (int i = endX - 1; i >= index; --i)
			cout << matrix[endY][i] << " ";
	}
	if (index < endY - 1 && index < endX)
	{
		for (int j = endY - 1; j > index; --j)
			cout << matrix[j][index] << " ";
	}
}


void PrintMatrix(int **matrix, int rows, int cols)
{
	if (matrix == nullptr || rows <= 0 || cols <= 0)
		return;
	for (int index = 0; rows > 2 * index && cols > 2 * index; ++index)
	{
		PrintMC(matrix, rows, cols, index);
	}
	cout << endl;
}




void Test(int rows, int columns)
{
	printf("Test Begin: %d rows, %d cols.\n", rows, columns);

	if (columns < 1 || rows < 1)
		return;

	int** numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i * columns + j + 1;
			cout << numbers[i][j] << " ";
		}
		cout << endl;
	}
	PrintMatrix(numbers, rows, columns);
	printf("\n");

	for (int i = 0; i < rows; ++i)
		delete[](int*)numbers[i];

	delete[] numbers;
}

int main()
{
	/*
	1
	*/
	//Test(1, 1);

	/*
	1    2
	3    4
	*/
	//Test(2, 2);

	/*
	1    2    3    4
	5    6    7    8
	9    10   11   12
	13   14   15   16
	*/
	//Test(4, 4);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14   15
	16   17   18   19   20
	21   22   23   24   25
	*/
	//Test(5, 5);

	/*
	1
	2
	3
	4
	5
	*/
	//Test(5, 1);

	/*
	1    2
	3    4
	5    6
	7    8
	9    10
	*/
	//Test(5, 2);

	/*
	1    2    3
	4    5    6
	7    8    9
	10   11   12
	13   14   15
	*/
	//Test(5, 3);

	/*
	1    2    3    4
	5    6    7    8
	9    10   11   12
	13   14   15   16
	17   18   19   20
	*/
	//Test(5, 4);

	/*
	1    2    3    4    5
	*/
	Test(1, 5);

	/*
	1    2    3    4    5
	6    7    8    9    10
	*/
	Test(2, 5);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14    15
	*/
	Test(3, 5);

	/*
	1    2    3    4    5
	6    7    8    9    10
	11   12   13   14   15
	16   17   18   19   20
	*/
	Test(4, 5);

	return 0;
}

