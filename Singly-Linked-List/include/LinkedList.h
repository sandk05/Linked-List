#pragma once
class Node
{
public:
	int data;
	Node* next;
	Node(int content);

	~Node();

};

class LinkedList
{

public:
	LinkedList();
	~LinkedList();

	void display();
	void display(Node* nPtr);

	Node* getHead() { return head; }
	void setHead(Node* aPtr) { head = aPtr; }
	
	int count();
	int count(Node* nPtr);
	int sum();
	int sum(Node* nPtr);
	int largest(Node* nPtr);
	int smallest(Node* nPtr);

	Node* search(int key);
	Node* search(Node* nPtr, int key);

	void create(int Arr[], int size);
	void add_Node(int data);

	void insertfront(int data);
	void insertAt(int position, int data);

	void SortedInsert(int value);
	bool isSorted();

	void remove(int value);
	void removeDuplicates();

	void reverse(Node* prev, Node* curr);
	void reverse();

	void concat(LinkedList& other);
	void operator+(LinkedList& other);
	LinkedList* merge(LinkedList& other);
	
	void createLoop();
	bool isLoop();
	void removeloop();

private:
	Node* head;
	Node* loopNode();
	void removeloop(Node* loopNode);
};

