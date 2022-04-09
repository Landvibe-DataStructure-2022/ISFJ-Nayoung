#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* parent_node;
	vector<Node*> children_v;

	Node() {
		parent_node = NULL;
		data = 0;
	}
	Node(int data) {
		this->data = data;
		this->parent_node = NULL;
	}
	Node(Node* p, int data) {
		parent_node = p;
		this->data = data;
	}

	friend class Tree;
};

class Tree {
public:
	Node* root;
	vector<Node*> node_v;

	Tree() {
		root = new Node(1);
		node_v.push_back(root);
	}

	Node* findNode(int data) {
		for (int i = 0; i < node_v.size(); i++) {
			if (node_v[i]->data == data) {
				return node_v[i];
			}
		}
		return NULL;
	}

	void insertNode(int par_data, int data) {
		Node* parNode = findNode(par_data);
		Node* tempNode = findNode(data);

		if (parNode == NULL || tempNode != NULL) {
			cout << "-1\n";
		}
		else {
			Node* newNode = new Node(parNode, data);
			parNode->children_v.push_back(newNode);
			node_v.push_back(newNode);
		}
	}

	void deleteNode(int data) {
		Node* deleteNode = findNode(data);

		if (deleteNode == NULL || deleteNode == root) {
			cout << "-1\n";
		}
		else {
			Node* parentNode = deleteNode->parent_node; // 삭제할 노드의 부모노드

			for (int i = 0; i < deleteNode->children_v.size(); i++) { // 부모노드와 삭제노드의 자식 연결
				parentNode->children_v.push_back(deleteNode->children_v[i]);
				deleteNode->children_v[i]->parent_node = parentNode;
			}

			for (int i = 0; i < parentNode->children_v.size(); i++) {
				if (parentNode->children_v[i] == deleteNode) {
					parentNode->children_v.erase(parentNode->children_v.begin() + i);
					break;
				}
			}

			for (int i = 0; i < node_v.size(); i++) {
				if (node_v[i] == deleteNode) {
					node_v.erase(node_v.begin() + i);
					break;
				}
			}

			delete deleteNode;
		}
	}

	void printChild(int data) {
		Node* curNode = findNode(data);

		if (curNode == NULL || curNode->children_v.empty()) {
			cout << "-1\n";
		}
		else {
			for (int i = 0; i < curNode->children_v.size(); i++) {
				cout << curNode->children_v[i]->data << " ";
			}
			cout << endl;
		}
	}

};

int main() {
	int T; cin >> T;
	Tree t;

	while (T--) {
		string str;
		cin >> str;
		if (str == "insert") {
			int x, y; cin >> x >> y;
			t.insertNode(x, y);
		}

		if (str == "delete") {
			int x; cin >> x;
			t.deleteNode(x);
		}


		if (str == "print") {
			int x; cin >> x;
			t.printChild(x);
		}
	}
}

