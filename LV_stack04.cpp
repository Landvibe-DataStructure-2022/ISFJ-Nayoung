#include <iostream>
#include <string>
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

	int top() {
		if (empty()) {
			return -1;
		}
		else {
			Node* cur_node = head;
			//cout << cur_node->elem << endl;
			return cur_node->elem;
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
			return;
		}
		else {
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

	void Size() {
		cout << size << endl;
	}

	void Operator() {
		string str;
		cin >> str;
		int A = 0, B = 0, res = 0;
		int s_size = str.size();

		for (int i = 0; i < s_size; i++) {
			if (str[i] - '0' > 0 && str[i] - '0' < 10) { // ÇÇ¿¬»êÀÚ
				push(str[i] - '0');
			}
			else if (str[i] == '+' || str[i] == '-' || str[i] == '*') { // ¿¬»êÀÚ
				B = top(); pop();
				A = top(); pop();
				if (str[i] == '+')
					res = A + B;
				else if (str[i] == '-')
					res = A - B;
				else if (str[i] == '*')
					res = A * B;
				push(res);
			}
		}
		cout << top() << endl;
		pop();
	}

private:
	Node* head;
	Node* tail;
	int size = 0;
};

int main() {
	int t;
	string str;
	Stack sta;
	cin >> t;
	while (t--) {
		sta.Operator();
	}
}
