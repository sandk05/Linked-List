#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList ll, l2; 
	int Arr1[] = { 1, 3 , 5 , 7 , 9, 1, 3, 7, 5, 9};
	int Arr2[] = { 2, 4 , 6 , 8 , 10};
	ll.create(Arr1,10);
	l2.create(Arr2,5);
	ll.display();
	ll.reverse();
	ll.display();
	ll.removeDuplicates();
	ll.display();
	return 0;
}
