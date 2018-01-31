#include "List.h"

int main() {
	cout << "checking constructors..." << endl << endl;
	
	List l1(0);
	l1.pushBack(1);
	
	cout << "l1: " << l1 << endl;
	
	List l2;
	l2.pushFront(2);
	l2.pushFront(1);
	
	l1 = l2; //operator =
	List l3(l2); //copy constructor
	
	cout << "l2: " << l2 << endl;
	cout << "l1: " << l1 << endl;
	cout << "l3: " << l3 << endl;
	
	List test;
	test.pushBack(1);
	test.pushBack(3);
	test.pushBack(4);
	test.pushBack(5);
	test.insert(2, 2);
	test.insert(3, 2);
	test.insert(5, 2);
	cout << "test list: " << test << endl;
	
	cout << "deleting duplicates..." << endl << endl;
	test.deleteDuplicates(2);
	cout << test << endl;
	
	cout << "returning last element..." << endl << endl;
	cout << test.mtoLastElement(0) << endl << endl;
	
	cout << "reversing the list..." << endl << endl;
	test.reverseList();
	cout << test << endl;
	
	cout << "testing merge lists..." << endl << endl;
	
	List one;
	one.pushBack(1);
	one.pushBack(3);
	one.pushBack(7);
	one.pushBack(25);
	one.pushBack(50);
	cout << "list one: " << one << endl;
	
	List two;
	two.pushBack(5);
	two.pushBack(9);
	two.pushBack(11);
	two.pushBack(12);
	two.pushBack(29);
	cout << "list two: " << two << endl;
	
	List merge;
	merge.mergeLists(one, two);
	cout << "mergeLists: " << merge << endl;
	
	return 0;
}
