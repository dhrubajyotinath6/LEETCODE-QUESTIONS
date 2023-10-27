class Solution {
public:    
     unordered_map<string,bool> dp;
    
     bool isScramble(string s1, string s2) {
         
        if(s1.size()!=s2.size()){
            return false;
        }
         
        if(s1 == s2){
            return true;
        }
         
        if(dp.find(s1+s2) != dp.end()){
            return dp[s1+s2];
        }
                 
        vector<int> freq(26,0);
         
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
         
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return dp[s1+s2]=false;
            }
        }
         
         int n = s1.size();
         
         for (int i = 1; i <= n - 1; i++){
             
           // g r | e a t ,  r g | e a t
           if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))){
               dp[s1 + s2] = true;
               return true;
           }
           
           // g r | e a t  ,  e a t | g r
           if (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))){
               dp[s1 + s2] = true;
               return true;
           }
           
    }
     dp[s1 + s2] = false;
    return false;
    }
    
}; 
