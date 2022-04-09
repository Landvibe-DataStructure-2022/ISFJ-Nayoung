#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
	int data;
	int depth;
	Node* parent_node;
	vector<Node*> children_v;

	Node() {
		parent_node = NULL;
		data = 0;
		depth = 0;
	}
	Node(int data) {
		this->data = data;
		this->parent_node = NULL;
		depth = 0;
	}
	Node(Node* p, int data) {
		parent_node = p;
		this->data = data;
		depth = 0;
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
		root->depth = 0;
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
		//Node* tempNode = findNode(data);

		if (parNode == NULL) {
			cout << "-1\n";
		}
		else {
			Node* newNode = new Node(parNode, data);
			parNode->children_v.push_back(newNode);
			node_v.push_back(newNode);
			newNode->depth = newNode->parent_node->depth + 1;
		}
	}

	void printDepth(int data) {
		Node* curNode = findNode(data);

		if (curNode == NULL) {
			cout << "-1\n";
		}
		else {
			cout << curNode->depth + 1 << "\n";
		}
	}

};

int main() {
	int M, v; cin >> M >> v;
	Tree tree;

	while (M--) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
	}
	while (v--) {
		int x; cin >> x;
		tree.printDepth(x);
	}
}

