//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/discuss/78551/7-lines-Easy-Java-Solution

class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        vector<string> output;
        istringstream ss(preorder);
        string token;
        
        int diff = 1;
        
        while(getline(ss, token, ',')){

            if(--diff < 0) return false;
            if(token != "#") diff += 2;
            
        }
        
        return diff == 0;
        
    }
};


