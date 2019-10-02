#include "105.ConstructTree_INorder_POSTorder.h"

inline void Solution105::populateIndexMap(vector<int>& inorder)
{
	for (int i = 0; i < inorder.size(); ++i)
	{
		indexMap[inorder[i]] = i;
	}
}

inline TreeNode* Solution105::treeUtil(int start, int end, int rootIdx, vector<int>& inorder, vector<int>& preOrder)
{
	if (rootIdx < 0 || rootIdx >= inorder.size() || start > end)
		return nullptr;

	TreeNode* root = new TreeNode(preOrder[rootIdx]);

	int idx = indexMap[preOrder[rootIdx]];// , inorder);

	root->left = treeUtil(start, idx - 1, rootIdx + 1, inorder, preOrder);
	// if(left)
	//     root -> left = left;
	// else
	//     --rootIdx;

	//rootIdx++;
	root->right = treeUtil(idx + 1, end, rootIdx + idx - start + 1, inorder, preOrder);
	//         if(right)
	//             root -> right = right;
	//         else
	//             --rootIdx;

	return root;
}

inline TreeNode* Solution105::buildTree(vector<int>& preorder, vector<int>& inorder) {
	//         int rootIdx = 0;
	populateIndexMap(inorder);
	return treeUtil(0, inorder.size() - 1, 0, inorder, preorder);
}
