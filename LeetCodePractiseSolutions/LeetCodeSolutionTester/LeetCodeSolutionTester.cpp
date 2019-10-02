#include "pch.h"
#include "CppUnitTest.h"

#include "105.ConstructTree_INorder_POSTorder.h"
#include "106.TreeFromInOrderPostOrder.h"
#include "222.CountCompleteTreeNodes.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeSolutionTester
{
	TEST_CLASS(LeetCodeSolutionTester)
	{
	public:
		
		TEST_METHOD(Solution105_test)
		{
			vector<int> preOrder = { 1, 2, 3 };
			vector<int> inOrder = { 1, 2, 3 };

			auto v = Solution105().buildTree(preOrder, inOrder);			
		}

		TEST_METHOD(Solution106_test)
		{
			vector<int> postOrder = { 1, 2, 3 };
			vector<int> inOrder = { 1, 2, 3 };

			auto v = Solution106().buildTree(inOrder, postOrder);

		}
	};
}
