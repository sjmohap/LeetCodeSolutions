#include "headers.h"

class Solution88 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


		while (m > 0 && n > 0) {
			int v1 = nums1[m-1];
			int v2 = nums2[n-1];
			if (v1 > v2)
			{
				nums1[m + n - 1] = v1;
				m -= 1;
			}
			else {
				nums1[m + n - 1] = v2;
				n -= 1;
			}

		}
		if (n > 0) {
			std::copy(nums2.begin(), nums2.begin() + n, nums1.begin());
		}

	}
};

int main88() {
	vector<int> nums1 = {11, 12, 23, 0, 0, 0}; int m = 3, n = 3;
	vector<int> nums2 = {2, 5, 6 };
	Solution88().merge(nums1, m, nums2, n);
	return 0;
}
