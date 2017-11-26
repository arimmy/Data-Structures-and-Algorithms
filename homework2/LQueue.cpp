#include<iostream>

using namespace std;

template <typename T>
struct node 
{
	T data;
	node* next;
};

template <typename T>
class LQueue 
{
private:
	node<T>* front;
	node<T>* back;
	void copy(LQueue<T> const&);	
	void deleteAll(); 
public:
	LQueue() : front(NULL), back(NULL) {}
	LQueue(LQueue const& q) : front(NULL), back(NULL)
	{
		copy(q);
	}
	LQueue& operator=(LQueue const&);
	~LQueue();
	bool empty() const;
	void push(T const&); 
	T pop(); 
	T head() const;
	void print();
};

template <typename T>
void LQueue<T>::copy(LQueue<T> const& q)
{
	back = NULL;
	if (!q.empty())
	{
		node<T>* p = q.front;
		while (p)
		{
			push(p->data);
			p = p->next;
		}
	}
}

template <typename T>
void LQueue<T>::deleteAll() 
{
	while (!empty())
		pop();
}

template <typename T>
LQueue<T>& LQueue<T>::operator=(LQueue<T> const& q)
{
	if (this != &q) 
	{
		deleteAll();
		copy(q);
	}
	return *this;
}

template <typename T>
LQueue<T>::~LQueue()
{
	deleteAll();
}

template <typename T>
bool LQueue<T>::empty() const
{
	return back == NULL;
}

template <typename T>
void LQueue<T>::push(T const& x) 
{
	node<T>* p = new node<T>;
	p->data = x;
	p->next = NULL;
	if (!empty()) 
	{
		back->next = p;
	}
	else front = p;
	back = p;
}

template <typename T>
T LQueue<T>::pop() 
{
	if (empty()) 
	{
		cerr << "Empty queue!";
		return T();
	}

	node<T>* p = front;
	T x = p->data;

	if (p == back) 
	{
		front = NULL;
		back = NULL;
	}
	else front = p->next;

	delete p;
	return x;
}

template <typename T>
T LQueue<T>::head() const 
{
	if (empty()) 
	{
		cerr << "Empty queue!";
		return T();
	}
	return front->data;
}

template <typename T>
void LQueue<T>::print()
{
	node<T>* p = front;
	while (p) 
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	LQueue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);

	int a = queue.head();
	cout << a << endl;
	queue.pop();

	queue.print();

	system("pause");
	return 0;
}