#include "106.TreeFromInOrderPostOrder.h"

inline void Solution106::populateIndexMap(vector<int>& inorder)
{
	for (int i = 0; i < inorder.size(); ++i)
	{
		indexMap[inorder[i]] = i;
	}
}

inline TreeNode* Solution106::treeUtil(int start, int end, int postorderIdx, vector<int>& inorder, vector<int>& postorder)
{
	if (start > end || postorderIdx < 0 || postorderIdx >= inorder.size())
		return nullptr;

	TreeNode* root = new TreeNode(postorder[postorderIdx]);

	int idx = indexMap[postorder[postorderIdx]];
	root->right = treeUtil(idx + 1, end, postorderIdx - 1, inorder, postorder);
	root->left = treeUtil(start, idx - 1, postorderIdx - (end - idx + 1), inorder, postorder);

	return root;
}

inline TreeNode* Solution106::buildTree(vector<int>& inorder, vector<int>& postorder) {
	populateIndexMap(inorder);
	return treeUtil(0, inorder.size() - 1, inorder.size() - 1, inorder, postorder);
}
