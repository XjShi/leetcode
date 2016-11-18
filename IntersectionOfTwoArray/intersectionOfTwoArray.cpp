/**
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
**/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        bool flag = false;
        for (vector<int>::iterator iter1 = nums1.begin(), iter2 = nums2.begin(); iter1 != nums1.end() && iter2 != nums2.end();) {
            int x1 = *iter1;
            int x2 = *iter2;
            int lastValue = 0;
            if (result.size() != 0) {
                lastValue = result.back();
                flag = true;
            }
            if (x1 == x2) {
                if (!flag || (flag && lastValue != x1)) {
                    result.push_back(x1);
                }
                iter1++;
                iter2++;
            }
            else if (x1 < x2) {
                iter1++;
            }
            else if (x2 < x1) {
                iter2++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1;
    vector<int> nums2;
    int a1[] = {1,2,3,4,2};
    int a2[] = {2,4,2};
    for (int i = 0; i < sizeof(a1) / sizeof(*a1); i++) {
        nums1.push_back(a1[i]);
    }
    for (int i = 0; i < sizeof(a2) / sizeof(*a2); i++) {
        nums2.push_back(a2[i]);
    }
    Solution s = Solution();
    s.intersection(nums1, nums2);
}