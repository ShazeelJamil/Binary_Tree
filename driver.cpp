#include"LinkBinaryTree.h"
#include<iostream>
using namespace std;
int main()
{
	LinkBinaryTree<int> l;
	l.setRoot(1);
	l.setleftChid(1, 2);
	l.setRightChid(1, 3);
	l.setleftChid(2, 4);
	l.setRightChid(2, 5);
	l.setleftChid(3, 6);
	l.setRightChid(3, 7);
	cout << l.getParent(5);
	//l.remove(2);

	return 0;
}
