#include <iostream>
#include <stack>

using namespace std;

void enterElStack(int size, stack<int> &stack)
{
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
	{
		cin >> array[i];
	}
	for (int i = size - 1; i >= 0; --i)
	{
		stack.push(array[i]);
	}
	delete[] array;
}
int main()
{
	int games = 0, maxSum = 0;
	int sum, elementsPopped;
	int size1 = 0, size2 = 0;

	cin >> games;

	stack<int> stack1, stack2;

	for (int i = 0; i < games; ++i)
	{
		cin >> size1 >> size2 >> maxSum;
		elementsPopped = 0;
		sum = 0;

		
		enterElStack(size1, stack1);
		enterElStack(size2, stack2);
		

		while (!stack1.empty() || !stack2.empty())
		{
			if (stack1.empty())
			{
				sum += stack2.top();
				if (sum > maxSum) break;
				stack2.pop();
				elementsPopped++;
			}
			else if (stack2.empty())
			{
				sum += stack1.top();
				if (sum > maxSum) break;
				stack1.pop();
				elementsPopped++;
			}

			else if (stack1.top() <= stack2.top())
			{
				sum += stack1.top();
				if (sum > maxSum) break;
				stack1.pop();
				elementsPopped++;
			}
			else
			{
				sum += stack2.top();
				if (sum > maxSum) break;
				stack2.pop();
				elementsPopped++;
			}
		}

		cout << elementsPopped << endl;
	}

	system("pause");
	return 0;
}


