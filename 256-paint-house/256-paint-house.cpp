/*
class Solution {
    
public:
    int minCost(vector<vector<int>>& costs) {
        
        if(costs.size() == 0) return 0;
        
        return min(paint(0,0,costs), min(paint(0,1,costs), paint(0,2,costs))); 
    }
    
    int paint(int n, int color, vector<vector<int>> &costs){
        
        int totalCost = costs[n][color];
        
        if(n == costs.size() - 1) return totalCost;
        
        if(color == 0){
            totalCost += min(paint(n+1,1,costs), paint(n+1,2,costs));
        }else if(color == 1){
            totalCost += min(paint(n+1,0,costs), paint(n+1,2,costs));
        }else{
            totalCost += min(paint(n+1,0,costs), paint(n+1,1,costs));
        }
        
        return totalCost;
    }
};
*/

/*
class Solution {
    
public:
    int minCost(vector<vector<int>>& costs) {
        
        if(costs.size() == 0) return 0;
        vector<vector<int>> dp(costs.size(),vector<int>(3));
        
        return min(paint(0,0,costs,dp), min(paint(0,1,costs,dp), paint(0,2,costs,dp))); 
    }
    
    int paint(int n, int color, vector<vector<int>> &costs, vector<vector<int>> &dp){
        
        int totalCost = costs[n][color];
        
        if(n == costs.size() - 1) return totalCost;
        
        if(dp[n][color]) return dp[n][color];
        
        if(color == 0){
            totalCost += min(paint(n+1,1,costs,dp), paint(n+1,2,costs,dp));
        }else if(color == 1){
            totalCost += min(paint(n+1,0,costs,dp), paint(n+1,2,costs,dp));
        }else{
            totalCost += min(paint(n+1,0,costs,dp), paint(n+1,1,costs,dp));
        }
        
        return dp[n][color] = totalCost;
    }
};

*/


class Solution {
    
public:
    int minCost(vector<vector<int>>& costs) {
        
        if (costs.size() == 0) return 0; 
        
        for (int n = costs.size() - 2; n >= 0; n--) {
            
            // Total cost of painting the nth house red.
            costs[n][0] += min(costs[n + 1][1], costs[n + 1][2]);
            
            // Total cost of painting the nth house green.
            costs[n][1] += min(costs[n + 1][0], costs[n + 1][2]);
            
            // Total cost of painting the nth house blue.
            costs[n][2] += min(costs[n + 1][0], costs[n + 1][1]);
        }

         

        return min(min(costs[0][0], costs[0][1]), costs[0][2]);
    }
    
  
};