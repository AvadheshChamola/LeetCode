/*
96. Unique Binary Search Trees
Medium

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:
Input: n = 3
Output: 5

Example 2:
Input: n = 1
Output: 1

Constraints:
    1 <= n <= 19
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        //initiallisation
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[i-1-j]*dp[j];
            }
        }
        return dp[n];
    }
};
