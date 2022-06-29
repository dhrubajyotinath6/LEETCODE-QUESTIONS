class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        vector<int> dp(n + 1, -1);
        
        int ans = minimumCost(cost, n, dp);
        
        return ans;
    }
    
    int minimumCost(vector<int>& cost, int i, vector<int> &dp){
        
        if(i <= 1) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int downOne = cost[i-1] + minimumCost(cost, i - 1, dp);
        int downTwo = cost[i-2] + minimumCost(cost, i - 2, dp);
        
        return dp[i] = min(downOne, downTwo);
    }
};