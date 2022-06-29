//https://leetcode.com/problems/count-sorted-vowel-strings/solution/   -- imp

/*
//brute force
class Solution {
public:
    int countVowelStrings(int n) {
        return count(0,n,1);
    }
    
    int count(int index, int n, int vowels){
        
        if(index == n) return 1;
        
        int result = 0;
        
        for(int i = vowels; i <= 5; i++){
            result += count(1,n,i);
        }
        return result;
    }
};
*/

// ****************DP APPROACH NEEDS*********************


// MOST OPTIMAL APPROACH
/*
https://en.wikipedia.org/wiki/Combination#Number_of_combinations_with_repetition

*/

class Solution {
public:
    int countVowelStrings(int n) {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
