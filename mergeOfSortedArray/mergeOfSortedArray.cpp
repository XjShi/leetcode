/**
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
**/

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		std::vector<int>::iterator iter1 = nums1.begin();
		std::vector<int>::size_type iter2 = nums2.begin();
		while(iter1 != nums1.end() && iter2 != nums2.end()) {
			if (*iter1 < *iter2 && *(iter1 + 1) > *iter2) {
				nums1.insert(iter1+1, *iter2);
				iter2++;
			} else {
				iter1++;
			}
		}
		if (iter1 == nums1.begin() + m {

		}
	}

	void merge1(int A[], int m, int B[], int n) {
		int ia = m-1 ;
		int ib = n-1 ;
		int i = m + n - 1;
		for (int i=m+n-1; i>=0; i--){
			
			if (ia>=0 && ib<0){
				break;
			}
			if (ia<0 && ib>=0){
				A[i] = B[ib--];
				continue;
			}            
			if (ia>=0 && ib>=0){
				if (A[ia] > B[ib]){
					A[i] = A[ia--];
				}else{
					A[i] = B[ib--];
				}
			}

		}
	}

};