#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
		Create(a, k, n, Low, High, i, j + 1);
	else
		if (i < k - 1)
			Create(a, k, n, Low, High, i + 1, 0);
}

void Print(int** a, const int k, const int n, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		Print(a, k, n, i, j + 1);
	else
		if (i < k - 1)
		{
			cout << endl;
			Print(a, k, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void MaxRow(int** a, const int rowNo, const int n, int colNo, int& max)
{
	if (rowNo % 2 == 0)
	{
		if (a[rowNo][colNo] > max)
			max = a[rowNo][colNo];
		if (colNo < n - 1)
			MaxRow(a, rowNo, n, colNo + 1, max);
	}
}
void MinMaxRows(int** a, const int k, const int n, int rowNo, int& min)
{
	int max = a[rowNo][0];
	MaxRow(a, rowNo, n, 1, max);
	if (rowNo == 1)
		min = max;
	if (max < min)
		min = max;
	if (rowNo < k - 1)
		MinMaxRows(a, k, n, rowNo + 1, min);
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 2;
	int High = 15;
	int k;
	int n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High, 0, 0);
	Print(a, k, n, 0, 0);

	int max;
	MaxRow(a, 0, n, 0, max);
	int min;
	MinMaxRows(a, k, n, 0, min);
	cout << "min = " << min << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}