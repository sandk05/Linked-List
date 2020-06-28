#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <climits>
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

LinkedList::~LinkedList()
{
	Node* current;
	if (isLoop())
		removeloop();
	while (head)
	{
		current = head;
		head = head->next;
		//cout << "Deleting " << current->data << endl;
		delete current;
	}
	head = nullptr;
	//cout << endl;
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

void LinkedList::display(Node* nPtr)
{
	if (nPtr != nullptr)
	{
		std::cout << nPtr->data << " ";
		return display(nPtr->next);
		//cout <<nPtr->data <<" "; //REVERSE
	}
	std::cout << std::endl;
}

int LinkedList::count()
{
	int c = 0;
	Node* tmp = head;
	while (tmp)
	{
		c++;
		tmp = tmp->next;
	}
	return c;
}

int LinkedList::count(Node* nPtr)
{
	if (nPtr != nullptr)
		return count(nPtr->next) + 1;
	return 0;
}

int LinkedList::sum()
{
	int sum = 0;
	Node* tmp = head;
	while (tmp)
	{
		sum += tmp->data;
		tmp = tmp->next;
	}
	return sum;
}

int LinkedList::sum(Node* nPtr)
{
	if (nPtr != nullptr)
		return sum(nPtr->next) + nPtr->data;
	return 0;
}

int LinkedList::largest(Node* nPtr)
{
	if (nPtr != nullptr)
		return std::max(largest(nPtr->next), nPtr->data);
	return INT_MIN;
}

int LinkedList::smallest(Node* nPtr)
{
	if (nPtr != nullptr)
		return std::min(smallest(nPtr->next), nPtr->data);
	return INT_MAX;
}

Node* LinkedList::search(int key)
{
	Node* tmp = head;
	while (tmp)
	{
		if (tmp->data == key)
			return tmp;
		tmp = tmp->next;
	}
	return nullptr;
}

Node* LinkedList::search(Node* nPtr, int key)
{
	if (nPtr != nullptr)
	{
		if (key == nPtr->data)
			return nPtr;
		return search(nPtr->next, key);
	}
	return nullptr;
}

void LinkedList::create(int Arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//SortedInsert(Arr[i]);
		add_Node(Arr[i]);
	}
}

void LinkedList::createLoop()
{
	Node* loop1, * loop2;

	loop1 = head->next->next;
	loop2 = head->next->next->next->next;
	loop2->next = loop1;

}

void LinkedList::insertfront(int data)
{
	Node* tmp = new Node(data);
	tmp->next = head;
	head = tmp;
}

void LinkedList::insertAt(int position, int data)
{
	if (position == 0)
		return insertfront(data);
	Node* tmp = new Node(data);
	Node* tPtr = head;
	for (int i = 0; i < position - 1; i++)
	{
		if (tPtr)
			tPtr = tPtr->next;
		else
		{
			std::cout << "Impossible Action" << std::endl;
			return;
		}
	}
	tmp->next = tPtr->next;
	tPtr->next = tmp;
}

void LinkedList::SortedInsert(int value)
{

	if ((head == nullptr) || head->data > value)
		return insertfront(value);
	Node* temp = new Node(value);
	Node* current = head;
	while ((current->next != nullptr) && (current->next->data < value))
		current = current->next;
	temp->next = current->next;
	current->next = temp;
}

void LinkedList::remove(int value)
{
	if (head == nullptr)
	{
		return;
	}
	if (head->data == value)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	Node* current = head;
	Node* prev;
	while ((current != nullptr) && (current->data != value))
	{
		prev = current;
		current = current->next;
	}
	if (current == nullptr)
		return;
	prev->next = current->next;
	delete current;
}

bool LinkedList::isSorted()
{
	Node* current = head;
	int val = INT_MIN;
	while (current->next != nullptr)
	{
		if (val > current->data)
			return false;
		val = current->data;
		current = current->next;
	}
	return true;
}

void LinkedList::removeDuplicates()
{
	std::unordered_set<int> element_list;
	Node* current = head;
	Node* prev = nullptr;
	while (current != nullptr)
	{

		if (element_list.find(current->data) != element_list.end())
		{
			if (current->next)
				prev->next = current->next;
			else
				prev->next = nullptr;
			delete current;
		}
		else
		{
			element_list.insert(current->data);
			prev = current;
		}
		current = prev->next;
	}
}

void LinkedList::reverse(Node* prev, Node* curr)
{
	if (curr != nullptr)
	{
		reverse(curr, curr->next);
		curr->next = prev;
	}
	else
	{
		head = prev;
	}
}

void LinkedList::reverse()
{
	Node* prev = nullptr, * current = head, * next;
	while (current)
	{
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	head = prev;
}

void LinkedList::concat(LinkedList& other)
{
	Node* current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = other.getHead();
	other.setHead(nullptr);
}

void LinkedList::operator+(LinkedList& other)
{
	this->concat(other);
}

LinkedList* LinkedList::merge(LinkedList& other)
{
	LinkedList* rList = new LinkedList;
	Node* first = head;
	Node* second = other.getHead();
	Node* third = nullptr;
	Node* last = nullptr;
	if (first->data < second->data)
	{
		third = first;
		last = first;
		first = first->next;
		last->next = nullptr;
	}
	else
	{
		third = second;
		last = second;
		second = second->next;
		last->next = nullptr;
	}
	while ((first != nullptr) && (second != nullptr))
	{
		if (first->data < second->data)
		{
			last->next = first;
			last = first;
			first = first->next;
			last->next = nullptr;
		}
		else
		{
			last->next = second;
			last = second;
			second = second->next;
			last->next = nullptr;
		}
	}
	if (first != nullptr)
		last->next = first;
	if (second != nullptr)
		last->next = second;
	rList->setHead(third);
	return rList;
}

bool LinkedList::isLoop()
{
	Node* slow = head, * fast = head;
	while (true)
	{
		slow = slow->next;
		if (fast->next != nullptr)
			fast = fast->next->next;
		else
			return false;
		if ((slow == nullptr) || (fast == nullptr))
			return false;
		if (slow == fast)
			return true;
	}

}

void LinkedList::removeloop()
{
	return removeloop(loopNode());
}

Node* LinkedList::loopNode()
{
	Node* slow = head, * fast = head;
	while (true)
	{
		slow = slow->next;
		if (fast->next != nullptr)
			fast = fast->next->next;
		else
			return nullptr;
		if ((slow == nullptr) || (fast == nullptr))
			return nullptr;
		if (slow == fast)
			return slow;
	}
}

void LinkedList::removeloop(Node* loopNode)
{
	if (!loopNode)
		return;
	Node* tHead = head;
	Node* current;

	while (1)
	{
		current = loopNode;
		while (current->next != loopNode && current->next != tHead)
			current = current->next;

		if (current->next == tHead)
			break;

		tHead = tHead->next;
	}
	current->next = nullptr;
}
