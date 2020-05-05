int dfs(struct TreeNode* root, int base)
{
	if (root == NULL) {
		return 0; 
	} else {
		int value = base * 10 + root->val;
		int left = dfs(root->left, value);
		int right = dfs(root->right, value);
		// printf("v=%d, left=%d, right=%d\n", root->val, left, right);
		if (left > 0 || right > 0) {
			return left + right;
		} else {			
			return value;
		} 
	}
}

int sumNumbers(struct TreeNode* root)
{
	return dfs(root, 0);
}
