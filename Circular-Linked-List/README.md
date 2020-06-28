# Circular Linked List

A Simple Implementation Of Circular Linked List in C++

Default Constructor: Creates an empty Linked List.
```c++
 CircularLinkedList();
```
Displays contents of the linked list.
```c++
void display();
```
Displays content of linked list using recursion
```c++
void display(Node* nPtr);
```
Returns the head node of linked list
```c++
Node* gethead() { return head; };
```
A method used to create a linked list with an array of values
```c++
void create(int Arr[], int size);
```
Insert a node at agiven position
```c++
void insertat(int position, int data);
```
Insert node as head node
```c++
void insertBegining(int data);
```
Delete node at a position
```c++
void deleteat(int pos);
```
Deletes the head node
```c++
void deletehead();
```