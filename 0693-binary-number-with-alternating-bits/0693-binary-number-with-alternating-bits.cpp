//https://leetcode.com/problems/binary-number-with-alternating-bits/solution/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int curr = n%2;
        n /= 2;
        
        while(n > 0){
            if(curr == n%2) return false;
            curr = n%2;
            n /=2;
        }

        return true;
    }
};