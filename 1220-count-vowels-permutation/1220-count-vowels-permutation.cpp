/*
start   =>  a / e / i / o / u   # start denotes 1st character of string which can be any vowel
a       =>  e
e       =>  a / i
i       =>  a / e / o / u
o       =>  i / u
u       =>  a


https://leetcode.com/problems/count-vowels-permutation/discuss/1315039/Optimization-from-Brute-Force-to-DP-to-O(1)-Time-Solutions-or-Explained

https://leetcode.com/problems/count-vowels-permutation/discuss/1315113/C%2B%2BJavaPython-Top-down-DP-Bottom-up-DP-Picture-explain-Clean-and-Concise


https://leetcode.com/problems/count-vowels-permutation/discuss/398222/Detailed-Explanation-using-Graphs-With-Pictures-O(n)
*/
class Solution{
public:
    int countVowelPermutation(int n);
};

int Solution :: countVowelPermutation(int n)
{
    vector<vector<long>> dp(n+1, vector<long>(5, 0));
    
    int MOD = 1e9 + 7;
    
    /* dp[i][j] denotes the number of valid strings of length i */
    
    for(int i = 0; i < 5; i++)
        dp[1][i] = 1;
    
    for(int i = 1; i < n; i++)
    {
        dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) %MOD;
        
        dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD;
        
        dp[i+1][2] = (dp[i][1] + dp[i][3]) % MOD;
        
        dp[i+1][3] = dp[i][2];
        
        dp[i+1][4] = (dp[i][2] + dp[i][3]) % MOD;
    }
    
    int res = 0;
    for(int i = 0; i < 5; i++)
        res = (res + dp[n][i]) % MOD;
    
    return res;
}