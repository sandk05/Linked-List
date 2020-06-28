#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

int main()
{
	CircularLinkedList cl;
	int Arr[] = {1, 2, 3, 4, 5};
	cl.create(Arr,5);
	cl.display();
	//cl.display(cl.gethead());
	cl.insertat(0,8);
	cl.display();
	cl.insertBegining(0);
	cl.display();
	cl.deleteat(1);
	cl.display();
	cl.deletehead();
	cl.display();
	return 0;
}
