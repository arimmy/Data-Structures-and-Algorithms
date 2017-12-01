#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int main()
{
	stack<char> stack;
	queue<char> queue;
	string word;
	bool isPalindrome;
	
	cin >> word;
	int n = word.length();

	for (int i = 0; i < n; ++i)
	{
		stack.push(word[i]);
		queue.push(word[i]);
	}

	isPalindrome = true;

	for (int i = 0; i < n /2; ++i)
	{
		if (stack.top() != queue.front())
			isPalindrome = false;

		stack.pop();
		queue.pop();
	}

	if (isPalindrome) cout << "Yes!" << endl;
	else cout << "No!" << endl;

	
	system("pause");
	return 0;
}
