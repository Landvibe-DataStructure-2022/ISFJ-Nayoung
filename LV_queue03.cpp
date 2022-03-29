#include <iostream>
using namespace std;

class Queue {
public:
	Queue(int size) {
		this->size = size + 1;
		Q = new int[this->size];
		frontIndex = rearIndex = 0;

		for (int i = 0; i < size; i++) {
			Q[i] = 0;
		}
	}
	
	bool isFull() {
		return (frontIndex == (rearIndex + 1) % size);
	}

	bool isEmpty() {
		return (frontIndex == rearIndex);
	}

	void enqueue(int value) {
		if (isFull()) {
			cout << "Full" << endl;
		}
		else {
			rearIndex = (rearIndex + 1) % size;
			Q[rearIndex] = value;
		}
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			frontIndex = (frontIndex + 1) % size;
			cout << Q[frontIndex] << endl;
			Q[frontIndex] = 0;
		}
	}

	void front() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << Q[(frontIndex + 1) % size] << endl;
		}
	}

	void rear() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << Q[rearIndex] << endl;
		}
	}

	int Size() {
		return (rearIndex - frontIndex + size) % size;
	}

private:
	int* Q;
	int rearIndex;
	int frontIndex;
	int size;
};

int main() {
	int N, T;
	string str;
	cin >> N >> T;

	Queue que(N);
	while (T--) {
		cin >> str;
		if (str == "isEmpty") {
			if (que.isEmpty() == true) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (str == "size") {
			cout << que.Size() << endl;
		}
		else if (str == "front") {
			que.front();
		}
		else if (str == "rear") {
			que.rear();
		}
		else if (str == "enqueue") {
			int X; cin >> X;
			que.enqueue(X);
		}
		else if (str == "dequeue") {
			que.dequeue();
		}
	}
}