#include"LinkBinaryTree.h"
#include<iostream>
using namespace std;
template<typename T>
void LinkBinaryTree<T>::VLR(BTNode<T>* p)
{
	cout << p->info << "\n";
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
}
template<typename T>
BTNode<T>* LinkBinaryTree<T>::accessParent(BTNode<T>* p, const T& key)
{
	BTNode<T>* isFound = nullptr;
	if (!p)
		return isFound;
	if ((p->left && p->left->info == key) || (p->right && p->right->info == key))
		isFound = p;
	if (!isFound && p->left)
		isFound = accessParent(p->left, key);
	if (!isFound && p->right)
		isFound = accessParent(p->right, key);
	return isFound;
}
template<typename T>
void LinkBinaryTree<T>::LRV(BTNode<T>* p)
{
	if (p->left)
		VLR(p->left);
	if (p->right)
		VLR(p->right);
	cout << p->info << "\n";
}
template<typename T>
void LinkBinaryTree<T>::LVR(BTNode<T>* p)
{
	if (p->left)
		LVR(p->left);
	cout << p->info << "\n";
	if (p->right)
		LVR(p->right);
}
template<typename T>
BTNode<T>* LinkBinaryTree<T>::searchNode(BTNode<T>* p, const T& key)
{
	BTNode<T> *isFound = nullptr;
	if (p->info == key)
		isFound = p;
	if (!isFound && p->left)
		isFound = searchNode(p->left, key);
	if (!isFound && p->right)
		isFound = searchNode(p->right, key);
	return isFound;
}
template<typename T>
LinkBinaryTree<T>::LinkBinaryTree()
{
	root = nullptr;
}
template<typename T>
void LinkBinaryTree<T>::setRoot(const T& val)
{
	if (root)
		root->info = val;
	else
		root = new BTNode<T>(val);
}
template<typename T>
void LinkBinaryTree<T>::setleftChid(const T& parent, const T& val)
{
	BTNode<T>* p = searchNode(root, parent);
	if (!p)
		return;
	if (p->left)
		p->left->info = val;
	else
		p->left = new BTNode<T>(val);
}
template<typename T>
void LinkBinaryTree<T>::setRightChid(const T& parent, const T& val)
{
	BTNode<T>* p = searchNode(root, parent);
	if (!p)
		return;
	if (p->right)
		p->right->info = val;
	else
		p->right = new BTNode<T>(val);
}
template<typename T>
void LinkBinaryTree<T>::preOrder()
{
	VLR(root);
}
template<typename T>
void LinkBinaryTree<T>::postOrder()
{
	LRV(root);
}
template<typename T>
void LinkBinaryTree<T>::inOrder()
{
	LVR(root);
}
template<typename T>
T LinkBinaryTree<T>::getParent(const T& key)
{
	BTNode<T>* p = accessParent(root, key);
	if (p)
		return p->info;
	cout << "exit(0)";
	exit(0);
}
template<typename T>
void LinkBinaryTree<T>::removeDescendents(BTNode<T>* p)
{
	if (!p->left)
		return;
	if (!p->right)
		return;
	if (p->left)
		removeDescendents(p->left);
	p = nullptr;
	if (p->right)
		removeDescendents(p->right);
}
template<typename T>
void LinkBinaryTree<T>::remove(const T& key)
{
	BTNode<T>* p = accessParent(root, key);
	if (p)
		removeDescendents(p->left);
	cout << "exit(0)";
	exit(0);
}