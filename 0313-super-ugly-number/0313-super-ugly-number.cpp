
//https://leetcode.com/problems/super-ugly-number/discuss/277313/My-view-of-this-question-hope-it-can-help-you-understand!!!   --check this too
/*
tc - O(nk) ; k = primes.length
sc - O(n)
*/

#define ll long long int

class Solution {
    
public:
    ll minFunc(ll a, ll b){
        if(a < b) return a;
        return b;
    }
    
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<ll> pointers(primes.size(), 0);
        
        vector<ll> dp(n, 0);
        dp[0] = 1;
        
        for(int i = 1; i < n; i++){
            
            int mini = INT_MAX;
            
            for(int i = 0; i < pointers.size(); i++){
                mini =  minFunc(mini, dp[pointers[i]] * primes[i]);
            }
            
            for(int i = 0; i < pointers.size(); i++){
                if(mini == dp[pointers[i]]*primes[i]){
                   pointers[i]++; 
                }
            }
            
            dp[i] = mini;
        }
        
        int ans = dp[n-1];
        return ans;
        
    }
};