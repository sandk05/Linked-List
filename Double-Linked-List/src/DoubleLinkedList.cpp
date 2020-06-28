#include <iostream>
#include "DoubleLinkedList.h"

Node::Node(int val)
{
	data = val;
	prev = nullptr;
	next = nullptr;
}

DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
}

DoubleLinkedList::DoubleLinkedList(int val)
{
	head = new Node(val);
}

DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = head;
	while (current)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

void DoubleLinkedList::create(int Arr[], int size)
{
	Node* tail = head;
	for (int i = 0; i < size; i++)
	{
		Node* newNode = new Node(Arr[i]);
		newNode->prev = tail;
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}

void DoubleLinkedList::display()
{
	Node* current = head;
	while (current)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

void DoubleLinkedList::insertat(int data, int position)
{
	if ((position == 0) || (head == nullptr))
		return insertBegin(data);
	Node* current = head;
	Node* newNode = new Node(data);
	for (int i = 0; i < position - 1; i++)
		current = current->next;
	if (current->next)
	{
		current->next->prev = newNode;
		newNode->next = current->next;
	}
	else {
		newNode->next = nullptr;
	}
	if (current)
	{
		newNode->prev = current;
		current->next = newNode;
	}
}

void DoubleLinkedList::insertBegin(int data)
{
	Node* newNode = new Node(data);

	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

void DoubleLinkedList::deleteHead()
{
	Node* temp = head;
	head->next->prev = nullptr;
	head = head->next;
	delete temp;
}

void DoubleLinkedList::deletekey(int key)
{
	if (!head)
		return;
	Node* temp = head;
	if (head->data == key)
		return deleteHead();
	while ((temp->data != key) && (temp != nullptr))
	{
		temp = temp->next;
	}
	if (!temp)
		return;
	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	delete temp;
}

void DoubleLinkedList::reverse()
{
	Node* prev = nullptr, * current = head, * next = nullptr;
	while (current)
	{
		next = current->next;
		current->next = prev;
		current->prev = next;

		prev = current;
		current = next;
	}
	head = prev;
}

void DoubleLinkedList::reverse(Node* current)
{
	if (current == nullptr)
		return;
	Node* next = current->next;
	current->next = current->prev;
	current->prev = next;

	if (current->prev == nullptr)
	{
		head = current;
		return;
	}

	return reverse(current->prev);

}


