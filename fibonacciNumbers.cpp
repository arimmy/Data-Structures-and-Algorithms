#include<iostream>

using namespace std;

int fibonacci_recursion(int n)
{
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;

	return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}
//complexity -> O(2^n)
//the sequence of numbers starts from 0


int fibonacci_linear(int n)
{
	int number = 0, temp1 = 1, temp2 = 0;

	for (int i = 0; i < n - 1; i++)
	{
		number = temp1;
		temp1 += temp2;
		temp2 = number;
	}

	return number;
}
//complexity -> O(n)
//the sequence of numbers starts from 0


void multiply(int F[2][2], int M[2][2])
{
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(int F[2][2], int n)
{
	if (n == 0 || n == 1)
		return;
	int M[2][2] = { { 1,1 },{ 1,0 } };

	power(F, n / 2);
	multiply(F, F);

	if (n % 2 != 0)
		multiply(F, M);
}


int fibonacci_matrix(int n)
{
	int F[2][2] = { { 1,1 },{ 1,0 } };
	if (n == 0)
		return 0;
	power(F, n - 1);
	return F[0][0];
}
//complexity -> O(log n)
//the sequence of numbers starts from 1


int main()
{
	int a, b, c;
	a = fibonacci_recursion(3);
	b = fibonacci_linear(3);
	c = fibonacci_matrix(3);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	system("pause");
	return 0;
}
