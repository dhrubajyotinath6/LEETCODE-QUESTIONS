//https://leetcode.com/problems/binary-trees-with-factors/discuss/125794/C%2B%2BJavaPython-DP-solution
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        unordered_map<int, long> dp;
        
        long count = 0;
        long mod = pow(10, 9) + 7;
        
        for(int i = 0; i < arr.size(); i++){
            dp[arr[i]] = 1;
            
            for(int j = 0; j < i; j++){
                /*
                 10
                2   5                   
                */
                if(arr[i] % arr[j] == 0 && dp.find(arr[i] / arr[j]) != dp.end()){
                    dp[arr[i]] =  (dp[arr[i]] +  dp[arr[j]] * dp[arr[i] / arr[j]] ) % mod; 
                }                
                
            }
            
            count = (count + dp[arr[i]]) % mod;
        }
        
        return count;
    }
};




   // long res = 0, mod = pow(10, 9) + 7;
   //      sort(A.begin(), A.end());
   //      unordered_map<int, long> dp;
   //      for (int i = 0; i < A.size(); ++i) {
   //          dp[A[i]] = 1;
   //          for (int j = 0; j < i; ++j)
   //              if (A[i] % A[j] == 0)
   //                  dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
   //          res = (res + dp[A[i]]) % mod;
   //      }
   //      return res;