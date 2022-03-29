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
	friend class Queue;
};

class Queue {
public:
	bool isEmpty() {
		return (head == NULL || tail == NULL);
	}
	void enqueue(int value) {
		Node* new_node = new Node;
		new_node->elem = value;
		new_node->next = NULL;

		if (isEmpty()) {
			head = new_node;
			tail = new_node;
			size++;
		}
		else {
			tail->next = new_node;
			tail = new_node;
			size++;
		}
	}
	void dequeue() {
		if (isEmpty()) {
			cout << "Empty\n";
		}
		else {
			Node* delete_node = head;
			cout << head->elem << endl;

			if (size == 1) {
				tail = NULL;
				head = NULL;
			}
			else {
				head = delete_node->next;
			}
			size--;
		}
	}
	void Size() {
		cout << size << endl;
	}
	void front() {
		if (isEmpty()) {
			cout << "Empty\n";
		}
		else {
			cout << head->elem << endl;
		}
	}
	void rear() {
		if (isEmpty()) {
			cout << "Empty\n";
		}
		else {
			cout << tail->elem << endl;
		}
	}

private:
	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;
};

int main() {
	int T; string str;
	Queue que;
	cin >> T;
	while (T--) {
		cin >> str;
		if (str == "enqueue") {
			int val;
			cin >> val;
			que.enqueue(val);
		}
		else if (str == "dequeue") {
			que.dequeue();
		}
		else if (str == "size") {
			que.Size();
		}
		else if (str == "isEmpty") {
			if (que.isEmpty() == true) {
				cout << "True\n";
			}
			else {
				cout << "False\n";
			}
		}
		else if (str == "front") {
			que.front();
		}
		else if (str == "rear") {
			que.rear();
		}
	}
}