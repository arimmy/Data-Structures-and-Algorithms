#include<iostream>

using namespace std;

//при положение, че редицата на Фибоначи започва от 0

int fibonacci_recursion(int n)
{
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;

	return fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);
}
//complexity -> O(2^n)

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

//complexity -> O(log n):
//Ако N e четно => k=n/2 :    F(n) = [2*F(k-1) + F(k)] * F(k);
//Ако N e нечетно => k=(n+1)/2 :    F(n) = F(k)*F(k) + F(k-1)*F(k-1);

int main()
{
	int a, b;
	a = fibonacci_recursion(3);
	b = fibonacci_linear(3);
	cout << a << endl;
	cout << b << endl;

	system("pause");
	return 0;
}