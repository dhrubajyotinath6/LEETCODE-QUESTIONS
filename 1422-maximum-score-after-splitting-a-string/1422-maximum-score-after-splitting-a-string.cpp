class Solution {
public:
    int maxScore(string s) {
        
        int ans = 0;
        int n = s.size();
        
        /*
        0   1   1   1   0   1
        4   4   3   2   1   1 --suffix
        
        */
        vector<int> suffix(n);
        suffix[n-1] = s[n-1] - '0';
        
        for(int i = n-2; i >= 0; i--){
            char ch = s[i];
            int x = ch - '0';
            
            suffix[i] += (x + suffix[i+1]);
            
        }
        
        int zeros = 0;
        
        for(int i = 0; i <= n-2; i++){
            
            char ch = s[i];
            int x = ch - '0';
            
            if(x == 0) zeros++;
           
            ans = max(ans, zeros + suffix[i+1]);
            
            
            
        }
        
        return ans;
    }
};