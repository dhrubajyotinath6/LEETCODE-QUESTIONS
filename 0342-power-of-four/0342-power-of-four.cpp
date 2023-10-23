/*
https://leetcode.com/problems/power-of-four/discuss/80455/One-of-my-favorite-tricks
https://leetcode.com/problems/power-of-four/discuss/80460/1-line-C%2B%2B-solution-without-confusing-bit-manipulations
https://leetcode.com/problems/power-of-four/discuss/80456/O(1)-one-line-solution-without-loops
*/
// class Solution {
// public:
//     bool isPowerOfFour(int num) {
        
//    // if(num == 1) return true;
       
//     return  (num > 0 && (num & 1) == 0 && (num - 1) % 3 == 0);  -->check 10
        
//     //for num & 1 check https://stackoverflow.com/questions/14905643/what-does-this-boolean-number-1-0-mean
//     }
// };

class Solution {
public:
    bool isPowerOfFour(int num) {       
       
    return  (num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0);
    
        //https://tianrunhe.wordpress.com/2012/03/09/explain-n-n-1-0/ (num & (num - 1)) == 0
    
    }
};