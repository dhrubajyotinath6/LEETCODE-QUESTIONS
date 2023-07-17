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
//https://leetcode.com/problems/house-robber-iii/discuss/79330/Step-by-step-tackling-of-the-problem
class Solution {
  
    // 0 -> not rob,   1 -> rob
public:
    vector<int> robSub(TreeNode* root){
        
        if(root == NULL) return {0, 0};
        
        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);
        
        vector<int> res(2);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        
        return res;
     } 
public:
    int rob(TreeNode* root) {
        vector<int>res = robSub(root);
        return max(res[0], res[1]);
    }
};





