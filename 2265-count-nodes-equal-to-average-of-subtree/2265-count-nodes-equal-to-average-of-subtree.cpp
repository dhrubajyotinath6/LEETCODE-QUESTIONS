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
    
public:
    vector<int> f(TreeNode* node, int &res){
        
        
        if(!node) return {0,0};
        
        vector<int> left = f(node->left, res);
        vector<int> right = f(node->right, res);
        
        int count = left[1] + right[1] + 1;    
        int avg = (left[0] + right[0] + node->val)/count;
        
        if(avg == node->val) res++;
        
        return {left[0] + right[0] + node->val, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
       
        if(!root) return 0;
        
        int res = 0;
        f(root, res);
        return res;
    }
};