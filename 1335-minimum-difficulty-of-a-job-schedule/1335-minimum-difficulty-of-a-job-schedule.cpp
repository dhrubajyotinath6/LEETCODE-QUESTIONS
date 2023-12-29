class Solution {
    
public:
    int calculateCost(vector<int> &arr, int i, int j){
        
        int maxi = INT_MIN;
        
        for(int start = i; start <= j; start++){
            maxi = max(maxi, arr[start]);
        }
        
        return maxi;
    }
    
public:
    int f(vector<int> &jobDifficulty, int partition, int start, int end, vector<vector<int>> &dp){
        
        
        if(dp[partition][start] != -1){
            return dp[partition][start];
        }
        //base case start
        if(partition == 0){
            return  dp[partition][start] = calculateCost(jobDifficulty, start, end);
        }
        
        int remainingJob = end - start + 1;
        int partitionPossible = remainingJob - 1;
        
        if(partition > partitionPossible){
            return dp[partition][start] = INT_MAX;
        }
        
        //base case end
        
        /*
        [A, B, C,  |6, 5, 4,| 3, 2, 1]
         0  1  2   |3  4  5,| 6  7  8  
         
         start = 3, end = 8
        */
        int cost = INT_MAX;
        
        for(int i = start; i < end; i++){
            
            int remainingJobCost = f(jobDifficulty, partition - 1, i+1, end, dp);
            
            if(remainingJobCost != INT_MAX){
                cost =  min(cost, calculateCost(jobDifficulty, start, i)  + remainingJobCost);
            }
            
        }
        
        return  dp[partition][start] = cost;
        
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        
        if(d > n) return -1;
        
        vector<vector<int>> dp(d,vector<int>(n, -1));
        
        int ans = f(jobDifficulty, d-1, 0, n-1, dp);
        return ans;
    }
};