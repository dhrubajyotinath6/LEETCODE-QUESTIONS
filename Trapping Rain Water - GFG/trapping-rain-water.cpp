//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int height[], int n){
        // code here
        
        int left = 0, right = n-1, maxLeft = 0, maxRight = 0;
        long long res = 0;
        
        while(left <= right){
            if(height[left] <= height[right]){
                
                if(height[left] >= maxLeft) maxLeft = height[left];
                else res += maxLeft - height[left];
                
                left++;
            }
            else{
                if(height[right] >= maxRight) maxRight = height[right];
                else res += maxRight - height[right];
                
                right--;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends