/**
	There are two sorted arrays nums1 and nums2 of size m and n respectively.

	Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

	Example 1:
	nums1 = [1, 3]
	nums2 = [2]

	The median is 2.0
	Example 2:
	nums1 = [1, 2]
	nums2 = [3, 4]

	The median is (2 + 3)/2 = 2.5
**/

class Solution {
public:
	/**
	该算法思路是，先合并，然后直接计算median
	复杂度为O(m+n)，没有达到题目要求O(log(m+n))
	**/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> mergedVector;

        std::vector<int>::iterator iter1 = nums1.begin();
        std::vector<int>::iterator iter2 = nums2.begin();
        while(iter1 != nums1.end() && iter2 != nums2.end()) {
            if (*iter1 < *iter2)
        		{
        			mergedVector.push_back(*iter1);
        			iter1++;
        		}
        		else 
        		{
        			mergedVector.push_back(*iter2);
        			iter2++;
        		}
        }
        
        if (iter2 == nums2.end() && iter1 != nums1.end())
        {
        	mergedVector.insert(mergedVector.end(), iter1, nums1.end());
        }

        if (iter1 == nums1.end() && iter2 != nums2.end())
        {
        	mergedVector.insert(mergedVector.end(), iter2, nums2.end());
        }

        if (mergedVector.size() % 2 == 0)
        {
        	int halfIndex = mergedVector.size() / 2;
        	return (mergedVector[halfIndex - 1] + mergedVector[halfIndex]) / 2.0;
        }
        else 
        {
        	return mergedVector[(mergedVector.size() - 1) / 2];
        }
    }
};