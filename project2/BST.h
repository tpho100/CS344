#ifndef _BST_H_
#define _BST_H_

#include <iostream>

template<typename K, typename V>
struct Node {
	K key;
	V value;
	Node<K,V> *left;
	Node<K,V> *right;
	Node<K,V> *parent;

	Node<K,V>(){
		this->value = 0;
		this->key = 0;
	}	

	Node<K,V>(K key, V value){
		this->value = value;
		this->key = key;
	}
};

template <typename K,typename V>
class BST {
	private:
		Node<K,V> *root;
	public:
		BST<K,V>() {
			root = 0;
		}

		~BST<K,V>() {
		
		}
		
		Node<K,V> *getRoot() {
			return root;
		}

		void setRoot(Node<K,V> & x) {
			root = &x;
		}
		
		void tree_insert(Node<K,V> z) {
			Node<K,V> *y = new Node<K,V>(z);
			Node<K,V> *x = this->getRoot(); //return pointer to root
			
			while(x){ //while root exists
				y = x; //put new node at root
				if( z.key < x->key ) {
					x = (x->left);
				} else {
					x = (x->right);
				}
			}
			z.parent = y;
			if(!y) {
				this->setRoot(z); //tree is empty
			} else if( z.key < y->key ) {
				y->left = &z;
			} else {
				y->right = &z;
			}
			
			
		}

};

#endif
