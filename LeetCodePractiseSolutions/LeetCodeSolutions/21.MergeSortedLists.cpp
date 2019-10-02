
#include "headers.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummy(3);
		ListNode* ptr = &dummy; 
		while (l1 && l2)
		{
			int val1 = l1->val;
			int val2 = l2->val;

			if (val1 <= val2)
			{
				ptr->next = new ListNode(val1);
				l1 = l1->next;
			}
			else
			{
				ptr->next = new ListNode(val2);
				l2 = l2->next;
			}
			ptr = ptr->next;
		}

		while (l1)
		{
			int val1 = l1->val;
			ptr->next = new ListNode(val1);
			l1 = l1->next;
			ptr = ptr->next;
		}

		while (l2)
		{
			int val1 = l2->val;
			ptr->next = new ListNode(val1);
			l2 = l2->next;
			ptr = ptr->next;
		}
		return dummy.next;
	}
};

int main21()
{
	ListNode* l1 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(3);
	l2->next->next = new ListNode(4);

	ListNode* res = Solution21().mergeTwoLists(l1, l2);
	return 0;
}