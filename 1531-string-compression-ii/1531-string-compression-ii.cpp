/*
1. https://leetcode.com/problems/string-compression-ii/discuss/756022/C%2B%2B-Top-Down-DP-with-explanation-64ms-short-and-clear

2. https://leetcode.com/problems/string-compression-ii/discuss/2704470/LeetCode-The-Hard-Way-Explained-Line-By-Line

3. https://leetcode.com/problems/string-compression-ii/discuss/757506/Detailed-Explanation-Two-ways-of-DP-from-33-to-100

*/

/*
Input
"llllllllllttttttttt"
1
Output
5
Expected
4

l - 10
t - 9



*/
/*
class Solution {
    
public:
  struct valueCompare {
    bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return y.second < x.second;
    }
  };
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        if(k == s.size()) return 0;
        
        unordered_map<char, int>characterFrequencyMap;
        for(auto& ch : s){
            characterFrequencyMap[ch]++;
        }
        
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> minHeap;

        // add all characters to the max heap
        for (auto entry : characterFrequencyMap) {
          minHeap.push(entry);
        }
        
        
        while(!minHeap.empty() && k > 0){
            auto entry = minHeap.top();
            minHeap.pop();
            
            if(entry.second <= k){
                k -= entry.second;
            }else{
               
                // entry.second -= k;
                // k = 0;
                minHeap.push(entry);
            }
        }
        
        int len = 0;
        
        while(!minHeap.empty()){
            auto entry = minHeap.top();
            minHeap.pop();
            
           int x = entry.second;
           if( x == 1) len += 1;
           else if(x <= 9 && x > 1) len += 2;
           else if( x >= 10 && x <= 99) len += 3;
           else if( x == 100) len += 4;
        }
        
        return len;
        
        
    }
};

*/

/*
class Solution{
   
public:
    vector<vector<vector<vector<int>>>> dp;

    int calcLen(int len) {
        if (len == 0) return 0;
        else if (len == 1) return 1;
        else if (len < 10) return 2;
        else if (len < 100) return 3;
        else return 4;
    }

    int solve(int i, int ch, int len, int k, string str) {
        
        if (i == str.length()) return calcLen(len);
        
        if (dp[i][ch][len][k] == INT_MAX) {
            
            int c = str[i] - 'a';
            
            if (k > 0) dp[i][ch][len][k] = solve(i + 1, ch, len, k - 1, str);
            if (c == ch) dp[i][ch][len][k] = min(dp[i][ch][len][k], solve(i + 1, ch, len + 1, k, str));
            else dp[i][ch][len][k] = min(dp[i][ch][len][k], calcLen(len) + solve(i + 1, c, 1, k, str));
            
        }
        return dp[i][ch][len][k];
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        int n = s.length();
        dp.resize(n, vector<vector<vector<int>>>(26, vector<vector<int>>(n + 1, vector<int>(k + 1, INT_MAX))));

        return solve(0, 0, 0, k, s);
    }
    
    
};
*/


class Solution
{
    int encodedLen(int len)
    {
        if (len <= 1) return len;
        else if (len < 10) return 2;
        else if (len < 100) return 3;
        else return 4;
    }

    public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.length();
        vector<vector<long>> dp(n+1,vector<long>(k+1,INT_MAX));
        dp[0][0]=0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j > 0) 
                    dp[i][j] = dp[i - 1][j - 1];
                int removed = 0, count = 0;
                for (int p = i; p > 0; p--)
                {
                    if (s[p-1] == s[i-1]) 
                        count++;
                    else if (++removed > j)
                        break;
                    dp[i][j] = min(dp[i][j], dp[p - 1][j - removed] + encodedLen(count));
                }
            }
        }
        return dp[n][k];
    }
};