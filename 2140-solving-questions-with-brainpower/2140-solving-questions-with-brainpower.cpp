//https://leetcode.com/problems/solving-questions-with-brainpower/discuss/1693670/Recursive-%2B-Memoized-%2B-Tabulation-oror-Variation-of-HOUSE-ROBBER

//https://leetcode.com/problems/solving-questions-with-brainpower/discuss/1692963/DP


class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        
        int n = q.size(); 
        // long long dp[n+1]{};
        vector<long long> dp(n+1);
        
        for(int i = n-1; i >= 0; i--){
            int nx = q[i][1];
            
            long long take = q[i][0] + ((i + 1 + nx <= n) ? dp[i+1+nx] : 0);
            long long not_take = dp[i+1];
            
            dp[i] = max(take, not_take);
        }
        
        return dp[0];
    }
};


