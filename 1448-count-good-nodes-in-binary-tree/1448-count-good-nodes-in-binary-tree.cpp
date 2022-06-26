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
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.


*/

class Solution {
public:
    int goodNodes(TreeNode* root) {   
        
        int numGoodNodes = 0;
        dfs(root, INT_MIN, numGoodNodes);
        return numGoodNodes;
    }
    
    void dfs(TreeNode* node, int maxSoFar, int &numGoodNodes){
        
        if(maxSoFar <= node->val) numGoodNodes++;
        
        if(node->left != NULL) dfs(node->left, max(node->val,maxSoFar), numGoodNodes);
        
        if(node->right != NULL) dfs(node->right, max(node->val,maxSoFar), numGoodNodes);
    }
};