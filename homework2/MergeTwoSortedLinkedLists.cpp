#include<iostream>

using namespace std;

template<typename T>
struct node
{
	T inf;
	node<T>* link;
};

template<typename T>
class LinkedList
{
private:
	node<T>* start;
	node<T>* end;
	node<T>* current;

	void DeleteLinkedList();
	void CopyLinkedList(LinkedList const &);

public:
	LinkedList();
	LinkedList(LinkedList const &);
	LinkedList& operator=(LinkedList const &);
	~LinkedList();

	void IterStart(node<T>* p = NULL);
	node<T>* Iter();

	void ToEnd(T const &);
	void InsertAfter(node<T>*, T const &);
	void InsertBefore(node<T>*, T const &);
	bool DeleteAfter(node<T>*, T &);
	bool DeleteBefore(node<T>*, T &);
	void DeleteElem(node<T>*, T &);
	void print();
	int length();
	void concat(LinkedList<T> const&);
	void sortConcat();
};

template <typename T>
LinkedList<T>::LinkedList()
{
	start = NULL;
	end = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList const & list)
{
	CopyLinkedList(list);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList const & list)
{
	if (this != &list)
	{
		DeleteLinkedList();
		CopyLinkedList(list);
	}
	return *this;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	DeleteLinkedList();
}

template <typename T>
void LinkedList<T>::DeleteLinkedList()
{
	node<T>* p;
	while (start)
	{
		p = start;
		start = start->link;
		delete p;
	}
	end = NULL;
}

template <typename T>
void LinkedList<T>::CopyLinkedList(LinkedList const & list)
{
	start = end = NULL;
	if (list.start) 
	{
		node<T> *p = list.start;
		while (p) 
		{
			ToEnd(p->inf);
			p = p->link;
		}
	}
}

template <typename T>
void LinkedList<T>::IterStart(node<T> *p)
{
	if (p) current = p;
	else current = start;
}

template <typename T>
node<T>* LinkedList<T>::Iter()
{
	node<T> *p = current;
	if (current) current = current->link;
	return p;
}

template <typename T>
void LinkedList<T>::ToEnd(T const & x)
{
	current = end;
	end = new node<T>;
	end->inf = x;
	end->link = NULL;
	if (current) current->link = end;
	else start = end;
}

template <typename T>
void LinkedList<T>::InsertAfter(node<T> *p, T const & x)
{
	node<T> *q = new node<T>;
	q->inf = x;
	q->link = p->link;
	if (p == end) end = q;
	p->link = q;
}

template <typename T>
void LinkedList<T>::InsertBefore(node<T> *p, T const & x)
{
	node<T> *q = new node<T>;
	*q = *p;
	if (p == end) end = q;
	p->inf = x;
	p->link = q;
}

template <typename T>
bool LinkedList<T>::DeleteAfter(node<T> *p, T & x)
{
	if (p->link)
	{
		node<T> *q = p->link;
		x = q->inf;
		p->link = q->link;
		if (q == end) end = p;
		delete q;
		return 1;
	}
	return 0;
}

template <typename T>
void LinkedList<T>::DeleteElem(node<T> *p, T & x)
{
	if (p == start) 
	{
		x = p->inf;
		if (start == end)
		{
			start = end = NULL;
		}
		else start = start->link;
		delete p;
	}
	else
	{
		node<T> *q = start;
		while (q->link != p) q = q->link;
		DeleteAfter(q, x);
	}
}

template <typename T>
bool LinkedList<T>::DeleteBefore(node<T> *p, T & x)
{
	if (p != start) 
	{
		node<T> *q = start;
		while (q->link != p) q = q->link;
		DeleteElem(q, x);
		return 1;
	}
	return 0;
}

template <typename T>
void LinkedList<T>::print()
{
	node<T>* p = start;
	while (p) 
	{
		cout << p->inf << " ";
		p = p->link;
	}
	cout << endl;
}

template <typename T>
int LinkedList<T>::length()
{
	int n = 0;
	IterStart();
	node<T> *p = Iter();
	while (p) 
	{
		n++;
		p = Iter();
	}
	return n;
}

template <typename T>
void LinkedList<T>::concat(LinkedList<T> const & list)
{
	node<T> *p = list.start;
	while (p) 
	{
		ToEnd(p->inf);
		p = p->link;
	}
}

template <typename T>
void LinkedList<T>::sortConcat()
{
	node<T> *minPtr = nullptr, *current, *next = nullptr;
	T minValue;
	IterStart();
	current = Iter();

	while (current->link)
	{
		minValue = current->inf;
		minPtr = current;
		next = current->link;


		while (next)
		{
			if (next->inf < minValue)
			{
				minPtr = next;
				minValue = next->inf;
			}
			next = next->link;
		}

		if (minPtr != current)
		{
			minPtr->inf = current->inf;
			current->inf = minValue;
		}

		current = current->link;
	}
}

int main()
{
	LinkedList<int> list1, list2;

	list1.ToEnd(1);
	list1.ToEnd(3);
	list1.ToEnd(5);
	list1.ToEnd(6);

	list2.ToEnd(2);
	list2.ToEnd(4);
	list2.ToEnd(7);

	list1.concat(list2);
	list1.sortConcat();

	list1.print();

	system("pause");
	return 0;
}