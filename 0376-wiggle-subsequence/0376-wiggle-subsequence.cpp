class Solution {
    
public:
    int findLASLength(const vector<int> &nums) {
        if (nums.empty()) {
          return 0;
        }
        // dp[i][0] = stores the LAS ending at 'i' such that the last two elements are in ascending
        // order dp[i][1] = stores the LAS ending at 'i' such that the last two elements are in
        // descending order
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        int maxLength = 1;
        
        for (int i = 0; i < nums.size(); i++) {
          // every single element can be considered as LAS of length 1
          dp[i][0] = dp[i][1] = 1;
            
          for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
              // if nums[i] is BIGGER than nums[j] then we will consider the LAS ending at 'j'
              // where the last two elements were in DESCENDING order
              dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
              maxLength = max(maxLength, dp[i][0]);
            } else if (nums[i] != nums[j]) { // if the numbers are equal don't do anything
              // if nums[i] is SMALLER than nums[j] then we will consider the LAS ending at
              // 'j' where the last two elements were in ASCENDING order
              dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
              maxLength = max(maxLength, dp[i][1]);
            }
          }
        }
        
    return maxLength;
  }
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        return findLASLength(nums);
    }
};