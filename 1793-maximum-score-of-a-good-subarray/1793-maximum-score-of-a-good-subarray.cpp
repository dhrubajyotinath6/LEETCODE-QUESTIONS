class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        int left = k, right = k;
        int ans = nums[k],  currMin = nums[k];
        
        while(left > 0 || right < n-1){
            
            int possibleLeft = 0;
            int possibleRight = 0;
            
            if(left > 0)  possibleLeft = nums[left - 1];
            if(right < n - 1) possibleRight = nums[right + 1];
            
            if(possibleLeft < possibleRight){
                right++;
                currMin = min(currMin, possibleRight);
            }else{
                left--;
                currMin = min(currMin, possibleLeft);
            }
            
            ans = max(ans, currMin * (right - left + 1));
        }
        
        return ans;
    }
};