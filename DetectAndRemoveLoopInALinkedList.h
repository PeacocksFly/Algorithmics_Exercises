#pragma once

//Write a function detectAndRemoveLoop() that checks whether a given Linked List contains loop 
//and if loop is present then removes the loop and returns true.And if the list doesn’t contain 
//loop then returns false.Below diagram shows a linked list with a loop.detectAndRemoveLoop() 
//must change the below list to 1->2->3->4->5->NULL.

#include <vector>
#include <algorithm>
#include <iostream>

class DetectAndRemoveLoopInALinkedList {

private:
	struct node {
		node* next;
		int value;
		node(int _value, node* _next) :
			value(_value),
			next(_next) {}
	};

	typedef node* link;
	link head;
	void detectAndRemoveLoopR(link);


public:
	DetectAndRemoveLoopInALinkedList();
	~DetectAndRemoveLoopInALinkedList();
	void insert(int _value) { head = new node(_value, head); };
	void detectAndRemoveLoop() { detectAndRemoveLoopR(head); };
	friend std::ostream& operator<<(std::ostream&, const DetectAndRemoveLoopInALinkedList&);
};
