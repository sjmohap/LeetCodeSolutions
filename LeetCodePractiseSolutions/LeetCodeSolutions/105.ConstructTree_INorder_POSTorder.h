#pragma once
#include"headers.h"

class LEETSolutions Solution105 {
	unordered_map<int, int> indexMap;
	void populateIndexMap(vector<int>& inorder);
	TreeNode* treeUtil(int start, int end, int rootIdx, vector<int>& inorder, vector<int>& preOrder);

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
};