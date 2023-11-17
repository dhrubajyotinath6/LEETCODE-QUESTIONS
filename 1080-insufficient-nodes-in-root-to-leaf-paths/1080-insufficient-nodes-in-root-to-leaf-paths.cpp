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
 
 //https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/discuss/308326/JavaC%2B%2BPython-Easy-and-Concise-Recursion
 */
class Solution {
 
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        if(root->left == NULL && root->right == NULL){
            return root->val < limit ? NULL : root;
        }
        
        if(root->left){
            root->left = sufficientSubset(root->left, limit - root->val);
        }
        if(root->right){
            root->right = sufficientSubset(root->right, limit - root->val);
        }
        
        return (root->left == NULL && root->right == NULL) ? NULL : root;
        
    }
};


/*

Explanation
if root.left == root.right == null, root is leaf with no child {
    if root.val < limit, we return null;
    else we return root.
}
if root.left != null, root has left child {
    Recursively call sufficientSubset function on left child,
    with limit = limit - root.val
}
if root.right != null, root has right child {
    Recursively call sufficientSubset function on right child,
    with limit = limit - root.val
}
if root.left == root.right == null,
root has no more children, no valid path left,
we return null;
else we return root.

*/