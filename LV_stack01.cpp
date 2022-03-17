#include <iostream>
using namespace std;

int t = 0;
class Stack {
private:
	int size = 0;
	int arr[10]{};

public:
	Stack() {
		size = 0;
	}
	bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void top() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << arr[size - 1] << endl;
		}
	}
	void push(int x) {
		if (size >= t) {
			cout << "FULL" << endl;
		}
		else {
			arr[size] = x;
			size++;
		}
	}
	void pop() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			top();
			size--;
		}
	}
};
//int main() {
//	int N;
//	string str;
//	Stack sta;
//	cin >> t >> N;
//	while (N--) {
//		cin >> str;
//		if (str == "empty") {
//			if (sta.empty() == true) {
//				cout << 1 << endl;
//			}
//			else {
//				cout << 0 << endl;
//			}
//		}
//		else if (str == "top") {
//			sta.top();
//		}
//		else if (str == "push") {
//			int x; cin >> x;
//			sta.push(x);
//		}
//		else if (str == "pop") {
//			sta.pop();
//		}
//	}
//}