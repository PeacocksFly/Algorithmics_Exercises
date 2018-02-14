#pragma once

#include <iostream>
//Sort the given Linked List using quicksort.which takes O(n ^ 2) 
//time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

class QuicksortOnDoublyLinkedList {

private:
	struct node {
		node* next;
		node* prev;
		int value;
		node(int _value, node* _next, node* _prev) :
			value(_value),
			next(_next),
		    prev(_prev){}
	};

	typedef node* link;
	link head;
	link tail;
	void sortR(link, link);
	


public:
	QuicksortOnDoublyLinkedList() : head(nullptr), tail(head) {};
	~QuicksortOnDoublyLinkedList();
	void insert(int _value);
	void swap(link, link);
	void sort() { sortR(head, tail); };
	
	friend std::ostream& operator<<(std::ostream&, const QuicksortOnDoublyLinkedList&);

};
