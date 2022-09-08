class Solution {
    
    int noOf1s(int n){
        
        int count = 0;
        
        while(n > 0){
            n = n&(n-1);
            count++;
        }
        
        return count;
    }
    
public:
    vector<int> countBits(int n) {
        
        vector<int> ans;
        
        for(int i = 0; i <= n; i++){
            
            ans.push_back(noOf1s(i));
        }
        
        return ans;
    }
};