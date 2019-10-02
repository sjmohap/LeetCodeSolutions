
//class Solution105 {
//	int getIdx(int num, vector<int>& inorder)
//	{
//		for (int i = 0; i < inorder.size(); ++i)
//		{
//			if (inorder[i] == num)
//				return i;
//		}
//		return -1;
//	}
//
//	TreeNode* treeUtil(int start, int end, int& rootIdx, vector<int>& inorder, vector<int>& preOrder)
//	{
//		if (rootIdx < 0 || rootIdx >= inorder.size() || start > end)
//			return nullptr;
//
//		TreeNode* root = new TreeNode(preOrder[rootIdx]);
//
//		int idx = getIdx(preOrder[rootIdx], inorder);
//		rootIdx++;
//		auto left = treeUtil(start, idx - 1, rootIdx, inorder, preOrder);
//		if (left)
//			root->left = left;
//		else
//			--rootIdx;
//
//		rootIdx++;
//		auto right = treeUtil(idx + 1, end, rootIdx, inorder, preOrder);
//		if (right)
//			root->right = right;
//		else
//			--rootIdx;
//
//		return root;
//	}
//
//public:
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		int rootIdx = 0;
//		return treeUtil(0, inorder.size() - 1, rootIdx, inorder, preorder);
//	}
//};



int main()
{
	vector<int> preOrder = { 1, 2, 3 };
	vector<int> inOrder = { 1, 2, 3 };

	auto v = Solution105().buildTree(preOrder, inOrder);
	return 0;
}

