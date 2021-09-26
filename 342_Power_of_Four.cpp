/*
342. Power of Four
Easy

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Example 1:

Input: n = 16
Output: true

Example 2:

Input: n = 5
Output: false

Example 3:

Input: n = 1
Output: true

Constraints:
    -231 <= n <= 231 - 1
Follow up: Could you solve it without loops/recursion?
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && (n-1)%3==0;
    }
};
//mETHOD 2
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n&(n-1))==0 && (n&0x55555555)==n;
    }
};
