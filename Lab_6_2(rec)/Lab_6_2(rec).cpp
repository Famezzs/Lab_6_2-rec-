// Lab_6_2(iter).cpp
// Козубенко Андрій
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами.
// Варіант 10
// Рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::setw;

void CreateArray(int *z, const int size, const int LeftLimit, const int RightLimit, int &FaultCheck, const int i);
void PrintArray(int *z, const int size, const int i);
void ArithmeticMean(int *z, const int size, double S, const int i);

int main()
{
	srand((unsigned)time(NULL));

	int n;
	int A;
	int B;
	int t = 0; // fault check

	cout << "How many elements should a new array consist of?\n";
	cout << "n = "; cin >> n;
	cout << endl << "What interval should RNG's results be generated from? (i.e. define [A;B], where A and B are both integers, A < B)\n";
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;

	int *a = new int[n];

	CreateArray(a, n, A, B, t, 0);
	if (t == 1)
	{
		PrintArray(a, n, 0);
		ArithmeticMean(a, n, 0, 0);
	}

	delete[] a;
	return 0;
}

void CreateArray(int *z, const int size, const int LeftLimit, const int RightLimit, int &FaultCheck, const int i)
{
	if (LeftLimit >= RightLimit)
		cerr << "Unable to proceed: either A > B or A = B";
	else
	{
		if (i < size)
		{
			int t = LeftLimit + rand() % (RightLimit - LeftLimit + 1);
			if (t % 2 == 0)
			{
				z[i] = t;
				CreateArray(z, size, LeftLimit, RightLimit, FaultCheck, i + 1);
			}
			else
				CreateArray(z, size, LeftLimit, RightLimit, FaultCheck, i);
		}
		else
			FaultCheck++;
	}
}

void PrintArray(int *z, const int size, const int i)
{
	if (i == 0)
		cout << endl <<"a = " << "{";

	cout << setw(4) << z[i];

	if (i != size - 1)
		cout << ",";

	if (i < size - 1)
		PrintArray(z, size, i + 1);
	else
		cout << " }\n";
}

void ArithmeticMean(int *z, const int size, double S, const int i)
{
	
	if (i < size)
	{
		S += z[i];
		ArithmeticMean(z, size, S, i + 1);
	}
	else
		cout << endl << "The arithmetic mean is:" << setw(5) << S / size << endl;
}
