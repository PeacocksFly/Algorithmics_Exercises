#pragma once

//Given two Linked Lists, create union and intersection lists that contain union and 
//intersection of the elements present in the given lists.Order of elments in output lists doesn’t matter.
//
//Example:
//
//Input:
//List1: 10->15->4->20
//	lsit2 : 8->4->2->10
//	Output :
//	Intersection List : 4->10
//	Union List : 2->8->20->4->15->10

#include <vector>
#include <iostream>


class UnionAndIntersectionOfTwoLinkedLists {

private:
	struct node {
		node* next;
		int value;
		node(int _value, node* _next) :
			value(_value),
			next(_next) {}
	};

	typedef node* link;
	link _head;
	void unionAndIntersectionP(link&, link&);

public:
	UnionAndIntersectionOfTwoLinkedLists();
	~UnionAndIntersectionOfTwoLinkedLists();
	void insert(int value) { _head = new node(value, _head); };
	void unionAndIntersection(UnionAndIntersectionOfTwoLinkedLists& a) { unionAndIntersectionP(this->_head, a._head); }
	friend std::ostream& operator<<(std::ostream&, const UnionAndIntersectionOfTwoLinkedLists&);
};

