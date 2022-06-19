/*
https://leetcode.com/problems/integer-to-roman/solution/


https://leetcode.com/problems/integer-to-roman/discuss/1293176/C%2B%2B-easy-solution-O(1)
*/

class Solution {
public:
    string intToRoman(int num) 
    {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        for(int i=0; num != 0; i++)
        {
            while(num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }
        
        return res;
    }
};