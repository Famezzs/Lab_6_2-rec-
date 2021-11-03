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

void CreateArray(int *z, const int size, const int LeftLimit, const int RightLimit, const int i);
void PrintArray(int *z, const int size, const int i);
void ArithmeticMean(int *z, const int size, double S, double &ArMean, const int i, const int n);

int main()
{
	srand((unsigned)time(NULL));

	int n;
	int A;
	int B;
	double z = 0;

	cout << "How many elements should a new array consist of?\n";
	cout << "n = "; cin >> n;
	
	if (n <= 0)
	{
		std::cerr << "Number of elements in an array should be > 0";
		return -1;
	}

	cout << endl << "What interval should RNG's results satisfy? (i.e. define [A;B], where A and B are both integers, A < B)\n";
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;

	if (A >= B)
	{
		std::cerr << "A must be < B";
		return -1;
	}

	int *a = new int[n];

	CreateArray(a, n, A, B, 0);
	PrintArray(a, n, 0);
	ArithmeticMean(a, n, 0, z, 0, 0);

	cout << "The arithmetic mean = " << z;

	delete[] a;
	return 0;
}

void CreateArray(int *z, const int size, const int LeftLimit, const int RightLimit, const int i)
{
	z[i] = LeftLimit + rand() % (RightLimit - LeftLimit + 1);;
	
	if (i < size - 1)
		CreateArray(z, size, LeftLimit, RightLimit, i + 1);
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

void ArithmeticMean(int *z, const int size, double S, double &ArMean, const int i, const int n)
{
	if (i < size)
	{
		S += z[i];
		ArithmeticMean(z, size, S, ArMean, i + 2, n + 1);
	}
	else
		ArMean = S / n;		
}
