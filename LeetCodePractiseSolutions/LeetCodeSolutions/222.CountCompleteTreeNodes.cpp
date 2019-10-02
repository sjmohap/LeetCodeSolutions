#include "222.CountCompleteTreeNodes.h"

inline int Solution::getDepth(TreeNode* root)
{
	if (!root) return 0;
	return 1 + getDepth(root->left);
}

inline int Solution::getLastCount(TreeNode* root, int level)
{
	int sum = 0;
	if (level < 2 || !root)
		return sum;

	if (level == 2) {
		if (root->left && root->right)
			return 2;

		if (root->left || root->right)
			return 1;
		return 0;
	}
	sum = sum + getLastCount(root->left, level - 1);
	sum = sum + getLastCount(root->right, level - 1);
	return sum;
}

inline int Solution::countNodes(TreeNode* root) {
	if (!root)
		return 0;
	int totalLevels = getDepth(root);
	if (totalLevels == 1)
		return 1;

	int NodeCount = pow(2, totalLevels - 1) - 1 + getLastCount(root, totalLevels);
	return NodeCount;
}
