#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
using namespace std;


// Define EXPORTED for any platform
#ifdef _WIN32
# ifdef LEETSolutions_EXPORT
#   define LEETSolutions  __declspec( dllexport )
# else
#   define LEETSolutions  __declspec( dllimport )
# endif
#else
# define LEETSolutions
#endif

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
