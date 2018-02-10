#pragma once

//Given two linked lists, represented as linked lists(every character is a node in linked list).
//Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are same, 
//1 if first linked list is lexicographically greater, and -1 if second string is lexicographically greater.
//
//Examples:
//
//Input: list1 = g->e->e->k->s->a
//	list2 = g->e->e->k->s->b
//	Output : -1
//
//	Input : list1 = g->e->e->k->s->a
//	list2 = g->e->e->k->s
//	Output : 1
//
//	Input : list1 = g->e->e->k->s
//	list2 = g->e->e->k->s
//	Output : 0


class CompareTwoStringsRepresentedAsLinkedList {

private:
	

	struct node {
		node* next;
		char value;
		node(char _value, node* _next):
			value(_value),
			next(_next){}
	};

	typedef node* link;
	link head;


public:
	CompareTwoStringsRepresentedAsLinkedList(): head(nullptr) {};
	~CompareTwoStringsRepresentedAsLinkedList();
	void insert(char _value) { head = new node(_value, head); };
	friend int compare(const CompareTwoStringsRepresentedAsLinkedList&, const CompareTwoStringsRepresentedAsLinkedList&); 
};