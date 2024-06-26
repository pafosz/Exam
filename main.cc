#include <iostream>
#include <optional>
#include "src/search.cc"
#include "src/list.cc"
#include "src/stack.cc"
#include "src/queue.cc"
#include "src/sort.cc"
#include "src/tree.cc"
using namespace std;

void print_vector(const vector<int>& vec) {
	for (auto v : vec) {
		cout << v << " ";
	}
	cout << "\n";
}

int main() {

	/*CyclicList<int> clst;
	clst.push_back(1);
	clst.push_back(2);
	clst.push_back(3);
	clst.push_back(4);
	clst.push_back(5);
	clst.print();
	clst.pop_back();
	clst.print();*/

	/*DoublyLinkedList<int> lst;

	lst.push_back(4);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(6);
	lst.push_back(12);
	lst.push_back(9);
	lst.print();
	lst = lst.includeSort();
	lst.print();*/

	/*vector<int> arr{ 4,3,5,1,2,6,12,9 };
	vector<int> arr1{ 9,8,7,6,5,4,3,2,1 };
	cout << arr1.size() - 1 << endl;
	print_vector(arr1);
	quickSort(arr1);
	print_vector(arr1);*/

	SearchTree<int> t;
	t.add(30);
	t.add(50);
	t.add(15);
	t.add(12);
	t.add(16);
	t.add(80);
	t.add(74);
	t.add(50);
	t.print();
	cout << t.contains(50);
	t.erase(30);
	t.print();
	

	return 0;

}