#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	
	string brackets;
	
	bool isBalanced = true;
	int n;
	cin >> n;
	
	
	while (n != 0)
	{
		stack<char> stack;
		cin >> brackets;
		isBalanced = true;

		for (int i = 0; i < brackets.length(); ++i)
		{
			if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{' || brackets[i] == '<')
				stack.push(brackets[i]);

			else if (brackets[i] == ')')
			{
				if (stack.empty()) isBalanced = false;
				else
				{
					if (stack.top() != '(') isBalanced = false;
					else
						stack.pop();
				}


			}

			else if (brackets[i] == ']')
			{
				if (stack.empty()) isBalanced = false;
				else
				{
					if (stack.top() != '[') isBalanced = false;
					else
						stack.pop();
				}

			}

			else if (brackets[i] == '}')
			{
				if (stack.empty()) isBalanced = false;
				else
				{
					if (stack.top() != '{') isBalanced = false;
					else
						stack.pop();
				}

			}

			else if (brackets[i] == '>')
			{
				if (stack.empty()) isBalanced = false;
				else
				{
					if (stack.top() != '<') isBalanced = false;
					else
						stack.pop();
				}

			}
		}
		n--;
		if (isBalanced) cout << "Yes!" << endl;
		else cout << "No!" << endl;

	}
	
	

	system("pause");
	return 0;
}