//https://leetcode.com/problems/rotate-function/discuss/87853/Java-O(n)-solution-with-explanation

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        if(nums.size() <= 1) return 0;
        
        int sum = 0, fZero = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            fZero += (i*nums[i]);
        }
        
        int maxi = fZero;
        
        for(int i = 1; i <= n-1; i++){
            
            int f = (fZero + sum - n*nums[n-i]);
            maxi = max(maxi, f);
            
            fZero = f;
        }
        
        return maxi;
    }
};