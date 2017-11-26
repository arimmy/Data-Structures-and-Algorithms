#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> stack1, stack2;

	int instruction = 0;
	int element = 0;
	int numberOfElements = 0;

	cin >> numberOfElements;

	if (numberOfElements <= 0) cout << "Invalid input!" << endl;

	for (int i = 0; i < numberOfElements; ++i)
	{
		cin >> instruction;

		if (instruction == 1)
		{
			cin >> element;
			stack1.push(element);
		}

		if (instruction == 2)
		{
			if (stack2.empty())
			{
				while (!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
			}
			stack2.pop();
		}

		if (instruction == 3)
		{
			if (stack2.empty())
			{
				while (!stack1.empty())
				{
					stack2.push(stack1.top());
					stack1.pop();
				}
			}
			cout << stack2.top() << endl;
		}
	}

	system("pause");
	return 0;
}