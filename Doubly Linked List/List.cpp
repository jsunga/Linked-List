#include "List.h"

List::List() {
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;
}

List::List(int data) {
/*
create new node with data. head points to the node. tail points to the node.
node prev and next are null.
*/	
	n = new node;
	n->data = data;
	h = n;
	t = n;
	n->prev = NULL;
	n->next = NULL;	
	size = 1;
}

List::List(const List& rhs) {
//initialize
	node* rhshead = rhs.h;
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;

//traverse through list rhs. create a new copy for each iteration.

	while (rhshead != NULL) {
		pushBack(rhshead->data);
		rhshead = rhshead->next;
	}	
}

List& List::operator=(const List& rhs) {
//to replace the list with rhs, empty the list first, then initialize it.
	deleteList();
	node* rhshead = rhs.h;
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;
//copy rhs to the list
	while (rhshead != NULL) {
		pushBack(rhshead->data);
		rhshead = rhshead->next;
	}	
}

List::~List() {	
	deleteList();
}

void List::deleteList() {
	if (h == NULL)
		return;
	node* walk = h;
	while(walk != NULL) {
		node* temp = walk;
		walk = walk->next;
		delete temp;
	}
	h = NULL;
	t = NULL;
	n = NULL;
	size = 0;
}

ostream& operator<<(ostream& out, const List& rhs) {
	if (rhs.h == NULL) {
		out << "head->NULL" << endl;
		return out;
	}
	out << "NULL - ";
	node* walk = rhs.h;
	while (walk != NULL) {
		cout << walk->data << " - ";
		walk = walk->next;
	}
	out << "NULL" << endl;
	return out;
}

void List::pushFront(int data) {
/*
case 1: empty list
see custom constructor

case 2: 1 or more nodes in the list
create node with data. n links with head both ways (next and prev).
h points to n. 
*/
	if (size == 0) {
		n = new node;
		n->data = data;
		h = n;
		t = n;
		n->prev = NULL;
		n->next = NULL;		
	} else {
		n = new node;
		n->data = data;
		n->next = h; //double link
		h->prev = n; //double link
		h = n;
		n->prev = NULL; 
	}
	size++;
}

void List::pushBack(int data) {
/*
since this is a doubly linked list,
pushBack is like the reverse of pushFront,
switching from head and tail and prev and next
*/
	if (size == 0) {
		n = new node;
		n->data = data;
		h = n;
		t = n;
		n->prev = NULL;
		n->next = NULL;
	} else {
		n = new node;
		n->data = data;
		n->prev = t;
		t->next = n;
		t = n;
		n->next = NULL;
	}
	size++;
}

void List::popFront() {
/*
case 1: there is only one node in the list
point head and tail to NULL and delete temp

case 2: more than one node
head becomes right node. delete first node.
head.prev points to null.
*/
	if (size == 1) {
		node* temp = t;
		t = temp->prev;
		h = NULL;
		delete temp;
	} else {
		node* temp = h;
		h = h->next;
		h->prev = NULL;
		delete temp;
	}
	--size;
}

void List::popBack() {
/*
same as popFront but reverse.
use tail instead of head
*/
	if (size == 1) {
		node* temp = t;
		t = temp->prev;
		h = NULL;
		delete temp;		
	} else {
		node* temp = t;
		t = t->prev;
		t->next = NULL;
		--size;
		delete temp;
	}
}

void List::insert(int index, int data) {
/*
case 1: invalid input
case 2: index is 1 then pushFront
case 3: index is size + 1 then pushBack
case 4: index in between front and back
use prev and cur pointers to insert node and connect
the necessary links
*/
	if (index > size + 1 || index <= 0) {
		cout <<"Invalid Insert!" << endl;
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
		n->prev = prev;
		n->next = cur;
		cur->prev = n;
	} else if (index == 1) {
		pushFront(data); 		
	} else if (index == size + 1) {
		pushBack(data);
	}
	size++;
}

void List::deleteDuplicates(int data) {
/*
first traverse
c traverse to the list till it finds first data.
p points to node of data and c points to the next node. 

second traverse (traverse the entire list)
p is always behind c
if c finds data again, p.next points to c.next, delete c, then c moves to the next node.
c.prev points to p creating a double link.
repeat this till the end of list.
*/
	node* p = NULL;
	node* c = h;
	while (c->data != data)
		c = c->next;
	p = c;
	c = c->next;
	while (c->next != NULL) {
		if (c->data == data) { 
			p->next = c->next;
			--size;
			delete c;
			c = p->next;
			c->prev = p;
		} else {
		p = c;
		c = c->next;
		}
	}
	if (c->data == data) {
		p->next = NULL;
		--size;
		delete c;
	}
}

int List::mtoLastElement(int m) {
/*
traverse to list
stop at the (size - m) node
*/
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
/*
since this is a doubly linked list, I use
node prev to my advantage.
traverse to the list and change the links.
also switch the head and tail
*/
	node* temp = NULL;
	node* c = h;
	while(c != NULL) {
		temp = c->prev;
		c->prev = c->next;
		c->next = temp;
		c = c->prev;
	}
	if (temp != NULL)
		h = temp->prev;
	n = h;
	while (n->next != NULL)
		n = n->next;
	t = n;
}

void List::mergeLists(List& one, List& two) {
/*
in this while loop, i compare the heads of the two lists.
i use the pushBack function to copy nodes from the two lists into the new list.
if i copy a node, i delete the node i copied and change the head accordingly.
when one of the lists becomes empty, i just copy the rest of the other list nodes which are
already sorted.
*/
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
