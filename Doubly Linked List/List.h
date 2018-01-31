#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class List {
	
private:
	node* h;
	node* t;
	node* n;
	int size;

public:
	List();
	List(int data);
	List(const List& rhs);
	List& operator=(const List& rhs);
	~List();
	void deleteList();
	
	friend ostream& operator<<(ostream& out, const List& rhs);
	void pushFront(int data);
	void pushBack(int data);
	void popFront();
	void popBack();
	
	void insert(int index, int data);
	void deleteDuplicates(int data);
	int mtoLastElement(int m);
	int getSize();
	void reverseList();
	void mergeLists(List& one, List& two);
};

