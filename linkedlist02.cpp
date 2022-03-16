#include <iostream>
using namespace std;

class Node {
private:
	int elem;
	Node* next;
	Node* prev;
public:
	Node() {
		elem = 0;
		next = nullptr;
		prev = nullptr;
	}
	~Node() {
		elem = 0;
		next = nullptr;
		prev = nullptr;
	}
	friend class D_LinkedList;
};

class D_LinkedList {
public:
	D_LinkedList();
	void print();
	void append(int elem);
	void Delete(int idx);
	void print_reverse();
	void update(int X, int Y);
	int listSize();
	bool empty();
private:
	Node* header;
	Node* trailer;
};

D_LinkedList::D_LinkedList() {
	header = new Node;
	trailer = new Node;

	header = NULL;
	trailer = NULL;
}

bool D_LinkedList::empty() {
	return (header == NULL || trailer == NULL);
}

int D_LinkedList::listSize() {
	int list_size = 0;
	if (empty()) {
		return list_size;
	}
	else {
		Node* cur_node = header;
		while (cur_node->next != NULL) {
			list_size++;
			cur_node = cur_node->next;
		}
		list_size++;

		return list_size;
	}
}

void D_LinkedList::print() {
	if (empty()) {
		cout << "empty" << endl;
	}
	else {
		Node* cur_node = header;
		while (cur_node->next != NULL) {
			cout << cur_node->elem << ' ';
			cur_node = cur_node->next;
		}
		cout << cur_node->elem << endl;
	}
}

void D_LinkedList::print_reverse() {
	if (empty()) {
		cout << "empty" << endl;
	}
	else {
		Node* cur_node = trailer;
		while (cur_node->prev != NULL) {
			cout << cur_node->elem << ' ';
			cur_node = cur_node->prev;
		}
		cout << cur_node->elem << endl;
	}
}

void D_LinkedList::append(int elem) {
	Node* new_node = new Node;
	new_node->elem = elem;
	new_node->next = NULL;

	if (empty()) {
		header = new_node;
		trailer = new_node;
	}
	else {
		trailer->next = new_node;
		new_node->prev = trailer;
		trailer = new_node;
	}
	print();
}

void D_LinkedList::Delete(int idx) {
	int removeNum = 0;
	int cnt = 0;
	Node* cur_node;
	Node* pre_node;
	bool flag = true;

	if (empty() || listSize() <= idx) {
		flag = false;
		cout << -1 << endl;
	}
	else if (idx == 0) {
		if (listSize() == 1) {
			removeNum = header->elem;
			trailer = NULL;
			header = NULL;
		}
		else {
			cur_node = header;
			removeNum = cur_node->elem;
			header = cur_node->next;
			cur_node->next->prev = nullptr;
		}
	}
	else {
		pre_node = cur_node = header;
		while (cnt != idx) {
			pre_node = cur_node;
			cur_node = cur_node->next;
			cnt++;
		}
		removeNum = cur_node->elem;
		pre_node->next = cur_node->next;

		if (cur_node == trailer) {
			trailer = pre_node;
		}
		else {
			cur_node->next->prev = pre_node;
		}
	}

	if (flag) {
		cout << removeNum << endl;
	}
}

void D_LinkedList::update(int X, int Y) {
	bool flag = true;
	int cnt = 0;
	if (empty()) {
		flag = false;
		cout << "empty" << endl;
	}
	else {
		Node* cur_node = header;
		while (cur_node->next != NULL) {
			if (cur_node->elem == X) {
				flag = true;
				cur_node->elem = Y; cnt++;
			}
			cur_node = cur_node->next;
		}
		if (cur_node->elem == X) {
			flag = true;
			cur_node->elem = Y; cnt++;
		} 
	}

	if (cnt == 0) {
		flag = false;
		cout << "Not found" << endl;
	}
	if (flag) {
		print();
	}
}

int main() {
	int M = 0;
	string str;
	cin >> M;
	D_LinkedList dll;

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "Print") {
			dll.print();
		}
		else if (str == "Append") {
			int X; cin >> X;
			dll.append(X);
		}
		else if (str == "Delete") {
			int X; cin >> X;
			dll.Delete(X);
		}
		else if (str == "Print_reverse") {
			dll.print_reverse();
		}
		else if (str == "Update") {
			int X; int Y; cin >> X >> Y;
			dll.update(X, Y);
		}
	}
}