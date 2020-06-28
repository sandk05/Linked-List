#include <iostream>
#include <stack>
#include "LinkedList.h"

Node::Node(int content)
{
	data = content;
	next = nullptr;
}

Node::~Node()
{
}

LinkedList::LinkedList()
{
	head = nullptr;
}

void LinkedList::add_Node(int data)
{
	Node* tmp = new Node(data);
	if (head == nullptr)
	{
		head = tmp;
	}
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = tmp;
	}
}

void LinkedList::add_Node(Node* newNode)
{
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

void LinkedList::display()
{
	Node* tmp = head;
	while (tmp)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

void LinkedList::create(int Arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//SortedInsert(Arr[i]);
		add_Node(Arr[i]);
	}
}

Node* LinkedList::interSectionPoint(LinkedList& other)
{
	std::stack<Node*> myStack;
	std::stack<Node*> otherStack;
	Node* current = head;
	Node* point = nullptr;
	while (current)
	{
		myStack.push(current);
		current = current->next;
	}
	current = other.getHead();
	while (current)
	{
		otherStack.push(current);
		current = current->next;
	}
	while ((!myStack.empty()) || (!otherStack.empty()))
	{
		if (myStack.top() == otherStack.top())
		{
			point = myStack.top();
			myStack.pop();
			otherStack.pop();
		}
		else
		{
			return point;
		}
	}
	return nullptr;
}
