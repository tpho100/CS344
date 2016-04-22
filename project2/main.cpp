#include "Map.h"
#include <iostream>
#include <utility>

using namespace std;

int main(){

	Map<int,int> map;
	map.insert(make_pair(10, 1)); //INSERT TEST
	map.insert(make_pair(11, 1));
	map.insert(make_pair(12, 1));
	map.insert(make_pair(13, 1));
	cout << "MAPSIZE: " << map.size() << endl; //SIZE TEST
	cout << "COUNTING NODES WITH KEY:  12" << map.count(12) << endl; //COUNT TEST
	map.erase(12);			//ERASE TEST
	cout << "ERASING NODE WITH KEY 12" << endl;
	cout << map.count(12) << endl;
	cout << "COUNTING NODE WITH KEY 12 - SHOULD BE 0" << endl;
	cout << map.size() << endl; //SIZE TEST
	cout << "GETTING NEW MAP SIZE, SHOULD BE 3" << endl;
	
	Map<int,int> map2 = map; //ASSIGNMENT TEST
	cout << "ASSIGNING MAP2 TO MAP" << endl;
	cout << map2.size() << endl; //SIZE TEST
	cout << "CHECKING MAP2 SIZE, SHOULD BE 3" <<endl;
	cout << map2.count(13) << endl;
	cout << "COUNTING ELM WITH KEY 13" << endl;


	return 0;
}
