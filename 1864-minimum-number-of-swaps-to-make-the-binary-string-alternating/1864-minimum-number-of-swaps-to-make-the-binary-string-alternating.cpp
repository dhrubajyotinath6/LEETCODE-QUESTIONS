//https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/discuss/1211118/JavaPython-Count-wrong-positions-O(N)-Easy-to-understand


class Solution {
    
    
    /*
    start = 1 - start;
    
    */
    
public:
    int countSwaps(string s, char start){
        
        int  wrongPos = 0;
        
        for(auto& ch : s){
            
            if(ch != start) wrongPos++;
    
            //cout << start << endl;
            int i = start - '0';
            i = 1 - i;
            start = '0' + i;           
        }
        
        return wrongPos/2;
    }
public:
    int minSwaps(string s) {
        
      int zero = 0, one = 0;
        
      for(auto& ch : s){
            if(ch == '0') zero++;
            else one++;
      }
        
      if(abs(zero - one) > 1) return -1;
      
      else if(zero > one) return countSwaps(s, '0');
      
      else if(one > zero) return countSwaps(s, '1');
        
      return min(countSwaps(s, '0'), countSwaps(s, '1'));
    }
};


