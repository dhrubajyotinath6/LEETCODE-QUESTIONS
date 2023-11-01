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
    void dfs(TreeNode* node, unordered_map<int,int> &mpp){
        if(!node) return;
        
        mpp[node->val]++;
        
        dfs(node->left, mpp);
        dfs(node->right, mpp);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        if(!root) return ans;
        
        unordered_map<int,int> mpp;
              
        dfs(root,mpp);
        
        int maxFreq = 0;
        for(auto &[key, value] : mpp){
            maxFreq = max(maxFreq, value);
        }
        
        for(auto &[key, value] : mpp){
            if(maxFreq == value) ans.push_back(key);
        }
        
        
        return ans;
        
    }
};