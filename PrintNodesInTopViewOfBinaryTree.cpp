#include "PrintNodesInTopViewOfBinaryTree.h"


PrintNodesInTopViewOfBinaryTree::PrintNodesInTopViewOfBinaryTree() {

	head = new node(1);
	head->l = new node(2);
	head->r = new node(3);
	head->l->r = new node(4);
	head->l->r->r = new node(5);
	head->l->r->r->r = new node(6);

}


PrintNodesInTopViewOfBinaryTree::~PrintNodesInTopViewOfBinaryTree() {

	clearTreeR(head);
}

void PrintNodesInTopViewOfBinaryTree::clearTreeR(link h) {

	if (h == nullptr) return;
	link l = nullptr, r = nullptr;
	if (h->l != nullptr) l = h->l;
	if (h->r != nullptr) r = h->r;
	delete h;
	clearTreeR(l);
	clearTreeR(r);
}


void PrintNodesInTopViewOfBinaryTree::printR(link h) {

	if (h == nullptr) return;

	std::queue<std::pair<link, int>> queue;
	queue.push(std::make_pair(h,0));

	int min = 0;
	int max = 0;
	std::cout << queue.front().first->val << "   ";
	while (!queue.empty()) {
		if (queue.front().first->l != nullptr) {
			queue.push(std::make_pair(queue.front().first->l, queue.front().second -1));
		}
		if (queue.front().first->r != nullptr) {
			queue.push(std::make_pair(queue.front().first->r, queue.front().second + 1));
		}

		if (queue.front().second < 0 && queue.front().second < min) {
			std::cout << queue.front().first->val << "   ";
			min = queue.front().second;
		}

		if (queue.front().second > 0 && queue.front().second > max) {
			std::cout << queue.front().first->val << "   ";
			max = queue.front().second;
		}
		      
		queue.pop();
	}
	
}