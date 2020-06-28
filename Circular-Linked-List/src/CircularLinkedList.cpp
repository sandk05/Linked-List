#include <iostream>
#include "CircularLinkedList.h"
	
Node::Node(int v)
{
	data = v;
	next = nullptr;
}
CircularLinkedList::CircularLinkedList()
{
	head = nullptr;
}

CircularLinkedList::~CircularLinkedList()
{
	if (head == nullptr)
		return;
	Node* current = head, * next;
	do {
		next = current->next;
		delete current;
		current = next;
	} while (current != head);
	head = nullptr;
}

void CircularLinkedList::display()
{
	if (head != nullptr)
	{
		Node* current = head;
		do {
			std::cout << current->data << "  ";
			current = current->next;
		} while (current != head);
		std::cout << std::endl;
	}
}

void CircularLinkedList::display(Node* nPtr)
{
	if (head == nullptr)
		return;
	static int counter = 0;
	if ((nPtr != head) || (counter == 0))
	{
		counter = 1;
		std::cout << nPtr->data << " ";
		display(nPtr->next);
	}
	counter = 0;
}

void CircularLinkedList::create(int Arr[], int size)
{
	Node* last;
	head = new Node(Arr[0]);
	head->next = head;
	last = head;
	for (int i = 1; i < size; i++)
	{
		Node* current = new Node(Arr[i]);
		current->next = last->next;
		last->next = current;
		last = current;
	}
}

void CircularLinkedList::insertat(int position, int data)
{
	if ((position == 0) || (head == nullptr))
		return insertBegining(data);
	Node* current = head;
	for (int i = 0; i < position - 1; i++)
	{
		current = current->next;
	}
	Node* newNode = new Node(data);
	newNode->next = current->next;
	current->next = newNode;
}

void CircularLinkedList::insertBegining(int data)
{
	Node* last = head;
	do {
		last = last->next;
	} while (last->next != head);
	Node* newNode = new Node(data);
	newNode->next = head;
	last->next = newNode;
	head = newNode;
}

void CircularLinkedList::deleteat(int pos)
{
	if (pos == 0)
		return deletehead();
	Node* current = head;
	for (int i = 0; i < pos - 2; i++)
		current = current->next;
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
}

void CircularLinkedList::deletehead()
{
	Node* last = head;
	while (last->next != head) {
		last = last->next;
	}
	if (last == head)
	{
		delete head;
		head = nullptr;
	}
	else {
		last->next = head->next;
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}