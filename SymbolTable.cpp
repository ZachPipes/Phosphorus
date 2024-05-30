#include <list>
#include <vector>

//Node structure for linked list chaining
struct Node {
	int key;
	int value;
	Node* next;

	Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class HashTable {
private:
	vector<list<Node>> table;
	int size;


};