class Solution {
    
public:
    int startWithZeroOrOne(string s, int start){
        
        int cnt = 0;
        
        int first = s[0] - '0';
        if(first != start) cnt += 1;
        
        for(int i = 1; i < s.size(); i++){
            
            int curr = s[i] - '0';
            
            //means alternating
            if(abs(start - curr) == 1){
                start = curr;
            }else{
                cnt++;
                start = (curr == 0 ? 1 : 0);
            }
        }
        
        return cnt;
    }
    
    
public:
    int minOperations(string s) {
        
          int ans = min(startWithZeroOrOne(s,1), startWithZeroOrOne(s,0));
          return ans;
    }
};