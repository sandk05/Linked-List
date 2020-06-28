#include <iostream>
#include "LinkedList.h"
using namespace std;


int main()
{
	LinkedList ll, l2; 
	int Arr1[] = { 1, 3 , 5 , 7 , 9, 11, 13, 15, 17, 19};
	int Arr2[] = { 2, 4 , 6 , 8 , 10};
	ll.create(Arr1,10);
	l2.create(Arr2,5);
	l2.add_Node(ll.getthird());

	ll.display();
	l2.display();

	Node* node = ll.interSectionPoint(l2);
	cout<<" InterSection Node is at " <<node <<" with data "<<node->data <<endl;
	return 0;
}
