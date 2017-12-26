#include<iostream>

template <typename T>
struct node
{
   T inf;
   node<T> *left;
   node<T> *right;
};


template <typename T>
node<T>* BinTree<T>::lca(node<T>* root, int vertex1, int vertex2)
{
   if (root == NULL) return NULL;

   if (root->inf > vertex1 && root->inf > vertex2) return lca(root->left, vertex1, vertex2);
		
   if (root->inf < vertex1 && root->inf < vertex2) return lca(root->right, vertex1, vertex2);

   return root;	
}
