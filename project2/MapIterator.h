#include "Map.h"

template <typename K, typename V>
class MapIterator{
	//friend class Map<K,V>;
	public:
		MapIterator() : p_current_node(nullptr) {}
		
		K & operator*() const { return p_current_node->element; }
		K * operator->() const { return &(p_current_node->element); }
	
		bool operator==(const MapIterator & rhs) const {
			return (p_current_node == rhs.p_current_node);
		}
		
		bool operator!=(const MapIterator & rhs) const {
			return (p_current_node != rhs.p_current_node);
		}
		
		MapIterator & operator++();
		MapIterator & operator--();
		
		MapIterator operator++(int);
		MapIterator operator--(int);
	private:
		explicit MapIterator(Node<K,V> * p) : p_current_node(p) {}
		
		Node<K,V> *p_current_node;
		
};

template <typename K, typename V>
inline MapIterator<K,V> & MapIterator<K,V>::operator++()
// prefix version (++itr)
{
    p_current_node = p_current_node->next;
    return *this;
}

template <typename K, typename V>
inline MapIterator<K,V> & MapIterator<K,V>::operator--()
// prefix version (--itr)
{
    p_current_node = p_current_node->previous;
    return *this;
}

template <typename K, typename V>
inline MapIterator<K,V> MapIterator<K,V>::operator++(int)
// postfix version (itr++)
{
    MapIterator<K,V> original_itr = *this;
    p_current_node = p_current_node->next;
    return original_itr;
}

template <typename K, typename V>
inline MapIterator<K,V> MapIterator<K,V>::operator--(int)
// postfix version (itr++)
{
    MapIterator<K,V> original_itr = *this;
    p_current_node = p_current_node->previous;
    return original_itr;
}
