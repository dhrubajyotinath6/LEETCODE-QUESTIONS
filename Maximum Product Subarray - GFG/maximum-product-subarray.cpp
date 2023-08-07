//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    
    long long maxi(long long x, long long y, long long z){
       
       if(x >= y && x >= z){
           return x;
       }else if(y >= x && y >= z){
           return y;
       }
       return z;
    }
    
    
    long long mini(long long x, long long y, long long z){
       
       if(x <= y && x <= z){
           return x;
       }else if(y <= x && y <= z){
           return y;
       }
       return z;
    }
    
    
    
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	    if(n == 0) return 0;
	    
	    long long maxSoFar = nums[0];
	    long long minSoFar = nums[0];
	    long long res = maxSoFar;
	    
	    for(int i = 1; i < n; i++){
	        
	        int curr = nums[i];
	        
	       // int temp = max(curr, max(maxSoFar*curr, minSoFar*curr));
	       // minSoFar = min(curr, min(maxSoFar*curr, minSoFar*curr));
	       long long temp = maxi(curr, maxSoFar*curr, minSoFar*curr);
	       minSoFar = mini(curr, maxSoFar*curr, minSoFar*curr);
	        
	       maxSoFar = temp;
	        
	        res = max(res, maxSoFar);
	    }
	    
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends