//https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/discuss/4063345/Hacker's-Delight

class Solution {
    
public:    
    int bits(int i){
        int cnt = 0;
        
        while(i){
            cnt += i & 1;
            i >>= 1;
        }
        
        return cnt;
    }
    
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(k == bits(i)) sum += nums[i];
        }
        
       return sum;
        
    }
};

