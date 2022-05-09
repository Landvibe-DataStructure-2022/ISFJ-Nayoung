#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum direction { MIN = 1, MAX = -1 };

class Heap {
private:
	vector<int> v;
	int heapSize;
	int rootIndex;
	int direction;

public:
	Heap(int direction) {
		v.push_back(-1);
		this->heapSize = 0;
		this->rootIndex = 1;
		this->direction = direction;
	}

	void swap(int idx1, int idx2) {
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}

	void upHeap(int idx) {
		if (idx == rootIndex) return;
		else {
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction) {
				swap(parent, idx);
				upHeap(parent);
			}
		}
	}

	void downHeap(int idx) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		if (right <= heapSize) {
			if (v[left] * direction <= v[right] * direction) {
				if (v[left] * direction < v[idx] * direction) {
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else {
				if (v[right] * direction < v[idx] * direction) {
					swap(right, idx);
					downHeap(right);
				}
				else return;
			}
		}
		else if (left <= heapSize) {
			if (v[left] * direction < v[idx] * direction) {
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else return;
	}

	void insert(int e) {
		v.push_back(e);
		heapSize++;
		upHeap(heapSize);
	}

	void pop() {
		if (isEmpty()) {
			return;
		}
		else {
			int top = v[rootIndex];
			v[rootIndex] = v[heapSize]; heapSize--;
			v.pop_back();
			downHeap(rootIndex);
		}
	}

	int top() { return v[rootIndex]; }
	int size() { return heapSize; }
	bool isEmpty() { return heapSize == 0; }

	void print() {
		if (isEmpty()) {
			cout << -1 << endl;
		}
		else {
			for (int i = 1; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << endl;
		}
	}

	bool operation(int e) {
		bool flag = false;
		if (isEmpty()) {
			return false;
		}
		else {
			for (int i = 1; i < v.size(); i++) {
				if (v[i] <= e) {
					flag = true;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag)
				return true;
			else
				return false;
		}
	}
};

int main() {
	int T; cin >> T;
	while (T--) {
		Heap heapPQ(MAX);
		int N, P; cin >> N >> P;
		for (int i = 0; i < N; i++) {
			int num; cin >> num;
			heapPQ.insert(num);
		}
		int count = 0;
		while (1) {
			if (heapPQ.operation(P)) {
				break;
			}
			else if (heapPQ.size() <= 2 && heapPQ.operation(P) == false) {
				break;
			}

			int num1 = 0, num2 = 0, num3 = 0, newnum = 0;
			num1 = heapPQ.top(); heapPQ.pop();
			num2 = heapPQ.top(); heapPQ.pop();
			num3 = heapPQ.top(); heapPQ.pop();

			newnum = (num1 + num3) / 2;
			heapPQ.insert(newnum);
			count++;
		}

		if (heapPQ.operation(P)) {
			cout << count << endl;
			heapPQ.print();
		}
		else if (heapPQ.size() <= 2 && heapPQ.operation(P) == false) {
			cout << "False" << endl;
		}
	}
}