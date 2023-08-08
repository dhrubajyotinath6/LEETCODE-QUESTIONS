//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    
    public:
    bool isCeleb(int i, int n, vector<vector<int> >& M){
        
        for(int j = 0; j < n; j++){
            
            if (i == j) continue; // Don't ask if they know themselves.
            
            if (M[i][j] || !M[j][i]) {
                return false;
            }
        }
        return true;
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int possibleCelebrity = 0;
        
        for(int i = 0; i < n; i++){
            if(M[possibleCelebrity][i]){
                possibleCelebrity = i;
            }
        }
        
        if(isCeleb(possibleCelebrity, n, M)) return possibleCelebrity;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends