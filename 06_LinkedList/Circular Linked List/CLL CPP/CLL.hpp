#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

class CLL {
private:
    Node* head;
    Node* tail;
    int numNodes;

public:
    CLL() : head(nullptr), tail(nullptr) {}
    //print linked list
        void printList();
        // helper function to reverse list
        void printRevHelper(Node* node);
        //print linked List in reverse
        void printRevList();
        //swap values of 2 nodes
        void swap(Node*, Node*);
        //add at the end of the list
	void addEnd(int newVal);
	//add after the specified value
	void addAfter(int newVal, int prevVal);
        //add before the specified value
        void addBefore(int newVal, int nextVal);
	//delete a node of a specific value (first instance) and return it
	int deleteFirstInstance(int target);
	//delete a node of a specific value (all instances)
	void deleteAllInstances(int target);
	//delete from the head/front of the list
	void deleteFront();
	//delete from the end of the list
	void deleteEnd();
};
