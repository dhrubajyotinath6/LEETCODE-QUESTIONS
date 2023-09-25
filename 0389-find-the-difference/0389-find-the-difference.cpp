class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> freq(26,0);
        
        for(auto& ch : s){
            freq[ch - 'a']++;
        }
        
        for(auto& ch : t){
            freq[ch - 'a']--;
            
            if(freq[ch - 'a'] == -1) return ch;
        }
        
        
        return 'a';
    }
};