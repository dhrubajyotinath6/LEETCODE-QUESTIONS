class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> mpp;
        
        for(auto chr : s){
            mpp[chr]++;
        }
        
        int ans = 0;
        int single = 0;
        
        for(int j = 0; j < s.size(); j++){
            
            char ch = s[j];
            
            while(mpp[ch] > 1){
                
                ans += 2;
                
                mpp[ch] -= 2;
            }
            
            if(mpp[ch] == 1 && single == 0 ) single = 1;
            
        }
        
        cout << single << endl;
        
        return (ans + single);
        
    }
};
