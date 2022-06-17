/*
https://leetcode.com/problems/count-binary-substrings/discuss/1172569/Short-and-Easy-w-Explanation-and-Comments-or-Keeping-Consecutive-0s-and-1s-Count-or-Beats-100

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
*/
class Solution {
public:
    
int countBinarySubstrings(string& s) {
    
  // we start from first character - so curConsecutive = 1
  int curConsecutive = 1, prevConsecutive = 0, ans = 0;
    
  for(int i = 1; i < size(s); i++) {
      
  	if(s[i] != s[i - 1]){ // whenever current & previous don't match
        
  		ans += min(prevConsecutive, curConsecutive), // number of substring formed is minimum of cur & prev count
  		prevConsecutive = curConsecutive,            // previous consecutive streak will become current consecutive and,
  		curConsecutive = 1;                          // current streak will be resetted
    }
  	else {
        curConsecutive++; 
    }
  		
  }
  // required to include count from last two groups of consecutive characters.
  ans += min(prevConsecutive, curConsecutive); 
    
  return ans;
}
};