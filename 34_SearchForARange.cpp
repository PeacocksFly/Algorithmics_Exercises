#include "34_SearchForARange.h"

//constructor
SearchForARange::SearchForARange(const std::vector<int>& _vecInput, int _target):
	vecInput(_vecInput), target(_target){}


//binary search function
int SearchForARange::binarySearch(int l, int r) {
	if (l > r) return -1;
	int  m = (l + r) / 2;
	if (vecInput[m] == target)  return m;
	if (l == r) return -1;
	if (target > vecInput[m])
		return binarySearch(m + 1, r);
	else
		return binarySearch(l, m - 1);
}

//main range search function
std::vector<int> SearchForARange::rangeSearch() {

	int l = 0;
	int r = vecInput.size() - 1;

	int pos = binarySearch(l, r);
	if (pos == -1) {
		return std::vector<int> {-1, -1};
	}
	else {
		int posTemp = pos;
		std::vector<int> result;
		int* rangeBegin = &vecInput[pos];
		int* rangeEnd = rangeBegin;

		while ((pos < r) && vecInput[++pos] == target) { rangeEnd++; }
		while ((posTemp > l) && vecInput[--posTemp] == target) { rangeBegin--; }

		std::back_insert_iterator< std::vector<int> > back_it(result);
		std::copy(rangeBegin, ++rangeEnd, back_it);
		return result;
	}

}