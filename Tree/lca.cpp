
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
