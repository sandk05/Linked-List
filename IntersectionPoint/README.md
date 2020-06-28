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
```
Create a linked list with given array
```c++
void create(int Arr[], int size);
```
Methods provided to create an intersection of Nodes
```c++
Node* getHead() { return head; }
Node* getthird() { return head->next->next; }
```
Public Method to find the intersection point
```c++
Node* interSectionPoint(LinkedList& other);
```
