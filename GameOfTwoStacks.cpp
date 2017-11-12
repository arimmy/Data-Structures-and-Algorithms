#include<iostream>

using namespace std;

template <typename T>
struct node {
	T data;
	node* next;
};

template <typename T>
class Lstack {
private:
	node<T>*  topNode;

	void copy(node<T>*);
	void copyLstack(const Lstack&);
	void deleteLstack();
public:
	Lstack();
	Lstack(const Lstack&);
	Lstack& operator=(const Lstack&);
	~Lstack();

	bool empty() const;
	void push(const T&);
	T pop();
	T top() const;
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
void Lstack<T>::copyLstack(Lstack<T> const & other)
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
Lstack<T>::Lstack(const Lstack<T>& other)
{
	copyLstack(other);
}

template <typename T>
Lstack<T>& Lstack<T>::operator=(const Lstack<T>& other)
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

int main()
{
	int games = 0, sum = 0, maxSum = 0, elementsPopped = 0;
	int size1 = 0, size2 = 0;

	cin >> games;

	for (int i = 0; i < games; ++i)
	
	{
		cin >> size1 >> size2 >> maxSum;
		Lstack<int> stack1, stack2;

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