#ifndef _MAP_H_
#define _MAP_H_

#include "BST.h"

class Map {
	private:
		template<typename K,typename V>
		BST<K,V> binarySearchTree = BST<K,V>();
};

#endif
