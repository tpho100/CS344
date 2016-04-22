#ifndef _NODE_H_
#define _NODE_H_

template <typename K, typename V>
class Node {
	private:
		K key; //value for map, not used in BST structure
		V value; //key for comparing <
		Node<K,V> *left; //left child
		Node<K,V> *right; //right child
		Node<K,V> *parent; //parent
		
	public:
		Node<K,V>(K k,V v)
		{
			key = k;
			value = v;
			left = 0;
			right = 0;
			parent = 0;
		}

		K getKey() 
		{
			return key;		
		}

		V getValue()
		{
			return value;
		}

		Node<K,V> *& getLeft()
		{
			return left;
		}

		void setLeft(Node<K,V> & x)
		{
			left = &x;
		}

		Node<K,V> *& getRight()
		{
			return right;
		}

		void setRight(Node<K,V> & x)
		{
			right = &x;
		}
		
		Node<K,V> *& getParent()
		{
			return parent;
		}

		void setParent(Node<K,V> & x)
		{
			parent = &x;
		}
};
#endif
