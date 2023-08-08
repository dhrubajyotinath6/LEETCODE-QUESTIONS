//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int denominations[], int n, int total) {

        // code here.
    vector<vector<long long int>> dp(n, vector<long long int>(total + 1));

    // populate the total=0 columns, as we will always have an empty set for zero total
    for (int i = 0; i < n; i++) {
      dp[i][0] = 1;
    }
    // process all sub-arrays for all capacities

    for (int i = 0; i < n; i++) {
      for (int t = 1; t <= total; t++) {
        if (i > 0) {
          dp[i][t] = dp[i - 1][t];
        }
        if (t >= denominations[i]) {
          dp[i][t] += dp[i][t - denominations[i]];
        }
      }
    }

    // total combinations will be at the bottom-right corner.
    return dp[n - 1][total];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends