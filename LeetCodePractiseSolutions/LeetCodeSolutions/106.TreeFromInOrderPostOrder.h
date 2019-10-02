#pragma once
#include "headers.h"

class LEETSolutions Solution106 {

	unordered_map<int, int> indexMap;

	void populateIndexMap(vector<int>& inorder);

	TreeNode* treeUtil(int start, int end, int postorderIdx, vector<int>& inorder, vector<int>& postorder);
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
};