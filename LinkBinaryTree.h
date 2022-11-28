#ifndef LINK_BINARY_TREE_H
#define LINK_BINARY_TREE_H
#include"BTNode.h"
template<typename T>
class LinkBinaryTree
{
	BTNode<T>* root;
	BTNode<T>* searchNode(BTNode<T>* p, const T& ref);
	void VLR(BTNode<T>* p);
	void LRV(BTNode<T>* p);
	void LVR(BTNode<T>* p);
	BTNode<T>* accessParent(BTNode<T>* p, const T& key);
	void removeDescendents(BTNode<T>* p);
public:
	LinkBinaryTree();
	void setRoot(const T& val);
	void setleftChid(const T& parent, const T& val);
	void setRightChid(const T& parent, const T& val);
	T getParent(const T& key);
	void preOrder();
	void postOrder();
	void inOrder();
	void remove(const T& key);
};
template class LinkBinaryTree<int>;
#endif // !Link_BINARY_TREE_H
