#pragma once
#include "headers.h"

class Solution {
	vector<TreeNode*> nodes;
	int getDepth(TreeNode* root);

	int getLastCount(TreeNode* root, int level);
public:
	int countNodes(TreeNode* root);
};