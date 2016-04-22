#include "Node.h"

template <typename K, typename V>
class MapIterator{
	public:
		MapIterator() : p_current_node(nullptr) {
		}
	private:
		explicit MapIterator( Node<K,V> *p ):
			p_current_node(p) {
			}
		Node<K,V> * p_current_node;
};