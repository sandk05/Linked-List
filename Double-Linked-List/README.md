

# Double Linked List

A simple implementation of Double Linked List in C++

Creates and empty Double Linked List or a list with root with data provided as parameter

```c++
DoubleLinkedList();
DoubleLinkedList(int val);
```

Provides method to create a Double linked list with an array of values
```c++
void create(int Arr[], int size);
```

Display contents of a Double Linked List in order
```c++
void display();
```

Method to insert a new node at a position or begining
```C++
void insertat(int data, int position);
void insertBegin(int data);
```

Method to delete a node at the begining or at a position
```c++
void deleteHead();
void deletekey(int key);
```

Returns head node of the Double Linked List
```C++
Node* getHead() { return head; }
```

Reverse a Double Linked List using iteration and recursion
```C++
void reverse();
void reverse(Node* current);
```