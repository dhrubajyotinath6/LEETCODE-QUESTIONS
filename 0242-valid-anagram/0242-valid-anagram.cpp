class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;
        
        vector<int> freq(26,0);
        
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        
        for(int i = 0; i < 26; i++){
            if(freq[i]) return false;
        }
        
        return true;
    }
};