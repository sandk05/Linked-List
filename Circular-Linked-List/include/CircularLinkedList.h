#pragma once
class Node
{
public:
	int data;
	Node* next;
	Node(int v);

};
class CircularLinkedList
{
public:
	CircularLinkedList();
	~CircularLinkedList();
	void display();
	void display(Node* nPtr);
	Node* gethead() { return head; };
	void create(int Arr[], int size);
	void insertat(int position, int data);
	void insertBegining(int data);
	void deleteat(int pos);
	void deletehead();

private:
	Node* head;
};

