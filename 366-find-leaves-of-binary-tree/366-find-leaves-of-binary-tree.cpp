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
 https://leetcode.com/problems/find-leaves-of-binary-tree/solution/
 */

class Solution {
public:
    
    vector<pair<int, int>> pairs;
    
    int getHeight(TreeNode *root) {
        
        // return -1 for null nodes
        if (!root) return -1;
        
        // first calculate the height of the left and right children
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        // based on the height of the left and right children, obtain the height of the current (parent) node
        int currHeight = max(leftHeight, rightHeight) + 1;
        
        // collect the pair -> (height, val)
        this->pairs.push_back({currHeight, root->val});
        
        // return the height of the current node
        return currHeight;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        this->pairs.clear();
        
        int height = getHeight(root);
        
        // cout << height <<endl;
        
        // sort all the (height, val) pairs
        sort(this->pairs.begin(), this->pairs.end());
        
        int n = this->pairs.size(), i = 0;
        
        vector<vector<int>> solution(height + 1, vector<int>());
        
        while(i < n){
            
            int level = this->pairs[i].first;
            int value = this->pairs[i].second;
            
//             cout << level << " - " << value << endl; 
            
            solution[level].push_back(value);
            i++;
        }
        
        return solution;
    }
};




