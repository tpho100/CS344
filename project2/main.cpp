#include "BST.h"
#include <iostream>

using namespace std;

int main(){
	Node<int,int> a = Node<int,int>(10,50);
	Node<int,int> b = Node<int,int>(25,66);
	Node<int,int> c = Node<int,int>(14,99);
	BST<int,int> tree = BST<int,int>();
	cout << a.key << endl;
	cout << b.key << endl;

	BST<int,int> t = BST<int,int>();
	t.tree_insert(a);


	return 0;
}
