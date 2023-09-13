#include <iostream>
#include <map>

struct NonBinaryNode {
	std::string value;
	NonBinaryNode*	rightNeighbor;
	NonBinaryNode*	left;

	NonBinaryNode() : value(0), rightNeighbor(nullptr), left(nullptr) {};
	NonBinaryNode(std::string value) : value (value), rightNeighbor(nullptr), left(nullptr) {};
};

bool	addNode(NonBinaryNode* root, std::string& parent, NonBinaryNode* child) {

	if (!root)
		return false;
	if (root->value == parent) {
		if (!root->left) {
			root->left = child;
		} else {
			root = root->left;
			while (root->rightNeighbor)
				root = root->rightNeighbor;
			root->rightNeighbor = child;
		}
		return true;
	}
	bool f1 = addNode(root->left, parent, child);
	bool f2 = addNode(root->rightNeighbor, parent, child);
	if (f1 || f2)
		return true;
	else
		return false;
}


int	countHeigh(NonBinaryNode* root) {
	if (!root)
		return 0;
	int l = countHeigh(root->left);
	int r = countHeigh(root->rightNeighbor);
	return l > r ? ++l + r : ++r + l;
}


void	countAns(NonBinaryNode* root, std::map<std::string, int>&	ans) {
	if (!root)
		return ;
	countAns(root->left, ans);
	countAns(root->rightNeighbor, ans);
	ans.insert(std::make_pair(root->value, countHeigh(root->left)));
}


int main( ) {
	int N;
	std::cin >> N;
	std::string	parent, child;
	std::cin >> child >> parent;
	std::map<std::string, int>	ans;
	NonBinaryNode	*root = new NonBinaryNode(parent), *childN, *tmp;
	addNode(root, parent, new NonBinaryNode(child));

	for (int i = 2; i < N; ++i) {
		std::cin >> child >> parent;
		childN = new NonBinaryNode(child);
		if (addNode(root, parent, childN) == false)	{
			tmp = root;
			while (tmp->rightNeighbor)
				tmp = tmp->rightNeighbor;
			tmp->rightNeighbor = new NonBinaryNode(parent);
			tmp = tmp->rightNeighbor;
			addNode(root, parent, childN);
		}
	}
	countAns(root, ans);
	std::cout << "\n\n\n\n\n";
	for (auto& it : ans)
		std::cout << it.first << ' ' << it.second << '\n';
}