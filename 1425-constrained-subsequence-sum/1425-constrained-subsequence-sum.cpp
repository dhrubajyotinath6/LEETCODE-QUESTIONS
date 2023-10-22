class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        deque<int> queue;
        vector<int> dp(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            
            if(!queue.empty() && i - queue.front() > k) queue.pop_front();
            
            dp[i] = (!queue.empty() ? dp[queue.front()] : 0) + nums[i];
            
            while(!queue.empty() && dp[queue.back()] < dp[i]){
                queue.pop_back();
            }
            
            if(dp[i] > 0){
                queue.push_back(i);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};