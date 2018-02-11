#include "ReverseAlternateLevelsOfAPerfectBinaryTree.h"


ReverseAlternateLevelsOfAPerfectBinaryTree::ReverseAlternateLevelsOfAPerfectBinaryTree() {

	head = new node('a');

	head->l = new node('b');
	head->r = new node('c');

	head->l->l = new node('d');
	head->l->r = new node('e');
	head->r->l = new node('f');
	head->r->r = new node('g');

	head->l->l->l = new node('h');
	head->l->l->r = new node('i');
	head->l->r->l = new node('j');
	head->l->r->r = new node('k');
	head->r->l->l = new node('l');
	head->r->l->r = new node('m');
	head->r->r->l = new node('n');
	head->r->r->r = new node('o');

}


ReverseAlternateLevelsOfAPerfectBinaryTree::~ReverseAlternateLevelsOfAPerfectBinaryTree() {

	link t = head;
	link g = nullptr;

	while (t != nullptr) {
		g = t;
		t = t->l;
		delete g;
	}
}


void ReverseAlternateLevelsOfAPerfectBinaryTree::swapR(std::deque<link>::iterator it_begin, std::deque<link>::reverse_iterator it_rbegin) {

	char temp = (*it_begin)->letter;
	(*it_begin)->letter = (*it_rbegin)->letter;
	(*it_rbegin)->letter = temp;
}


void ReverseAlternateLevelsOfAPerfectBinaryTree::reverseR(link h) {

	if (h == nullptr) return;

	int binaryCounter = 0;
	int floor = 1;
	std::deque<link> deque;
	deque.push_back(h);

	while (!deque.empty()) {

		if (deque.front()->l != nullptr) deque.push_back(deque.front()->l);
		if (deque.front()->r != nullptr) deque.push_back(deque.front()->r);
		deque.pop_front();
		binaryCounter = binaryCounter + 2;

		if ((binaryCounter == pow(2, floor)) && (floor % 2 == 1)) {
			std::deque<link>::iterator it_begin = deque.begin();
			std::deque<link>::reverse_iterator it_rbegin = deque.rbegin();
			int swapCount = binaryCounter / 2;
			while (swapCount-- != 0) {
				swapR(it_begin++, it_rbegin++);
			}
		}

		if (binaryCounter == pow(2, floor)) {
			binaryCounter = 0;
			floor++;
		}
	}
}
