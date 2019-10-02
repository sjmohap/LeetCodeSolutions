#include "pch.h"
#include "CppUnitTest.h"

#include "..\LeetCodeSolutions\105.ConstructTree_INorder_POSTorder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeSolutionTester
{
	TEST_CLASS(LeetCodeSolutionTester)
	{
	public:
		
		TEST_METHOD(Solution181)
		{
			vector<int> preOrder = { 1, 2, 3 };
			vector<int> inOrder = { 1, 2, 3 };

			auto v = Solution105().buildTree(preOrder, inOrder);
			
		}
	};
}
