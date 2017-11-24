#include<iostream>

using namespace std;

template <typename T>
struct node
{
	T inf;
	node<T> *link;
};

template <typename T>
class CirList
{
private:
	node<T>* end;
	node<T>* current;

	void CopyCirList(CirList<T> const &);
	void DeleteCirList();
public:
	CirList();
	CirList(CirList<T> const &);
	CirList& operator= (CirList<T> const &);
	~CirList();
	void IterStart(node<T> *p = NULL);
	node<T>* Iter();
	void ToEnd(T const &);
	void DeleteElem(node<T>*, T &);
	void print();
};

template <typename T>
CirList<T>::CirList()
{
	end = NULL;
}

template <typename T>
CirList<T>::CirList(CirList<T> const & list)
{
	CopyCirList(list);
}

template <typename T>
CirList<T>& CirList<T>::operator=(CirList<T> const & list)
{
	if (this != &list)
	{
		DeleteCirList();
		CopyCirList(list);
	}
	return *this;
}

template <typename T>
CirList<T>::~CirList()
{
	DeleteCirList();
}

template <typename T>
void CirList<T>::CopyCirList(CirList<T> const & list)
{
	end = NULL;
	node<T> *p = list.end;
	if (p) 
	{
		p = p->link;
		while (p != list.end) 
		{
			ToEnd(p->inf);
			p = p->link;
		}
		ToEnd(p->inf);
	}
}

template <typename T>
void CirList<T>::DeleteCirList()
{
	IterStart();
	node<T> *p = Iter();
	while (p)
	{
		delete p;
		p = Iter();
	}
}

template <typename T>
void CirList<T>::IterStart(node<T> *p)
{
	if (p) current = p;
	else
		if (!end) current = NULL;
		else current = end->link;
}
template <typename T>
node<T>* CirList<T>::Iter()
{
	node<T> *p = current;
	if (current == end) current = NULL;
	else if (current)
		current = current->link;

	return p;
}

template <typename T>
void CirList<T>::ToEnd(T const & x)
{
	node<T> *p = new node<T>;
	p->inf = x;
	if (end) p->link = end->link;
	else end = p;
	end->link = p;
	end = end->link;
}

template <typename T>
void CirList<T>::DeleteElem(node<T> *p, T & x)
{
	x = p->inf;
	if (end != end->link)
	{
		node<T> *q = end;
		while (q->link != p) q = q->link;
		q->link = p->link;
		if (p == end) end = q;
		delete p;
	}
	else
	{
		end = NULL;
		delete p;
	}
}

template <typename T>
void CirList<T>::print()
{
	IterStart();
	node<T>* p = Iter();
	while (p) 
	{
		cout << p->inf << " ";
		p = Iter();
	}
	cout << endl;
}

int main()
{
	CirList<int> list;

	list.ToEnd(1);
	list.ToEnd(2);
	list.ToEnd(3);
	list.ToEnd(4);

	list.print(); 
				  

	system("pause");
	return 0;
}