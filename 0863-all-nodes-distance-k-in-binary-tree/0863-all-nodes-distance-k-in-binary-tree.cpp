/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mpp,  TreeNode* target){
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(!root) return {};
        
        unordered_map<TreeNode*,TreeNode*> mpp;
        markParents(root, mpp, target);
        
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        
        q.push(target);
        vis[target] = true;
        int level = 0;
        
        while(!q.empty()){
            
            if(k == level) break;
            else level++;
            
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                } 
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                } 
                if(mpp[node] && !vis[mpp[node]]){
                    q.push(mpp[node]);
                    vis[mpp[node]] = true;
                } 
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            ans.push_back(node->val);
        }
        
        return ans;
    }
};








