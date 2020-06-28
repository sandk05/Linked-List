#pragma once
class Node
{
public:
	Node* prev;
	int data;
	Node* next;

	Node(int val);

};
class DoubleLinkedList
{
private:
	Node* head;

public:

	DoubleLinkedList();
	DoubleLinkedList(int val);

	~DoubleLinkedList();

	void create(int Arr[], int size);
	void display();

	void insertat(int data, int position);
	void insertBegin(int data);

	void deleteHead();
	void deletekey(int key);

	Node* getHead() { return head; }

	void reverse();
	void reverse(Node* current);

};

