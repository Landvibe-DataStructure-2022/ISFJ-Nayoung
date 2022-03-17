#include <iostream>
using namespace std;

class Node {
private:
	int elem;
	Node* next;
public:
	Node() {
		elem = 0;
		next = nullptr;
	}
	~Node() {
		elem = 0;
		next = nullptr;
	}
	friend class Stack;
};

class Stack {
public:
	bool empty() {
		return (head == NULL || tail == NULL);
	}

	void top() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			Node* cur_node = head;
			cout << cur_node->elem << endl;
		}
	}

	void push(int x) {
		Node* new_node = new Node;
		new_node->elem = x;

		if (empty()) {
			head = new_node;
			tail = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
		size++;
	}

	void pop() {
		Node* cur_node;
		
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			top();
			if (size == 1) {
				tail = NULL;
				head = NULL;
			}
			else {
				cur_node = head;
				head = cur_node->next;
			}
			size--;
		}

	}
	
private:
	Node* head;
	Node* tail;
	int size = 0;
};

int main() {
	int N;
	string str;
	Stack sta;
	cin >> N;
	while (N--) {
		cin >> str;
		if (str == "empty") {
			if (sta.empty() == true) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (str == "top") {
			sta.top();
		}
		else if (str == "push") {
			int x; cin >> x;
			sta.push(x);
		}
		else if (str == "pop") {
			sta.pop();
		}
	}
}