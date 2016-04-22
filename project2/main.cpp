#include "Map.h"
#include "BST.h"
#include <iostream>

using namespace std;

int main(){
	Node<int,int> *a = new Node<int,int>(45,50);
	Node<int,int> *b = new Node<int,int>(24,66);
	Node<int,int> *c = new Node<int,int>(33,99);
	Node<int,int> *d = new Node<int,int>(99,99);
	Node<int,int> *e = new Node<int,int>(100,99);

	Node<int,int> *yy = new Node<int,int>(26,99);
	Node<int,int> *xx = new Node<int,int>(75,99);

	BST<int,int> t = BST<int,int>();
	t.tree_insert(a);
	t.tree_insert(b);
	t.tree_insert(c);
	t.tree_insert(d);
	t.tree_insert(e);
	
	t.tree_walk(t.root);
	t.tree_delete(c);
	cout << "walking again" << endl;
	t.tree_walk(t.root);

	return 0;
}
