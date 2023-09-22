class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        
        int i = 0;
        int n = word1.size(), m = word2.size();
        
        for(i = 0; i < min(n,m); i++){
            ans += word1[i];
            ans += word2[i];
        }
        
        int j = i;
        
        while(j < n){
            ans += word1[j++];
        }
        
        j = i;  
        
        while(j < m){
            ans += word2[j++];
        }
        
        return ans;
    }
};