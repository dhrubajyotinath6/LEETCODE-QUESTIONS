/*
https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal

https://leetcode.com/problems/distribute-coins-in-binary-tree/solution/  -- very very imp
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
 
Below is the basic intuition behind this problem:

Root asks the left subtree, how much do you need or you've got extra? I'll give that/take it away to/from you via our direct edge, and pass it to right child, and if something remains, I'll take it.

Same question is asked to the right child.

Answer will be the sum of values(absolute) returned after the asked questions from the left(Left) and right(Right).

But what should the root return to its parent? It will return that how much does "his tree" need/has extra. That will be the signed sum of its Left+Right (question's answer) + same question asked to current root node.
 
 */
class Solution {
    
public:
    int dfs(TreeNode* node, int &ans){
        
        if(!node) return 0;
        
        int L = dfs(node->left, ans);
        int R = dfs(node->right, ans);
        
        ans += abs(L) + abs(R);
        
        return node->val + L + R - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};










