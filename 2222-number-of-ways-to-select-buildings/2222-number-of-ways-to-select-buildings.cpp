//https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907026/Easy-understanding-C%2B%2B-code-with-comments

//DP ALSO POSSIBLE CHECK THE DISCUSSION SECTION
class Solution {
public:
    long long numberOfWays(string s) {
        
        long long count1=0, count0=0, ans=0;        // a and b are the number of occurances of '1' and '0' after the current building respectively.
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
                count1++;
            else
                count0++;
        }
        
        long long count1SoFar = 0, count0SoFar = 0;             
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='1'){               // Counting the sequences of "010"
                ans+=(count0SoFar*count0);
                count1--;
                count1SoFar++;
            }
            else{                        // Counting the sequences of "101"
                ans+=(count1*count1SoFar);
                count0--;
                count0SoFar++;
            }
        }
        return ans;
    }
};
