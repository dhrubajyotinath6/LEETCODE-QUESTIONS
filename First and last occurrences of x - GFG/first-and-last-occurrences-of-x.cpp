//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int search(int arr[], int n, int val, bool maxi){
    
    int keyIndex = -1;
    
    int start = 0, end = n-1;
    
    while(start <= end){
        int mid = (start + end) >> 1;
        
        if(val > arr[mid]){
            start = mid+1;
        }else if(val < arr[mid]){
            end = mid -1;
        }else{
            keyIndex = mid;
            
            if(maxi){
                start = mid+1;
            }else{
                end = mid -1;
            }
        }
    }
    
    return keyIndex;
    
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans(2, -1);
    
    ans[0] = search(arr, n, x, false);
    
    if(arr[0] != -1){
        ans[1] = search(arr, n, x, true);
    }
    
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends