Node* lca(Node* root , int n1 , int n2 ) {
	if (root == nullptr) return nullptr;

	if (root->data == n1 || root->data == n2) return root;

	Node* leftans = lca(root->left, n1, n2);
	Node* rightans = lca(root->right, n1, n2);
	if (leftans != nullptr && rightans != nullptr)
		return root;
	else if (leftans != nullptr)
		return leftans;
	else
		return rightans;
}

//Finding the level of a given node from the root node
int search(Node* root, int key, int level = 0) {
	if (!root) return -1;
	if (root->data == key) return level;
	int left = search(root->left, key, level + 1);
	if (left != -1) return left;
	search(root->right, key, level + 1);
}
int findDist(Node* root, int a, int b) {
	Node* lca_node = lca(root, a, b);
	int l1 = search(lca_node, a);
	int l2 = search(lca_node, b);
	return l1 + l2;
}
