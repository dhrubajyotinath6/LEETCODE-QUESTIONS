class Solution {
    
public:
 vector<int> f(vector<int> &nums) {
     
     sort(nums.begin(), nums.end());
     
    vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
    
    for(int i = 0; i < nums.size(); i++){
        dp[1][i] = i;
    }
    
    dp[0][0] = 1;

    int maxLength = 1;
    int index = -1;
     
     
    
    for (int i = 1; i < nums.size(); i++) {
        
      dp[0][i] = 1;
      
      for (int j = 0; j < i; j++) {
          
        if ( ( (nums[i] % nums[j]) == 0 || (nums[j] % nums[i]) == 0) && dp[0][i] <= dp[0][j]) {
            
          dp[1][i] = j;
          dp[0][i] = dp[0][j] + 1;
          
         
          if(dp[0][i] > maxLength){
              maxLength = dp[0][i];
              index = i;
          }
          
        }
        
      }
    }
   
     
   
    vector<int> ans;
    while(index != -1 && index != dp[1][index]){
        ans.push_back(nums[index]);
        index = dp[1][index];
    }
    
    
    if(index >= 0){
        ans.push_back(nums[index]);
    }
     
    if(index == -1){
        ans.push_back(nums[0]);
    }
        
    return ans;
  }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 1) return nums;
        return f(nums);
    }
};