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
			return;
		}
		else {
			Node* delete_node = head;

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

	int front() {
		if (isEmpty()) {
			return -1;
		}
		return head->elem;
	}
private:
	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;
};

int main() { // Linked-list based Queue
	int T;
	cin >> T;

	while (T--) {
		int N = 0; cin >> N;

		Queue Q01;
		Queue Q02;
		int Q01point = 0;
		int Q02point = 0;
		int point1 = 0;
		int point2 = 0;
		string winner;

		for (int i = 0; i < N; i++) {
			int num = 0;
			cin >> num;
			Q01.enqueue(num);
		}
		for (int i = 0; i < N; i++) {
			int num = 0;
			cin >> num;
			Q02.enqueue(num);
		}

		for (int i = 0; i < N; i++) {
			int que01 = Q01.front() + point1;
			int que02 = Q02.front() + point2;

			if (que01 > que02) {
				Q01point++;
				point1 = 0;
				point2 = que01 - que02;
			}
			else if (que01 < que02) {
				Q02point++;
				point1 = que02 - que01;
				point2 = 0;
			}
			else {
				point1 = 0;
				point2 = 0;
			}

			Q01.dequeue(); Q02.dequeue();
		}

		if (Q01point > Q02point) {
			cout << Q01point << endl;
		}
		else if (Q01point <= Q02point) {
			cout << Q02point << endl;
		}
	}
}