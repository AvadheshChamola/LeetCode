//110. Balanced Binary Tree
/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
    The number of nodes in the tree is in the range [0, 5000].
    -10^4 <= Node.val <= 10^4

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    pair<bool,int> isBalancedHelper(TreeNode* root){
        if(!root){
            return make_pair(1,0);
        }
        pair<bool,int> l=isBalancedHelper(root->left);
        pair<bool,int> r=isBalancedHelper(root->right);
        return make_pair(l.first && r.first && abs(l.second-r.second)<=1,                                           1+max(l.second,r.second));
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).first;
    }
};