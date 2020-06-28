## Intersection Point Of Two Linked Lists

This is a simple implementation of a method to find intersection points of two linked lists. 



Constructor 

```c++
LinkedList();
```
Adding Nodes in the Linked Lists
```C++
void add_Node(int data);
void add_Node(Node* newNode);
```
Display all nodes of the list.
```c++
void display();
void display(Node* nPtr); //RECURSIVE METHOD
```
Create a linked list with given array
```c++
void create(int Arr[], int size);
```
Methods provided to create an intersection, loops of Nodes
```c++
Node* getHead() { return head; }
Node* getthird() { return head->next->next; }
void setHead(Node* aPtr) { head = aPtr; }
```
Find if an node is element is present in the Linked List
```c++
Node* search(int key);
Node* search(Node* nPtr, int key);
```

Public methods which give information about the Linked List

```C++
int count(); //Number Of Nodes
int count(Node* nPtr);
int sum();  //Sum of All Node data
int sum(Node* nPtr);
int largest(Node* nPtr); //Largest Node
int smallest(Node* nPtr); //Smallest Node
```
Methods for adding nodes

```c++
void insertfront(int data); //HEAD Node
void insertAt(int position, int data); //At Position
void SortedInsert(int value); //Insert into sorted Linked List
```

Verify if Node is sorted

```c++
bool isSorted();
```

Remove Node from Linked List

```c++
void remove(int value); //Remove individual Node with key
void removeDuplicates(); //Remove all duplicate Nodes
```

Reverse a Linked List

```c++
void reverse(Node* prev, Node* curr); //Recursive
void reverse(); //Iterative
```

Appending And Merging two Linked Lists

```c++
void concat(LinkedList& other);
void operator+(LinkedList& other);
LinkedList* merge(LinkedList& other);
```

Creating Loop , Verifying Loop Status and Removing Loop

```c++
void createLoop();
bool isLoop();
void removeloop();
```

