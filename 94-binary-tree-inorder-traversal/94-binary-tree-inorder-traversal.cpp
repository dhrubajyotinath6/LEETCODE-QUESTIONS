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

/*
class Solution {
    
    void dfs(TreeNode* node, vector<int> &ans){
        
        if(node->left) dfs(node->left,ans);
        
        ans.push_back(node->val);
            
        if(node->right) dfs(node->right,ans);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        dfs(root,ans);
        
        return ans;
    }
};

*/
    
class Solution {    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
         stack<TreeNode*> st;
         vector<int> ans;

         TreeNode* node = root;

         if(node == NULL) return ans;

        while(true){
            
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                
                if(st.empty() == true) break;
                
                node = st.top();
                st.pop();
                
                ans.push_back(node->val);
                
                node = node->right;
            }
        }
        
        return ans;
        
    }
};
    
    