// 03분반 21800179 김준현
/*
On my honour, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
Signed: 김준현 Section:  03분반 Student  Number: 21800179
*/

#include <iomanip>
#include "listnode.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
Node* clear(Node* p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	Node* curr = p;
	while (curr != nullptr) {
		Node* prev = curr;
		curr = curr->next;
		cout << prev->item << " ";
		delete prev;
		//cout << prev->item << " ";
	}
	cout << "\tcleard \tHappy Coding~~\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(Node* p) {
	if (empty(p)) return 0;
	int count = 0;
	for (Node* c = p; c != nullptr; c = c->next, count++);
	return count;
}

// returns the last node of in the list.
Node* last(Node* p) {
	if (empty(p)) return nullptr;
	while (p->next != nullptr) p = p->next;
	return p;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(Node* p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by one.
Node* push_front(Node* p, int val) {
	DPRINT(cout << "><push_front val=" << val << endl;);

	Node* newNode = new Node(val, p);
	p = newNode;

	return p;
}

// adds a new node with val at the end of the list and returns the
// first node of the list. This effectively increases the list size by one.
Node* push_back(Node* p, int val) {
	DPRINT(cout << "><push_back val=" << val << endl;);
	Node* newNode = new Node(val);

	Node* cur = p;
	if(cur == nullptr) return newNode;	// 아무것도 없는 경우

	cur = last(cur);
	cur->next = newNode;

	return p;
}

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
Node* push(Node* p, int val, int x) {
	if (empty(p)) return push_front(p, val);
	if (p->item == x) return push_front(p, val);

	Node* curr = p;
	Node* prev = nullptr;
	// 원하는 위치 찾기
	while(curr->next != nullptr && curr->next->item != x)
		curr = curr->next;

	if(curr->next == nullptr) return p; // 찾지 못한 경우

	//찾은 경우
	prev = curr;
	curr = curr->next;
	Node* newNode = new Node(val, curr);
	prev->next = newNode;

	return p;
}

// adds N number of new nodes at the end of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
// Since it simply calls push_back() repeatedly, it is O(N^2).
Node* push_backN(Node* p, int N) {
	DPRINT(cout << "<push_backN N=" << size(p) << endl;);

	int range = N + size(p);
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++) {
		int val = rand() % range;
		p = push_back(p, val);
		cout << setw(7) << "\r\tinserting in [" << i << "]=" << val;
	}
	cout << "\n";

	DPRINT(cout << "<push_backN size=" << size(p) << endl;);
	return p;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by one.
Node* pop_front(Node* p) {
	DPRINT(cout << ">pop_front size=" << size(p) << endl;);
	if(empty(p)) return nullptr;

	Node* temp = p; // delete하기 위한 임시저장
	p = p->next;

	delete(temp);
	return p;
}

// removes the last node in the list, effectively reducing the
// container size by one. This destroys the removed node.
Node* pop_back(Node* p) {
	DPRINT(cout << ">pop_back size=" << size(p) << endl;);
	if (empty(p)) return nullptr;
	Node* curr = p;
	Node* prev;
	//끝 위치와 끝에서 두번째 위치 찾기
	while(curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}
	// 두번째를 마지막으로
	prev->next = nullptr;
	delete(curr);
	//cout << curr->item << endl;

	DPRINT(cout << "<pop_back size=" << size(p) << endl;);
	return p;
}

// deletes N number of nodes, starting from the end.
// It deletes all the nodes if N is zero which is the default or out of
// the range of the list.
// Since it simply calls pop_back() which is O(n) repeatedly, it is O(N^2).
Node* pop_backN(Node* p, int N) {
	DPRINT(cout << ">pop_backN N=" << N << endl;);
	int Size = size(p);

	if(Size < N) clear(p);	// link size보다 N이 더 크면 모두 삭제
	else{
		Node* curr = p;
		Node* temp;
		// 삭제할 노드 위치로 이동하기.
		for(int i = 1; i < Size - N; i++)
			curr = curr->next;

		temp = curr;		// 나중에 nullptr 처리하기 위한 임시 포인터
		curr = curr->next;
		// 모두 삭제
		while (curr != nullptr) {
			Node* prev = curr;
			curr = curr->next;
			// cout << prev->item << " ";
			delete prev;
		}
		// 남은 link 마지막 nullptr처리
		temp->next = nullptr;
	}


	DPRINT(cout << "<pop_backN size=" << size(p) << endl);
	return p;
}

// removes the first occurrence of the node with val from the list
Node* pop(Node* p, int val) {
	DPRINT(cout << ">pop val=" << val << endl;);
	if (empty(p)) return nullptr;    // nothing to delete
	if (p->item == val) return pop_front(p);
	// 팝할 위치찾기
	Node* curr = p;
	while(curr->next != nullptr && curr->next->item != val)
		curr = curr->next;
	// 삭제
	if(curr->next->item == val) {
		Node* temp = curr->next;
		curr->next = temp->next;
		delete(temp);
	}

	DPRINT(cout << "<pop size=" << size(p) << endl;);
	return p;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than pmax * 2. If there are more than
// (pmax * 2) nodes, then it shows only pmax number of nodes from
// the beginning and the end in the list.
void show(Node* p, bool all) {
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
		for (i = 1, curr = p; curr != nullptr; curr = curr->next, i++) {
			cout << " -> " << curr->item;
			if (i % pmax == 0) cout << endl;
		}
		return;
	}

	// print the first pmax items
	curr = p;
	for(int i = 1; i <= pmax; i++, curr = curr->next)
		cout << " -> " << curr->item;
	cout << endl;

	cout << "\n...left out...\n";
	// print the last pmax items
	// move the pointer to the place where pmax items are left.
	curr = p;
	for(int i = 1; i <= N - pmax; i++)
		curr = curr->next;

	for(int i = 1; i <= pmax; i++, curr = curr->next)
		cout << " -> " << curr->item;
	cout << endl;

	cout << "\n";
}
