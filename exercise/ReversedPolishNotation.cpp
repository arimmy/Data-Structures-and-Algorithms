#include<iostream>
#include<string>

template <typename T>
struct node {
	T data;
	node* next;
};

template <typename T>
class Lstack {
private:
	node<T>*  topNode;

	bool empty() const;
	void copy(node<T>*);
	void copyLstack(const Lstack&);
	void deleteLstack();
public:
	Lstack();
	Lstack(const Lstack&);
	Lstack& operator=(const Lstack&);
	~Lstack();

	void push(const T&);
	T pop();
	T top() const;
	int length();
};

template <typename T>
bool Lstack<T>::empty() const
{
	return topNode == nullptr;
}

template <typename T>
void Lstack<T>::copy(node<T>* toCopy)
{
	if (toCopy == nullptr)
		return;
	copy(toCopy->next);
	push(toCopy->data); 
}

template <typename T>
void Lstack<T>::copyLstack(const Lstack& other)
{
	topNode = nullptr;
	copy(other.topNode);
}

template <typename T>
void Lstack<T>::deleteLstack()
{
	while (!empty())
		pop();
}

template <typename T>
Lstack<T>::Lstack() :topNode(nullptr)
{}

template <typename T>
Lstack<T>::Lstack(const Lstack& other)
{
	copyLstack(other);
}

template <typename T>
Lstack<T>& Lstack<T>::operator=(const Lstack& other)
{
	if (this != &other)
	{
		deleteLstack();
		copyLstack(other);
	}

	return *this;
}

template <typename T>
Lstack<T>::~Lstack()
{
	deleteLstack();
}

template <typename T>
void Lstack<T>::push(const T& x)
{
	node<T>* p = new node<T>;
	p->data = x;
	p->next = topNode;
	topNode = p;
}

template <typename T>
T Lstack<T>::pop()
{
	if (empty())
	{
		cerr << "Stack is empty!\n";
		return 0;
	}

	node<T>* p = topNode;
	topNode = topNode->next;
	T x = p->data;
	delete p;
	return x;

}

template <typename T>
T Lstack<T>::top() const
{
	if (empty())
	{
		cerr << "Stack is empty!\n";
		return 0;
	}

	return topNode->data;
}

template <typename T>
int Lstack<T>::length()
{
	int n = 0;
	while (!empty())
	{
		pop();
		n++;
	}
	return n;
}

using namespace std;

int evaluate(string str)
{
	Lstack<int> helper;

	int i = 0, n = str.size();
	double x, y;
	int z, w;

	while (i < n)
	{
		if (str[i] >= '0'&& str[i] <= '9')
		{
			helper.push((int)str[i] - (int)'0');
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '%' || str[i] == 'b' || str[i] == 'u' || str[i] == 't')
		{
			if (str[i] == 'u')
			{
				x = helper.pop();
				z = 2 * x + 1;
			}

			else if (str[i] == 't')
			{
				w = helper.pop();
				y = helper.pop();
				x = helper.pop();
				z = x + 2 * y + 3 * w;
			
			}
			else
			{
				y = helper.pop();
				x = helper.pop();


				switch (str[i])
				{
				case '+': z = x + y; break;
				case '-': z = x - y; break;
				case '*': z = x * y; break;
				case '/': if (y == 0) return 1;
						  else z = x / y; break;
				case '^': z = (int)pow(x, y); break;
				case '%': z = (int)x % (int)y; break;
				case 'b': z = (x*x) + y; break;
			}
			}
			helper.push(z);
		}
		i++;
	}
	helper.pop();

	return z;
}


int main()
{
	string str;
	int n;
	cin >> n;
	

	for (int i = 0; i < n; ++i)
	{
		cin >> str;

		int result = evaluate(str);
		cout << result << endl;

	}

	


	system("pause");
	return 0;
}
