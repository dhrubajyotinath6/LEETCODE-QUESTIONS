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
    TreeNode* markParents(TreeNode* root, int start, unordered_map<TreeNode*,TreeNode*> &mpp){
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* res;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node->val == start) res = node;
                
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                mpp[node->right] = node;
                q.push(node->right);
            }
            
        }
        
        return res;
    }
    
    
public:
    int travel(unordered_map<TreeNode*,TreeNode*> &mpp, TreeNode* node){
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        
        q.push(node);
        vis[node] = true;
        
        int time = 0;
        
        while(!q.empty()){
            
            int s = q.size();
            
            time++;
            
            for(int i = 0; i < s; i++){
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
        
        return time - 1;
    }
    
public:
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*,TreeNode*> mpp;
        TreeNode* res = markParents(root,start,mpp);
        
        int time = travel(mpp, res);
        
        return time;
    }
};