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
private:
	Node* head;
public:
	LinkedList();

	void add_Node(int data);
	void add_Node(Node* newNode);

	void display();
	void create(int Arr[], int size);


	Node* getHead() { return head; }
	Node* getthird() { return head->next->next; }

	Node* interSectionPoint(LinkedList& other);


};
