#ifndef _BST_H_
#define _BST_H_

#include <iostream>
using namespace std;

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
	public:
		Node<K,V> *root;		

		BST<K,V>() {
			root = 0;
		}

		~BST<K,V>() {
		}
		
		void destroy_tree(Node<K,V> *leaf){
			if( leaf != 0 ){
				destroy_tree(leaf->left);
				destroy_tree(leaf->right);
				free(leaf);
			}
		}
		
		void tree_walk(Node<K,V> *x){
			if(x != NULL ){	
				tree_walk(x->left);
				std::cout << x->key << std::endl;
				tree_walk(x->right);
			}
		}
		
		void tree_insert(Node<K,V> *z) { //takes pointer to node as object
			//cout << &y << endl;
			Node<K,V> *y = NULL;
			Node<K,V> *x = this->root; //point blank node to root
			
			while(x != NULL){ //while root exists
				//cout << "x not null" << endl;
				y = x; //put new node at root
				if( z->key < x->key ) {
					x = (x->left);
				} else {
					x = (x->right);
				}
			}

			z->parent = y;

			if(y == NULL) {
				//cout << "tree is empty";
				this->root = z; //tree is empty
			} else if( z->key < y->key ) {
				y->left = z;
			} else {
				y->right = z;
			}
		}
		
		Node<K,V>* tree_search(Node<K,V> *x, K keyToSearch){
			if( (x == NULL) || (keyToSearch == (x->key)) ) {
				return x;
			}
			
			if( keyToSearch < x->key ){
				return tree_search(x->left,keyToSearch);
			} else {
				return tree_search(x->right,keyToSearch);
			}
		}

		Node<K,V>* tree_minimum(Node<K,V>* x){
			while( x->left != NULL ){
				x = x->left;
			}
			return x;
		}

		Node<K,V>* tree_maximum(Node<K,V>* x){
			while( x->right != NULL ){
				x = x->right;
			}
			return x;
		}
		
		Node<K,V>* tree_successor(Node<K,V>* x){
			if(x->right != NULL){
				return tree_minimum(x->right);
			}
			Node<K,V> *y = x.parent;
			while( (y != NULL) && (x == y->right)) {
				x = y;
				y = y->parent;
			}
			return y;
		}
		
		void transplant(Node<K,V> *u, Node<K,V> *v){
			if(u->parent == NULL){
				this->root = v;
			} else if (u == (u->parent)->left) {
				(u->parent)->left = v;
			} else {
				(u->parent)->right = v;
			}

			if(v != NULL){
				v->parent = u->parent;
			}
		}
			

		void tree_delete(Node<K,V> *z) {
			if(z->left == NULL){
				transplant(z,z->right);
			} else if(z->right == NULL) {
				transplant(z,z->left);
			} else {
				Node<K,V> *y = tree_minimum(z->right);
				if(y->parent != z){
					transplant(y,y->right);
					y->right = z->right;
					(y->right)->parent = y;
				}
				transplant(z,y);
				y->left = z->left;
				(y->left)->parent = y;
			}
		}

};

#endif
