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
	if ((root->left && root->right == nullptr) || (root->right && root->left == nullptr))
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

int countHeight(Node* root) {
	int hl, hr;
	if (!root)
		return 0;
	hl = countHeight(root->left);
	hr = countHeight(root->right);
	return  hr > hl ? ++hr : ++hl;
}

bool checkAVL(Node* root) {

	if (!root)
		return true;
		if (checkAVL(root->left) == false)
			return false;
		if (checkAVL(root->right) == false)
			return false;
	int l = countHeight(root->left), r = countHeight(root->right);

	if (std::abs(l - r) <= 1)
		return true;
	else
		return false;
}


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
	int l = countHeight(root->left), r = countHeight(root->right);
	if (checkAVL(root))
		std::cout << "YES";
	else
		std::cout << "NO";
}