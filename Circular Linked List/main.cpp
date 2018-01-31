#include "List.h"

int main() {
	cout << "checking constructors..." << endl << endl;
	
	List l1(0);
	l1.pushBack(1);
	
	cout << "l1: " << l1 << endl;
	l1.print();
	cout << endl;
	
	List l2;
	l2.pushFront(2);
	l2.pushFront(1);
	
	l1 = l2; //operator =
	List l3(l2); //copy constructor
	
	cout << "l2: " << l2 << endl;
	l2.print();
	cout << endl;
	cout << "l1: " << l1 << endl;
	l1.print();
	cout << endl;
	cout << "l3: " << l3 << endl;
	l3.print();
	cout << endl;
	
	List test;
	test.pushBack(1);
	test.pushBack(3);
	test.pushBack(4);
	test.pushBack(5);
	test.insert(2, 2);
	test.insert(3, 2);
	test.insert(5, 2);
	cout << "test list: " << test << endl;
	test.print();
	cout << endl;
	
	cout << "deleting duplicates..." << endl << endl;
	test.deleteDuplicates(2);
	cout << test << endl;
	test.print();
	cout << endl;
	
	cout << "returning last element..." << endl << endl;
	cout << test.mtoLastElement(0) << endl << endl;
	
	cout << "reversing the list..." << endl << endl;
	test.reverseList();
	cout << test << endl;
	test.print();
	cout << endl;
	
	cout << "testing merge lists..." << endl << endl;
	
	List one;
	one.pushBack(1);
	one.pushBack(3);
	one.pushBack(7);
	one.pushBack(25);
	one.pushBack(50);
	cout << "list one: " << one << endl;
	one.print();
	cout << endl;
	
	List two;
	two.pushBack(5);
	two.pushBack(9);
	two.pushBack(11);
	two.pushBack(12);
	two.pushBack(29);
	cout << "list two: " << two << endl;
	two.print();
	cout << endl;
	
	List merge;
	merge.mergeLists(one, two);
	cout << "mergeLists: " << merge << endl;
	merge.print();
	cout << endl;
	return 0;
}
