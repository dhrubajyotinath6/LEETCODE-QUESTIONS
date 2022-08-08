//https://leetcode.com/problems/count-the-number-of-consistent-strings/discuss/969668/C%2B%2B-easy-solution    --FRIENDLY

// https://leetcode.com/problems/count-the-number-of-consistent-strings/discuss/969522/C%2B%2B-all_of --votrubac

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int mpp[26] = {0}, ans = 0;
        
        for(auto &ch : allowed){
            mpp[ch - 'a']++;
        }
        
        for(auto &word : words){
            
            bool isConsistent = true;
            
            for(auto &ch : word){
                
                if(mpp[ch - 'a'] == 0){
                    
                    isConsistent = false;
                    break;
                }                
            }
            if(isConsistent) ans++;
        }
        
        return ans;
        
    }
};