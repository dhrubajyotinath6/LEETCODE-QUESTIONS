class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        vector<int> mpp(26,0);
        
        for(int i = 0; i < s.size(); i++){
            mpp[s[i] - 'a']++;
        }
        
        bool flag = false;
        
        for(auto i : mpp){
            
            if(i % 2 != 0 && flag == true) return false;
            else if (i % 2 != 0) flag = true;
        }
        
        return true;
    }
};