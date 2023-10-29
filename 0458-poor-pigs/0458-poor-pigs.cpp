//https://leetcode.com/problems/poor-pigs/discuss/94266/Another-explanation-and-solution

//https://leetcode.com/problems/poor-pigs/discuss/2385451/C%2B%2B-oror-Detail-Explanation-oror-1-Line-Codeoror-100-Fast

//https://leetcode.com/problems/poor-pigs/discuss/94273/Solution-with-detailed-explanation

//https://leetcode.com/problems/poor-pigs/discuss/94305/1-line-solution-with-detailed-problem-clarification-and-math-proof-(please-read-if-you-really-want-to-know-what-this-problem-means)

/*

CAN BE SOLVE IN LOG ALSO (USING MATHS)
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        int pigs = 0;
        
        while (pow((minutesToTest / minutesToDie + 1), pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};

    // pigs = 0
    // while (minutesToTest / minutesToDie + 1) ** pigs < buckets:
    //     pigs += 1
    // return pigs
