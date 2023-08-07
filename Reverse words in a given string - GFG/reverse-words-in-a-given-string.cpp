//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
       /*
        input   i.like.this.program.very.much
        Output: much.very.program.this.like.i
       */
       
       string ans = "";
       string res = "";
       
       for(int i = 0; i < s.length(); i++){
           if(s[i] == '.'){
               ans = res + ans;
               ans = s[i] + ans;
               res = "";
               
           }else{
               res += s[i];
           }
       }
       
       ans = res + ans;
       return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends