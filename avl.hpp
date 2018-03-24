#ifndef avl_hpp
#define avl_hpp

/*
	Binary Search Tree using AVL algorithm
*/

#include <iostream>

template <class T>
class AVLnode
{
	T key;
	int bf;	// balance factor
	AVLnode* left;
	AVLnode* right;
	AVLnode* parent;
public:
	AVLnode(const T& value) : key(value), left(NULL), right(NULL), parent(NULL) {}
	~AVLnode() {}
};

template <class T>
class AVLtree
{
	AVLnode<T>* root;
	int count;
public:
	AVLtree();
	~AVLtree();
	void RR(AVLnode<T>* A);
	void LL(AVLnode<T>* A);
	void RL(AVLnode<T>* A);
	void LR(AVLnode<T>* A);
	bool InsertNode(const T& value);
};

/*	Function realizes RR rotation in AVL tree
 *	A        B
 *	 \	->	/
 *	  B    A
 * 	Node B goes to node A place. Node A becomes node B left son, former left son of node B is now A right son.
 *	There are two cases, balance factor of node B before rotation equals -1, or 0.
 * 	param [in] - A - main rotation node	
 */
template <class T>
void AVLtree<T>::RR(AVLnode<T>* A)
{
	AVLnode<T>* B = A->right; 	// B holds right son of node A
	AVLnode<T>* P = A->parent; 	// P holds A's parent
	A->right = B->left;
	if(A->right != NULL) A->right->parent = A;
	B->left = A;
	B->parent = P;
	A->parent = B;
	if(P == NULL) root = B;	// if node A was root, now node B becomes root
	else if(P->left == A) P->left = B;	// else we update former A parent
	else P->right = B;

	// then we modify balance factors
	if(B->bf == -1)
	{
		A->bf = 0;
		B->bf =0;
	}
	else
	{
		A->bf = -1;
		B->bf = 1;
	}
}

/*  Function realizes LL rotation in AVL tree
 *  	A    B
 *     /  ->  \
 *    B		   A
 *  Node B goes to node A place. Node A becomes node B right son, former right son of node B is now A left son.
 *  There are two cases, balance factor of node B before rotation equals -1, or 0.
 *  param [in] - A - main rotation node 
 */
template <class T>
void AVLtree<T>::LL(AVLnode<T>* A)
{
	AVLnode<T>* B = A->left;	// B holds right son of node A
	AVLnode<T>* P = A->parent; 	// P holds A's parent
	A->left = B->right;
	if(A->left != NULL) A->left->parent = A;
	B->right = A;
	B->parent = P;
	A->parent = B;
	if(P == NULL) root = B;	// if node A was root, now node B becomes root
	else if(P->left == A) P->left = B;	// else we update former A parent
	else P->right = B;

	// we modify balance factors
	if(B->bf == 1)
	{
		B->bf = 0;
		A->bf = 0;
	}
	else
	{
		B->bf = -1;
		A->bf = 1;
	}
}

/*  Function realizes RL rotation in AVL tree
 *	A        C
 *   \		/ \
 *    B -> A   B
 *   /
 *	C
 *  Node C replaces node A which becomes C's left son. C left son becomes A right son.
 *	Node B becomes right son of node C and takes right son of node C for his left son.
 *	There are three cases of balance factors before and after rotation.
 *  param [in] - A - main rotation node 
 */
template <class T>
void AVLtree<T>::RL(AVLnode<T> *A)
{
	AVLnode<T>* B = A->right;	// delcaring nodes that that part in rotation
	AVLnode<T>* C = B->left;
	AVLnode<T>* P = A->parent;
	B->left = C->right;
	if(B->left != NULL) B->left->parent = B;
	A->right = C->left;
	if(A->right != NULL) A->right->parent = A;
	C->left = A;
	C->right = B;
	A->parent = C;
	B->parent = C;
	C->parent = P;
	if(P == NULL) root = C;	// if node A was root
	else if(P->left == A) P->left = C;
	else P->right = C;
	
	// modyfing balance factors
	if(C->bf == -1)
	{
		A->bf = 1;
		B->bf = C->bf = 0;
	}
	else if(C->bf == 0)
	{
		A->bf = B->bf = C->bf = 0;
	}
	else
	{
		A->bf = C->bf = 0;
		B->bf = -1;
	}
}

/*  Function realizes LR rotation in AVL tree
 * 		A        C
 *     /    	/ \
 *    B	   ->  B   A
 *     \
 *      C
 *  Node C replaces node A which becomes C's right son. C right son becomes A left son.
 *  Node B becomes left son of node C and takes left son of node C for his right son.
 *  There are three cases of balance factors before and after rotation.
 *  param [in] - A - main rotation node 
 */
template <class T>
void AVLtree<T>::LR(AVLnode<T> *A)
{
	AVLnode<T> *B = A->left;
	AVLnode<T> *C = A->right;
	AVLnode<T> *P = A->parent;
	B->right = C->left;
	if(B->right != NULL) B->right->parent = B;
	A->left = C->right;
	if(A->left != NULL) A->left->parent = A;
	C->right = A;
	C->left = B;
	B->parent = C;
	A->parent = C;
	C->parent = P;
	if(P == NULL) root = C;
	else if(P->left == A) P->left = C;
	else P->right = C;

	// modyfing balance factors
	if(C->bf == -1)
	{
		A->bf = C->bf = 0;
		B->bf = 1;
	}
	else if(C->bf = 0) A->bf = B->bf = C->bf = 0;
	else
	{
		B->bf = C->bf = 0;
		A->bf = -1;
	}
}

template <class T>
bool AVLtree<T>::InsertNode(const T& value)
{
	
}






#endif
