#include "List.h"

/*
I pretty much reused my code from the doubly linked list for my functions with the idea of the tail pointing
to the head instead of null. Traversing through the list was also different.
If walk points to head and I have while (walk != head)... then the loop will run 0 times because it is already pointing to head.
So what I did is I take a new pointer and point it to head->next. Then I loop that pointer until it finds head.
*/

List::List() {
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;
}

List::List(int data) {
	n = new node;
	n->data = data;
	h = n;
	t = n;
	n->next = NULL;
	size = 1;
}

List::List(const List& rhs) {
//initialize
	node* rhshead = rhs.h;
	node* rhsn = rhs.h;
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;

/*
copy the head data. traverse through the list while n is not head.
copy all the data.
*/
	pushBack(rhshead->data);
	rhsn = rhsn->next;
	while (rhsn != rhshead) {
		pushBack(rhsn->data);
		rhsn = rhsn->next;
	}	
}

List& List::operator=(const List& rhs) {
//delete list first then copy the data	
	deleteList();
	node* rhshead = rhs.h;
	node* rhsn = rhs.h;
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;

	pushBack(rhshead->data);
	rhsn = rhsn->next;
	while (rhsn != rhshead) {
		pushBack(rhsn->data);
		rhsn = rhsn->next;
	}		
}

List::~List() {
	deleteList();
}

void List::deleteList() {
/*
traverse to the list while walk is not the tail.
walk = tail at the end of traverse.
delete temp and delete walk at the end.
*/
	if (h == NULL)
		return;
	node* walk = h;
	while(walk != t) {
		node* temp = walk;
		walk = walk->next;
		delete temp;
	}
	delete walk;
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;	
}

ostream& operator<<(ostream& out, const List& rhs) {
	if (rhs.h == NULL) {
		out << "List is empty" << endl;
		return out;
	} else if (rhs.size == 1) {
		out << rhs.h->data << " -> restart";
		return out;
	} else {
		node* walk = rhs.h;
		out << rhs.h->data << " -> ";
		walk = walk->next;
		while (walk != rhs.h) {
			out << walk->data << " -> ";
			walk = walk->next;
		}
		out << "restart" << endl;
		return out;
	}
}

void List::print() {
//checking head and tail and also if tail cycles back to head.
	cout << "head: " << h->data << endl;
	cout << "tail: " << t->data << endl;
	cout << "tail->next: " << t->next->data << endl;
}

void List::pushFront(int data) {
//just like doubly linked list but t->next points back to head.
	if (size == 0) {
		n = new node;
		n->data = data;
		h = n;
		t = n;
		t->next = h;
	} else {
		n = new node;
		n->data = data;
		n->next = h;
		h = n;
		t->next = h;
	}
	size++;
}

void List::pushBack(int data) {
	if (size == 0) {
		n = new node;
		n->data = data;
		h = n;
		t = n;
		t->next = h;		
	} else {
		n = new node;
		n->data = data;
		t->next = n;
		t = n;
		t->next = h;
	}
	size++;
}

void List::popFront() {
	if (size == 1) {
		node* temp = h;
		h = NULL;
		t = NULL;
		n = NULL;
		delete temp;
	} else {
		node* temp = h;
		h = h->next;
		t->next = h;
		delete temp;
	}
	--size;
}

void List::popBack() {
	if (size == 1) {
		node* temp = h;
		h = NULL;
		t = NULL;
		n = NULL;
		delete temp;
	} else {
		node* temp = t;
		t = h;
		for (int i = 1; i < size - 1; i++) {
			t = t->next;
		}
		t->next = h;
		delete temp;
	}
	--size;
}

void List::insert(int index, int data) {
	if (index > size + 1 || index <= 0) {
		cout << "Invalid Insert!" << endl;
	} else if (index == 1) {
		pushFront(data);
	} else if (index == size + 1) {
		pushBack(data);
	} else if (index > 1 && index < size + 1) {
		n = new node;
		n->data = data;
		node* cur = h;
		node* prev = NULL;
		for (int i = 1; i < index; i++) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = n;
		n->next = cur;
		size++;
	}
}

void List::deleteDuplicates(int data) {
	node* p = NULL;
	node* c = h;
	while (c->data != data)
		c = c->next;
	p = c;
	c = c->next;
	while(c->next != h) {
		if (c->data == data) {
			p->next = c->next;
			--size;
			delete c;
			c = p->next;
		} else {
			p = c;
			c = c->next;
		}
	}
	if (c->data == data) {
		t = p;
		t->next = h;
		--size;
		delete c;
	}
}

int List::mtoLastElement(int m) {
	node* walk = h;
	int s = getSize();
	
    if (m >= s){
        cout << "Invalid" << endl;
        return 0;
    } else if (m < 0) {
    	cout << "Invalid" << endl;
    	return 0;
	}
	
    for (int i = 1; i < s-m; i++)
        walk = walk->next;
   
    return walk->data;		
}

int List::getSize() {
	return size;
}

void List::reverseList() {
	node* prev = t;
	node* cur = h;
	for (int i = 1; i < size + 1; i++) {
		n = cur->next;
		cur->next = prev;
		prev = cur;
		cur = n;
	}
	h = prev;
	t = n;
	t->next = h;
}

void List::mergeLists(List& one, List& two) {
	if (one.h == NULL) {
		pushBack(two.h->data);
		two.n = two.h;
		two.n = two.n->next;
		while (two.n != two.h) {
			pushBack(two.n->data);
			two.n = two.n->next;
		}
		return;
	} else if (two.h == NULL) {
		pushBack(one.h->data);
		one.n = one.h;
		one.n = one.n->next;
		while (one.n != one.h) {
			pushBack(one.n->data);
			one.n = one.n->next;
		}
		return;
	}
	
	while (one.h != NULL && two.h != NULL) {
		if (one.h->data <= two.h->data) {
			pushBack(one.h->data);
			one.popFront();
		} else {
			pushBack(two.h->data);
			two.popFront();
		}
	}
	if (one.h != NULL) {
		node* walk = one.h;
		for (int i = 0; i < one.getSize(); i++) {
			pushBack(one.h->data);
			one.h = one.h->next;
		}
		one.deleteList();
	} else if (two.h != NULL) {
		for (int i = 0; i < two.getSize(); i++) {
			pushBack(two.h->data);
			two.h = two.h->next;
		}
		two.deleteList();	
	}
}
