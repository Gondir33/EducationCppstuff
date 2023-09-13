#include <iostream>

struct Node {
	int value;
	Node*	right;
	Node*	left;

	Node() : value(0), right(nullptr), left(nullptr) {};
	Node(int value) : value (value), right(nullptr), left(nullptr) {};
};


void	print_tree(Node* root) {
	if (root == nullptr)	return ;
	print_tree(root->left);
	std::cout << root->value << '\n';
	print_tree(root->right);
}

void	retHeigh_addNode(Node* root, Node* newNode) {
	Node*	prevNode;
	while (root) {
		prevNode = root;
		if (root->value < newNode->value) {
			root = root->right;
		} else if (root->value > newNode->value) {
			root = root->left;
		} else {
			return ;
		}
	}
	if (prevNode->value < newNode->value)
		prevNode->right = newNode;
	else
		prevNode->left = newNode;
}

/*
int countHeight(Node* root) {
	int hl, hr;
	if (!root)
		return 0;
	hl = countHeight(root->left);
	hr = countHeight(root->right);
	return  hr > hl ? ++hr : ++hl;
}


int get_sec_max(Node* root) {
	Node* prevNode = root;
	if (root->right == nullptr) {
		if (root->left) {
			root = root->left;
			while (root->right != nullptr) {
				root = root->right;
			}
			return root->value;
		}
	}
	while (root->right != nullptr) {
		prevNode = root;
		root = root->right;
	}
	if (root->left) {
		root = root->left;
		while (root->right) {
			root = root->right;
		}
		return root->value;
	}
	return prevNode->value;
}
*/
int main( ) {
	int	tmp;
	std::cin >> tmp;
	if (tmp == 0)
		return 0;
	Node*	root = new Node(tmp);
	std::cin >> tmp;

	while (tmp) {
		retHeigh_addNode(root, new Node(tmp));
		std::cin >> tmp;
	}
	print_tree(root);
}