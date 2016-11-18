/**
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. 
Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. 
If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. 
Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.
**/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0)
        	return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<int>::iterator gIter = g.begin();
        vector<int>::iterator sIter = s.begin();
        int count = 0;
        for (;gIter!=g.end() && sIter!=s.end();) {
        	if (*sIter >= gIter) {
        		++count;
        		++sIter;
        		++gIter;
        	} else {
        		++sIter;
        	}

        }
        return count;
    }
};