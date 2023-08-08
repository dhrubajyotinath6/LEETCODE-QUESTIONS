//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    long long mod = 1000000007;
    
    int nthFibonacci(int n){
        // code here
        long n0 = 0;
        long n1 = 1;
        
        for(int i = 2; i <= n; i++){
            int temp = (n1 + n0) % mod;
            
            n0 = n1;
            n1 = temp;
        }
        
        return n1 % mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends