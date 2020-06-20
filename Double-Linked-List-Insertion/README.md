# Inserting a Node Into

# a Sorted Doubly

# Linked List

Given a reference to the head of a doubly-linked list and an integer, ***data*** , create a new *DoublyLinkedListNode* object having data value ***data*** and insert it into a sorted linked list.

**Input Format**
The first line contains an integer ***t***, the number of test cases.
Each of the test case is in the following format:
- The first line contains an integer ***n***, the number of elements in the linked list.
- Each of the next ***n*** lines contains an integer, the data for each node of the linked list.
- The last line contains an integer ***data*** which needs to be inserted into the sorted doubly-linked list.

**Constraints**
- **1 <= *t* <= 10**
- **1 <= *n* <= 1000**
- **1 <= *list*[*i*] <= 1000**

**Output Format**
Print the list with the new data at correct position

**Sample Input**
```
1
4
1
3
4
10
5
```
**Sample Output**
```
1 3 4 5 10
```
**Explanation**
The initial doubly linked list is: **1 &hArr; 3 &hArr; 4 &hArr;10 &rArr;*NULL***.
The doubly linked list after insertion is: **1 &hArr; 3 &hArr; 4 &hArr;5 &hArr;10 &rArr;*NULL***
