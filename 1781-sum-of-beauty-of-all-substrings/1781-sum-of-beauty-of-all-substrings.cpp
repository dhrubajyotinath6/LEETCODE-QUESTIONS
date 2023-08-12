class Solution {
    
public:
    int beauty(vector<int> &freq){
        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) continue;
            
            mini = min(freq[i], mini);
            maxi = max(freq[i], maxi);
        }
       
       return maxi - mini;
        
    }
public:
    int beautySum(string s) {
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){
            
           vector<int> freq(26,0);
            
           for(int j = i; j < s.length(); j++){
               freq[s[j] - 'a']++;
               ans += beauty(freq);
           }
        }
    return ans;
    }

};