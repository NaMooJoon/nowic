//  listnode.h
//  Created by idebtor@gmail.com on December 12, 2018.
//  This header file contains a simple linked list of nodes.

#ifndef LISTNODE_H
#define LISTNODE_H

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#include <iostream>
#include <string>

using namespace std;

// Node structs contain data and a pointer to the next node.
struct Node {
	int		item;
	Node*	next;
	// constructor instantiates a node with default arguments
	Node(const int i = 0, Node* n = nullptr) {
		item = i, next = n;
	}
	~Node() {}
};
//using pNode = Node*;

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
Node* clear(Node* p);	// free linked nodes and returns nullptr

Node* last(Node* p);	// returns the last node
bool empty(Node* p);	// true if empty, otherwise false
int size(Node* p);		// returns size in the list

// inserts a new node with val at the beginning of the list and
// returns the new first node.
// This effectively increases the list size by one.
Node* push_front(Node* p, int x);

// inserts a new node with val at the end of the list and
// returns the first node.
// This effectively increases the container size by one.
Node* push_back(Node* p, int x);

// inserts a new node with val at the position of the node with x.
// The new node is actually inserted in front of the node with x.
// It returns the first node of the list.
// This effectively increases the container size by one.
Node* push(Node* p, int val, int x);

// adds N number of new nodes at the end of the list, O(n)
// Values of new nodes are randomly generated in the range of
// [0..(N + size(p))].
// Since it simply calls push_back() repeatedly, it is O(N^2).
Node* push_backN(Node* p, int N);

Node* pop_front(Node* p);			// deletes the first node in the list
Node* pop_back(Node* p);			// deletes the last node in the list, O(n)
Node* pop(Node* p, int val);	    // deletes the node with the val
Node* pop_backN(Node* p, int N = 0);// deletes N nodes from the end, O(N^2)
                                    // deletes all nodes by default (N = 0)

void show(Node* p, bool all = true);// shows values of nodes in list
#endif
