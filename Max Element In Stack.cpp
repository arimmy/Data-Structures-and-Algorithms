#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> stack1, stack2;
	int numberOfElements, instruction, elementToAdd;

	cin >> numberOfElements;
	
	for (int i = 0; i < numberOfElements; ++i)
	{
		cin >> instruction;

		if (instruction == 1)
		{
			cin >> elementToAdd;
			if (stack1.empty())
			{
				
				stack1.push(elementToAdd);
				stack2.push(elementToAdd);

			}
			else
			{
				stack1.push(elementToAdd);
				if (stack1.top() > stack2.top())
				{
					stack2.push(elementToAdd);
				}
				else stack2.push(stack2.top());
			}
		}

		else if (instruction == 2)
		{
			if (!stack1.empty())
			{
				stack1.pop();
				stack2.pop();
			}
		}

		else if (instruction == 3)
		{
			if (!stack2.empty())
			{
				cout << stack2.top() << endl;
			}
		}

	}

	system("pause");
	return 0;
}