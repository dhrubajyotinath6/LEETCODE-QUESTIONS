/*
https://leetcode.com/problems/count-binary-substrings/discuss/1172569/Short-and-Easy-w-Explanation-and-Comments-or-Keeping-Consecutive-0s-and-1s-Count-or-Beats-100
*/
class Solution {
public:
    int countBinarySubstrings(string &s) {
        
        int cur = 1, prev = 0;
        int ans = 0;
        
        for(int j = 1; j < s.length(); j++){
            
            if(s[j] != s[j-1]){
                ans += min(prev, cur);
                prev = cur;
                cur = 1;
            }
            else{
                cur++;
            }
        }
        ans += min(prev, cur);
        return ans;
    }
};