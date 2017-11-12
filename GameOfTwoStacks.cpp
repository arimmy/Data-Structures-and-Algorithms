#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int games = 0, sum = 0, maxSum = 0, elementsPopped = 0;
	int size1 = 0, size2 = 0;

	cin >> games;
	
	stack<int> stack1, stack2;

	for (int i = 0; i < games; ++i)
	
	{
		cin >> size1 >> size2 >> maxSum;
		

		int* a1 = new int[size1];
		for (int i = 0; i < size1; ++i)
		{
			cin >> a1[i];
		}
		for (int i = size1-1; i >= 0; --i)
		{
			stack1.push(a1[i]);
		}


		int* a2 = new int[size2];
		for (int i = 0; i < size2; ++i)
		{
			cin >> a2[i];
		}
		for (int i = size2-1; i >= 0; --i)
		{
			stack2.push(a2[i]);
		}



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

		delete[] a1;
		delete[] a2;

	}

	system("pause");
	return 0;
}
