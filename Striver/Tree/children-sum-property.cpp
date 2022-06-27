void changeTree(Node *root){
	if(root==NULL) return;
	int sum = 0;
	if(root->left) sum += root->left->val;
	if(root->right) sum += root->right->val;

	if(sum>=root->val){
		root->val = sum;
	}
	else if(sum<root->val){
		if(root->left) root->left->val = root->val;
		if(root->right) root->right->val = root->val;
	}

    changeTree(root->left);
    changeTree(root->right);

	int total = 0;
	if(root->left) total += root->left->val;
	if(root->right) total += root->right->val;
	// if root is not leaf node
	if(root->left or root->right) root->val = total;
}