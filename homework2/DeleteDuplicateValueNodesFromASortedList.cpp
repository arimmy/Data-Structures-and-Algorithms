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
	void DeleteDuplicates();
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
void LinkedList<T>::DeleteDuplicates()
{
	IterStart();//start from the beginning of the list (because there is no argument in the used function -> see definition of function IterStart())
	node<T>* p = Iter();//START and P are pointers to the first node (see definition of function Iter())

	if (start == NULL) return;//if there are no elements, nothing happens

	T x = start->inf;

	p = Iter();//P is now pointer to the node after START

	while(p)
	{
		while (x == p->inf)
		{
			DeleteElem(p, x);//delete duplicate element
			p = Iter();//change P to be a pointer to the next node, so that the comparison can continue
			if (p == NULL) return;//check, so that there is no exceptionn thrown
		}

		x = p->inf;//after deleting all duplicates of an element, we change the value of X and continue checking for duplicates of the new element
		p = Iter();//change the pointer, so that we can check for duplicates of the next element
	}
	//IMPORTANT! -> We go through the list only once in order to delete the duplicates i.e. we do not go through it a number of times for each element
}


int main()
{
	LinkedList<int> list;

	list.ToEnd(1);
	list.ToEnd(1);
	list.ToEnd(3);
	list.ToEnd(3);
	list.ToEnd(5);
	list.ToEnd(6);

	list.print();

	list.DeleteDuplicates();

	list.print();

	system("pause");
	return 0;
}