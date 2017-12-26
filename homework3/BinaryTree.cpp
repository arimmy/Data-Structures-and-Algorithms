#include<iostream>

using namespace std;

template <typename T>
struct node
{
	T inf;
	node<T> *left;
	node<T> *right;
};

template <typename T>
class BinTree
{
private:
	node<T> *root;
	void DeleteBinTree(node<T>* &) const;
	void Copy(node<T> * &, node<T>* const&) const;
	void CopyBinTree(BinTree<T> const&);
	void pr(const node<T> *) const;
	void CreateBinTree(node<T> * &) const;
public:
	BinTree();
	~BinTree();
	BinTree(BinTree<T> const&);
	BinTree& operator=(BinTree<T> const&);
	T RootBinTree() const;
	BinTree<T>& LeftBinTree() const;
	BinTree<T>& RightBinTree() const;
	node<T>* GetRoot();
	bool empty() const;
	void print() const;
	void Create();
	void Create3(T, BinTree<T>, BinTree<T>);
	int height(node<T>*);
	void Level(node<T>*, int);
	void levelOrderTraversal(node<T>*);
	bool isBST(node<T>*);
};

template <typename T>
BinTree<T>::BinTree()
{
	root = NULL;
}

template <typename T>
BinTree<T>::~BinTree()
{
	DeleteBinTree(root);
}

template <typename T>
BinTree<T>::BinTree(BinTree<T> const& r)
{
	CopyBinTree(r);
}

template <typename T>
BinTree<T>& BinTree<T>::operator=(BinTree<T> const& r)
{
	if (this != &r)
	{
		DeleteBinTree(root);
		CopyBinTree(r);
	}
	return *this;
}

template <typename T>
void BinTree<T>::DeleteBinTree(node<T>* &p) const
{
	if (p)
	{
		DeleteBinTree(p->left);
		DeleteBinTree(p->right);
		delete p;
		p = NULL;
	}
}

template <typename T>
void BinTree<T>::CopyBinTree(BinTree<T> const& r)
{
	Copy(root, r.root);
}

template <typename T>
void BinTree<T>::Copy(node<T> * & pos, node<T>* const & r) const
{
	pos = NULL;
	if (r)
	{
		pos = new node<T>;
		pos->inf = r->inf;
		Copy(pos->left, r->left);
		Copy(pos->right, r->right);
	}
}

template <typename T>
bool BinTree<T>::empty() const
{
	return root == NULL;
}

template <typename T>
T BinTree<T>::RootBinTree() const
{
	return root->inf;
}

template <typename T>
node<T>* BinTree<T>::GetRoot()
{
	return root;
}

template <typename T>
BinTree<T>& BinTree<T>::LeftBinTree() const   
{
	BinTree<T> t;
	Copy(t.root, root->left);
	return t;
}

template <typename T>
BinTree<T>& BinTree<T>::RightBinTree() const
{
	BinTree<T> t;
	Copy(t.root, root->right);
	return t;
}

template <typename T>
void BinTree<T>::pr(const node<T>*p) const
{
	if (p)
	{
		pr(p->left);
		cout << p->inf << " ";
		pr(p->right);
	}
}

template <typename T>
void BinTree<T>::print() const
{
	pr(root);
}

template <typename T>
void BinTree<T>::Create3(T x, BinTree<T> l, BinTree<T> r)
{
	root = new node<T>;
	root->inf = x;
	Copy(root->left, l.root);
	Copy(root->right, r.root);
}

template <typename T>
void BinTree<T>::CreateBinTree(node<T>* & pos) const
{
	T x; char c;
	cout << "root: ";
	cin >> x;
	pos = new node<T>;
	pos->inf = x;
	pos->left = NULL;
	pos->right = NULL;
	cout << "left BinTree of: " << x << " y/n? ";
	cin >> c;
	if (c == 'y') CreateBinTree(pos->left);
	cout << "right BinTree of: " << x << " y/n? ";
	cin >> c;
	if (c == 'y') CreateBinTree(pos->right);
}

template <typename T>
void BinTree<T>::Create()
{
	CreateBinTree(root);
}

template <typename T>
int BinTree<T>::height(node<T>* root)
{
	if (root == NULL) return -1;

	else
	{
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		if (leftHeight > rightHeight) return (leftHeight+1);

		else return (rightHeight+1);
	}
}

template <typename T>
void Level(node<T>* root, int level)
{
	if (root == NULL) return;
		
	if (level == 1) return root->data;
		
	else if (level > 1)
	{
		Level(root->left, level - 1);
		Level(root->right, level - 1);
	}
}

template <typename T>
void levelOrderTraversal(node<T>* root)
{
	int length = height(root);

	for (int i = 1; i <= length; ++i)
	{
		Level(root, i);
	}	
}

template <typename T>
bool isBST(node<T>* root)
{
	int recent;
	if (root == NULL) return true;

	bool flag = isBST(root->left);

	if (flag) {
		if (recent >= root->inf)
			return false;
		else
			recent = root->inf;
	}

	if (flag)
		flag = isBST(root->right);

	return flag;
}

//template <typename T>
//	bool isBST(node<T>* root, int min, int max) {
//		if (root == NULL) return true;
//
//		if (root->inf <= min || root->inf >= max)
//			return false;
//
//		return isBST(root.left, min, root.data) && isBST(root.right, root.data, max));
//
//	}

int main()
{
	BinTree<int> binTree;
	binTree.Create();
	binTree.print();
	cout << endl;
	int heigth;
	heigth = binTree.height(binTree.GetRoot());
	cout << heigth << endl;
	//binTree.levelOrderTraversal(binTree.GetRoot());

	system("pause");
	return 0;
}