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
	Lstack<int> stack1, stack2;
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
