#include<iostream>

using namespace std;

template <typename T>
struct node
{
	T inf;
	node<T> *prev;
	node<T> *next;
};

template <typename T>
class DList
{
private:
	node<T> *start;
	node<T> *end;
	node<T> *currentStart;
	node<T> *currentEnd;
	void DeleteDList();
	void CopyDList(DList<T> const &);
public:
	DList();
	DList(DList const &);
	DList& operator= (DList const &);
	~DList();
	void IterStart(node<T> *p = NULL);
	void IterEnd(node<T> *p = NULL);
	node<T>* IterNext();
	node<T>* IterPrev();
	void ToEnd(T const &);
	void DeleteElem(node<T>*, T &);
	void print();
	void print_reverse();
	int length();
	void reverseDList();
};

template <typename T>
DList<T>::DList()
{
	start = NULL;
	end = NULL;
}

template <typename T>
DList<T>::DList(DList const & list)
{
	CopyDList(list);
}

template <typename T>
DList<T>& DList<T>::operator=(DList const & list)
{
	if (this != &list)
	{
		DeleteDList();
		CopyDList(list);
	}
	return *this;
}

template <typename T>
DList<T>::~DList()
{
	DeleteDList();
}

template <typename T>
void DList<T>::CopyDList(DList const & list)
{
	start = end = NULL;
	if (list.start) 
	{
		node<T> *p = list.start;
		while (p) 
		{
			ToEnd(p->inf);
			p = p->next;
		}
	}
}

template <typename T>
void DList<T>::DeleteDList()
{
	node<T> *p;
	while (start) 
	{
		p = start;
		start = start->next;
		delete p;
	}
	start = end = NULL;
}

template <typename T>
void DList<T>::IterStart(node<T> *p)
{
	if (p) currentStart = p;
	else currentStart = start;
}

template <typename T>
void DList<T>::IterEnd(node<T> *p)
{
	if (p) currentEnd = p;
	else currentEnd = end;
}

template <typename T>
node<T>* DList<T>::IterNext()
{
	node<T> *p = currentStart;
	if (currentStart) currentStart = currentStart->next;
	return p;
}

template <typename T>
node<T>* DList<T>::IterPrev()
{
	node<T> *p = currentEnd;
	if (currentEnd) currentEnd = currentEnd->prev;
	return p;
}

template <typename T>
void DList<T>::ToEnd(T const & x)
{
	node<T> *p = end;
	end = new node<T>;
	end->inf = x;
	end->next = NULL;
	if (p) p->next = end;
	else start = end;
	end->prev = p;
}

template <typename T>
void DList<T>::DeleteElem(node<T> *p, T & x)
{
	x = p->inf;
	if (start == end) 
	{
		start = NULL;
		end = NULL;
	}
	else if (p == start) 
	{
		start = start->next;
		start->prev = NULL;
	}
	else if (p == end) 
	{
		end = p->prev;
		end->next = NULL;
	}
	else 
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}

	delete p;
}

template <typename T>
void DList<T>::print()
{
	node<T>* p = start;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
	cout << endl;
}

template <typename T>
void DList<T>::print_reverse()
{
	node<T>* p = end;
	while (p) 
	{
		cout << p->inf << " ";
		p = p->prev;
	}

	cout << endl;
}

template <typename T>
int DList<T>::length()
{
	int n = 0;
	node<T>* p = start;
	while (p) 
	{
		n++;
		p = p->next;
	}

	return n;
}

template <typename T>
void DList<T>::reverseDList()
{
	node<T>* temp = nullptr;
	node<T>* current = start;

	while (current)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp) start = temp->prev;
}

int main()
{
	DList<int> list;

	list.ToEnd(1);
	list.ToEnd(2);
	list.ToEnd(3);
	list.ToEnd(4);

	list.print();

	list.reverseDList();
	list.print();

	system("pause");
	return 0;
}