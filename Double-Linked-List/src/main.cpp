#include<iostream>
#include "DoubleLinkedList.h"
using namespace std;


int main()
{
	DoubleLinkedList *dl = new DoubleLinkedList(5);
	dl->display();
	int Arr[5] = {0, 1, 2, 3, 4};
	dl->create(Arr,5);
	dl->display();
	dl->insertBegin(8);
	dl->display();
	dl->insertat(77, 3);
	dl->display();
	dl->deleteHead();
	dl->display();
	dl->deletekey(3);
	dl->insertat(66, 6);
	dl->display();
	dl->reverse();
	dl->display();
	dl->reverse(dl->getHead());
	dl->display();
	return 0;
}
