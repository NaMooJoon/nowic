// 03분반 21800179 김준현
/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: 김준현 Section:  03분반 Student  Number: 21800179
*/

#include <iostream>
#include <cassert>
#include <iomanip>
#include "listds.h"
using namespace std;

// returns the first node which List::head points to in the container.
Node* begin(List* p) {
	return p->head->next;
}

// returns the tail node referring to the past -the last- node in the list.
// The past -the last- node is the sentinel node which is used only as a sentinel
// that would follow the last node. It does not point to any node next, and thus
// shall not be dereferenced. Because the way we are going use during the iteration,
// we don't want to include the node pointed by this. this function is often used
// in combination with List::begin to specify a range including all the nodes in
// the list. This is a kind of simulated used in STL. If the container is empty,
// this function returns the same as List::begin.
Node* end(List* p) {
	return p->tail;          // not tail->next
}

Node* last(List* p) {
	return p->tail->prev;
}

// returns the first node of the second half of the list.
Node* half(List* p) {
	Node* rabbit = begin(p);
	Node* turtle = begin(p);
	while (rabbit != end(p) && rabbit->next != end(p)) {
	  rabbit = rabbit->next->next;
	  turtle = turtle->next;
	}
	return turtle;
}

// returns the first node with a value found, nullptr otherwise.
Node* find(List* p, int val) {
	DPRINT(cout << ">find val=" << val << endl;);
	Node* c = begin(p);
	for (; c != end(p); c = c->next)
		if (c->item == val) return c;

	DPRINT(cout << "<find - not found\n";);
	return c;
}

// Removes all elements from the list container(which are destroyed),
// and leaving the container with a size of 0.
void clear(List* p) {
	if (empty(p)) return;

	DPRINT(cout << ">clear: ";);
	Node* curr = begin(p);
	Node* head = curr->prev;		// saved head node
	while (curr != end(p)) {
		Node* prev = curr;
		curr = curr->next;
		DPRINT(cout << prev->item << " ";);
		delete prev;
	}
	DPRINT(cout << endl;);

	p->head->next = p->tail;			// set tail at head
	p->tail->prev = p->head;			// set head at tail
	cout << "\tAll things are cleared.\n";
}

// returns true if the list is empty, false otherwise.
// To clear a list, see List::clear.
bool empty(List* p) {
	return begin(p) == end(p);
}

// returns the number of nodes in the list container.
int size(List* p) {
	int count = 0;
	for (Node* c = begin(p); c != end(p); c = c->next)
		count++;
	return count;
}

//////////////////////////////////////////////////////////////////////////
/////////// Make the best use of the following two fucntions  ////////////
///////////         insert() and erase()                      ////////////
//////////////////////////////////////////////////////////////////////////
// inserts a new node with val at the position of the node x.
// The new node is actually inserted in front of the node x.
// This effectively increases the list size by one.
void insert(Node* x, int val) {
	DPRINT(cout << ">insert val=" << val << endl;);
	Node* node = new Node( val, x->prev, x );
	x->prev = x->prev->next = node;
	DPRINT(cout << "<insert\n";);
}

// removes from the list a single node x given.
// This effectively reduces the container by one which is destroyed.
// It is specifically designed to be efficient inserting and removing
// a node regardless of its positions in the list such as front, back
// or in the middle of the list.
void erase(Node* x) {
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}

void erase(List* p, Node* x) {	// checks if x is either tail or head
	if (x == p->tail || x == p->head || x == nullptr) return;
	x->prev->next = x->next;
	x->next->prev = x->prev;
	delete x;
}
///////////////////////////////////////////////////////////////////////////

/////////////////////// pop ///////////////////////////////////////////////
// removes the first node in the list.
// This destroys the removed node, and reduces its size by one.
void pop_front(List* p) {
	DPRINT(cout << ">pop_front\n";);
	erase(p, begin(p));
	DPRINT(cout << "<pop_front\n";);
}

// removes the last node in the list, and reduces the list size
// by one. This destroys the removed node.
void pop_back(List* p) {
	DPRINT(cout << ">pop_back\n";);
	if (!empty(p)) erase(end(p)->prev);
	DPRINT(cout << "<pop_back\n";);
}

// removes the first node with val from the list and does nothing if not found.
// Unlike member function List::erase which erases a node by its position,
// this function removes a node by its value.
// Unlike pop(), pop_all() removes all the nodes with the value given.
void pop(List* p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	erase(p, find(p, val));
	DPRINT(cout << "<pop\n";);
}

// removes from the list all the nodes with the same value given.
// This calls the destructor of these objects and reduces the list size
// by the number of nodes removed.  Unlike erase(), which erases a node
// by its position, this function removes nodes by its value.
// Unlike pop_all(), pop() removes the first node with the value given.
void pop_all(List* p, int val) {
	DPRINT(cout << ">pop_all val=" << val << endl;);
	for(Node* c = begin(p); c != end(p); c = c->next) {
		if(c->item == val) {
			Node* x = c; // x는 삭제를 하기위한 임시 저장 포인터.
			c = c->prev;
			erase(x);
		}
	}
	DPRINT(cout << "<pop_all\n";);
}

// deletes N number of nodes, starting from the end.
// It deletes all the nodes if N is zero which is the default or out of
// the range of the list.
// Since it simply calls pop_back() which is O(1) repeatedly, it is O(n).
void pop_backN(List* p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);
	int psize = size(p);
	if (N <= 0 || N > psize) N = psize;
	for (int i = 0; i < N; i++) {
		if (i % 10000 == 0)
			cout << setw(7) << "\r\tdeleting in [" << psize - i - 1 << "]        ";
		pop_back(p);
	}
	cout << "\n";
	DPRINT(cout << "<pop_backN\n";);
}

/////////////////////// push ///////////////////////////////////////////////
// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
void push_front(List* p, int val) {		// inserts a node at front of list
	DPRINT(cout << ">push_front val=" << val << endl;);
	insert(begin(p), val);
	DPRINT(cout << "<push_front\n";);
}

// adds a new node with val at the end of the list and returns the
// first node of the list. This effectively increases the list size by one.
void push_back(List* p, int val) {
	DPRINT(cout << ">push_back val=" << val << endl;);
	insert(end(p), val);
	DPRINT(cout << "<push_back\n";);
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
void push(List* p, int val, int x) {
	DPRINT(cout << ">push val=" << val << endl;);
	Node* pos = find(p, x);
	if(pos == nullptr)
		push_front(p, val);
	else
		insert(find(p, x), val);

	DPRINT(cout << "<push\n";);
}

// adds N number of new nodes at the end of the list, O(1)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
void push_backN(List* p, int N, int val) {
	DPRINT(cout << ">push_backN N=" << N;);
	int psize = size(p);

	if (val == 0) {
		int range = N + psize;
		srand((unsigned)time(NULL));

		for (int i = 0; i < N; i++) {
			int val = ((long)rand() * RAND_MAX + rand()) % range;
			push_back(p, val);
			if (i % 10000 == 0)
				cout << setw(7) << "\r\tinserting in [" << i + psize << "]=" << val << "        ";
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			push_back(p, val);
			if (i % 10000 == 0)
				cout << setw(7) << "\r\tinserting in [" << i + psize << "]=" << val << "        ";
		}
	}
	cout << "\n";

	DPRINT(cout << "<push_backN\n";);
}

/////////////////////// unique, reverse, shuffle ///////////////////////////
// removes extra nodes that have duplicate values from the list.
// It removes all but the last node from every consecutive group of
// equal nodes in the list. Notice that a node is only removed from
// the list if it compares equal to the node immediately preceding it.
// Thus, this function is especially useful for sorted lists. O(n)
void unique(List* p) {
	DPRINT(cout << ">unique N=" << size(p) << endl;);
	if (size(p) <= 1) return;

	for (Node* c = begin(p); c != end(p); c = c->next)
    	if (c->item == c->prev->item){
			Node* x = c;
			c = c->prev;
      		erase(x);
		}

	DPRINT(cout << "<unique";);
}

// reverses the order of the nodes in the list.
// The entire operation does not involve the construction,
// destruction or copy of any element. Nodes are not moved,
// but pointers are moved within the list. O(n)
void reverse(List* p) {
	DPRINT(cout << ">reverse\n";);
	if (size(p) <= 1) return;

	// hint: swap prev and next in every node including head & tail
	// then, swap head and tail.
	// hint: use while loop, don't use begin()/end()

	for(Node* c = p->head; c != nullptr;){
		Node* x = c;
		c = c->next;
		swap(x->prev, x->next);
	}
	swap(p->head, p->tail);

	DPRINT(cout << "<reverse\n";);
}

// returns so called "perfectly shuffled" list.
// The first half and the second half are interleaved each other.
// The shuffled list begins with the second half of the original p.
// For example, 1234567890 returns 617283940.
void shuffle(List* p) {
	DPRINT(cout << ">shuffle\n";);
	if (size(p) <= 1) return;    // nothing to shuffle

	// find the mid node of the list p to split it into two lists.
	Node* mid = half(p);
	Node* que = begin(p);
	// remove 1st half from the list p, and keep it as a list "que".
	mid->prev->next = nullptr;	// set the last node of que terminated by null
	que->prev = nullptr;		// the que does not have sentinel nodes

	// set the list p head such that it points the "mid" of the list p.
	mid->prev = p->head;		// the list "mid" becomes the list p.
	p->head->next = mid;		// the list "mid" now has two sentinel nodes

	// interleave nodes in the "que" into "mid" in the list of p.
	// start inserting 1st node in "que" at 2nd node in "mid".
	Node* _que = que;
	Node* _mid = begin(p);
	while(_que != nullptr) {
		Node* _mid2 = _mid->next;	// mid->next를 임시 저장할 노드
		Node* _que2 = _que->next;	// que->next를 임시 저장할 노드
		_mid->next->prev = _que;
		_que->next = _mid->next;
		_mid->next = _que;
		_que->prev = _mid;

		_mid = _mid2;
		_que = _que2;
	}


	DPRINT(cout << "<shuffle\n";);
}

///////////////////////// sort /////////////////////////////////////////////
int ascending (int a, int b) { return a - b; };
int descending(int a, int b) { return b - a; };
int more(int a, int b) { return (a - b); }
int less(int a, int b) { return (b - a); }

// returns the node of which value is larger than x found first,
// the tail sentinel node which is returned by end(p) otherwise.
Node* _more(List* p, int x) {
	Node* c = begin(p);
	for (; c != end(p); c = c->next)
		if (c->item > x) return c;
	return c;
}

// returns the node of which value is smaller than x found first,
// the tail sentinel node which is returned by end(p) otherwise.
Node* _less(List* p, int x) {
	Node* c = begin(p);
	for (; c != end(p); c = c->next)
		if (c->item < x) return c;
	return c;
}

// returns true if sorted either by either ascending or descending
bool sorted(List* p) {
	DPRINT(cout << ">sorted up or dn\n";);
	return sorted(p, ascending) || sorted(p, descending);
}

// returns true if sorted according to comp fp provided
bool sorted(List* p, int(*comp)(int a, int b)) {
	DPRINT(cout << ">sorted?\n";);
	if (size(p) <= 1) return true;

	for(Node* c = begin(p); c->next != end(p); c = c->next)
		if(comp(c->item, c->next->item) > 0)
			return false;

	DPRINT(cout << "<sorted: true\n";);
	return true;
}

// inserts a node with val in sorted in the "sorted" list. O(n)
void push_sorted(List* p, int val) {
	DPRINT(cout << "<push_sorted val=" << val << endl;);

	if (sorted(p, ascending))
		insert(_more(p, val), val);
	else
		insert(_less(p, val), val);

	DPRINT(cout << "<push_sorted\n";);
}

// inserts N number of nodes in sorted in the sorted list.
// If you invoke push_sort() by N times, it takes longer. Therefore,
// don't call push_sort() N timee. But if you may follow something
// like push_sort(), its time complexity will be O(n^2) or larger.
// The values for new nodes are randomly generated in the range of
// [0..(N + size(p))]. For mac users, you use rand(). For pc, use
// (rand() * RAND_MAX + rand()) instead of rand().
void push_sortedN(List* p, int N) {
	DPRINT(cout << "<push_sortedN N=" << N << endl;);

	int psize = size(p);
	int range = N + psize;

	srand((unsigned)time(NULL));	// initialize random seed

#if 1
	// O(n^2) implment your code here for O(n^2)
	// Refer to push_sorted(), but don't invoke push_sorted().
	if (sorted(p, ascending)) {
		for (int i = 0; i < N; i++){
			int val = ((long)rand() * RAND_MAX + rand()) % range;
			insert(_more(p, val), val);
		}
	}else {
		for (int i = 0; i < N; i++){
			int val = ((long)rand() * RAND_MAX + rand()) % range;
			insert(_less(p, val), val);
		}
	}

#endif

#if 0
	// O(n^3) Don't implement somethig like this, but in O(n^2).
	for (int i = 0; i < N; i++) {
		int val = (rand() * RAND_MAX + rand()) % range;
		if (sorted(p, ascending)) {
			Node* node = _more(p, val);
			insert(node, val);
		}
		else {
			Node* node = _less(p, val);
			insert(node, val);
		}
	}
#endif
	DPRINT(cout << "<push_sortedN\n";);
}

// inserts N number of nodes in sorted in the sorted list.
// The goal of this function is to make it O(n log n).
// Algorithm:
// 1. Generate N numbers to insert. Let's name this array, vals.
// 2. Sort vals using quicksort() of which time complexity
//    is O(n log n), in ascending or descending depending on
//    the list. .
// 3. Merge two lists.
//    Compare two values from the list and vals one by one.
//    For example, if sorted ascending and vals is smaller,
//    insert the vals into the list and go for the next val.
//    the list pointer does not increment.
//    If vals is larger, then the list pointer increment, but
//    vals index does not increment.
// 4. If the list is exhausted, then exit the loop. If vals
//    is not exhausted, insert the rest of vals at the end
//    of the list.
//    Make sure that you go through a loop the list and vals
//    together once. This is the same concept used in the
//    most famous "mergesort" algorithm except recursion.
// The values for new nodes are randomly generated in the range of
// [0..(N + size(p))]. For mac users, you use rand(). For pc, use
// (rand() * RAND_MAX + rand()) instead of rand().
void push_sortedNlog(List* p, int N) {
	DPRINT(cout << "<push_sortedNlog N=" << N << endl;);

	int psize = size(p);
	int range = N + psize;
	int* vals = new int[N];
	int i = 0;

	srand((unsigned)time(NULL));
	for(int j = 0; j < N; j++)
		vals[j] = ((long)rand() * RAND_MAX + rand()) % range;

	if (sorted(p, ascending)) {	// sorting이 ascending인 경우
		quickSort(vals, N, ascending);
		for(Node* c = begin(p); i < N;) {
			if(c == end(p))
				insert(c, vals[i++]);
			else if(c->item > vals[i])
				insert(c, vals[i++]);
			else
				c = c->next;
		}
	}
	else {						// sorting이 descending인 경우
		quickSort(vals, N, descending);
		for(Node* c = begin(p); i < N;) {
			if(c == end(p))
				insert(c, vals[i++]);
			else if(c->item < vals[i])
				insert(c, vals[i++]);
			else
				c = c->next;
		}
	}

	delete[] vals;
	DPRINT(cout << "<push_sortedNlog\n";);
}

// returns a list of nodes sorted in ascending order if not
// sorted by default, using bubble or selection sort algorithm
// which is O(n^2).
// If the list is already sorted, it reverses the list such that
// the ascending ordered list becomes a descending order list and
// vice versa. It is O(n).
// In the bubble sort, it checks values of two adjacent node
// whether they are in ascending order or not, if not then we
// swap the value. It does this until every element get its right
// position.  In 1st pass the largest value get its right position
// and in 2nd pass 2nd largest value get its position and in 3rd
// pass 3rd largest element get its position and so on.
void sort(List* p) {
	DPRINT(cout << ">sort N=" << size(p) << endl;);
	if (sorted(p)) return reverse(p);
	bubbleSort(p);
}

///////////////////////// show /////////////////////////////////////////////
// shows the values of all the nodes in the list if all is true or
// the list size is less than pmax * 2. If there are more than
// (pmax * 2) nodes, then it shows only pmax number of nodes from
// the beginning and the end in the list.
void show(List* p, bool all) {
	DPRINT(cout << "show(" << size(p) << ")\n";);
	if (empty(p)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int i;
	int pmax = 10;   // a magic number, max number of items per line
	Node* curr;
	const int N = size(p);

	if (all || N < pmax * 2) {
		for (i = 1, curr = begin(p); curr != end(p); curr = curr->next, i++) {
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
		if (N % pmax != 0) cout << endl;
		return;
	}

	// print the first pmax items
	for (i = 1, curr = begin(p); curr != end(p) && i <= pmax; curr = curr->next, i++)
		cout << " -> " << curr->item;

	if (N > pmax * 2)
		cout << "\n...left out..." << half(p)->item << "...left out...\n";
	else
		cout << "\n";

	// print the last pmax items
	// move the pointer to the place where pmax items are left.
	for (i = 0, curr = begin(p); i < (N - pmax); i++, curr = curr->next);
	for (i = 1; curr != end(p) && i <= pmax; curr = curr->next, i++)
		cout << " -> " << curr->item;
	cout << "\n";
}
