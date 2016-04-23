#ifndef _MAP_H_
#define _MAP_H_

#include "BST.h"
#include <utility>
#include "MapIterator.h"

template<typename K,typename V>
class Map {
	
	//friend class MapIterator<K,V>;	
	
	private:
		BST<K,V> bst;
		int SIZE;
		
		BST<K,V> getBST(){
			return bst;
		}
		
	public:
		Map<K,V>(){//default constructor
			bst = BST<K,V>();
			SIZE = 0;
		}
			
		Map<K,V>(Map<K,V> & map){ //copy constructor
			this->bst = map.getBST();
			this->SIZE = map.size();
		}

		Map<K,V> & operator=(Map<K,V> & temp){ //assignment operator
			if(this != &temp){
				this->bst = temp.getBST();
				this->SIZE = temp.size();
			}
			return *this;
		}
		
		~Map<K,V>(){ //destructor
			//I have no dynamic memory allocation going on...
		}
		
		int size(){
			return SIZE;
		}
		
		bool empty(){
			if(SIZE > 0){
				return false;
			}
			return true;
		}

		void swap(Map<K,V> & map){
			BST<K,V> temp = bst;
			int tempSize = SIZE;

			this->bst = map.getBST();
			this->SIZE = map.size();
			map.bst = temp;
			map.SIZE = tempSize;
		}
		
		void clear(){
			bst.destroy_tree(bst.root);
			SIZE = 0;
		}
		
		Node<K,V>* begin(){ //Returns node to first element which is the lowest key
			return bst.tree_minimum(bst.root);
		}
		
		Node<K,V>* end(){
			return bst.tree_maximum(bst.root); //max is always at the end
		}
		
		size_t count(K key){
			Node<K,V> *temp = bst.tree_search(bst.root,key);
			if(temp != NULL){
				return 1;
			} else {
				return 0;
			}
		} 
		
		bool insert(pair<K,V> pair){
			K key = pair.first;
			V value = pair.second;
			Node<K,V> *temp = new Node<K,V>(key,value);
			Node<K,V> *temp2 = bst.tree_search(bst.root,key);

			if(temp2 != NULL){
				//found duplicate key, not inserting
				return false;
			} else {
				bst.tree_insert(temp);
				SIZE++;
				return true;
			}	
		}
		
		size_t erase(K key){
			Node<K,V> *temp = bst.tree_search(bst.root,key); //Search for the node with key key
			if( temp != NULL){ //if it is not null, it's in the tree
				bst.tree_delete(temp); //Delete that node
				SIZE--;
				return 1; //was deleted
			} else {
				return 0; //NULL so node was not in the tree
			}
			
		}
};

#endif
