
/*
same as coin change 2

difference is:
 In coin change 2 : (1  1   2)  &&  (1   2   1)    &&   (2   1   1)  counted as 1
 
 But here it is counted as 3

*/

//https://leetcode.com/problems/combination-sum-iv/discuss/85036/1ms-Java-DP-Solution-with-Detailed-Explanation

//https://leetcode.com/problems/combination-sum-iv/discuss/1166177/Short-and-Easy-w-Explanation-or-Optimization-from-Brute-Force-to-DP-Solution

class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<uint> comb(target+1);
        comb[0] = 1;
        
        for(int i = 1; i < comb.size(); i++){
            for(int j = 0; j < nums.size(); j++){
                if(i - nums[j] >= 0) comb[i] += comb[i-nums[j]];
            }
        }
        
        return comb[target];
    }
};



// public int combinationSum4(int[] nums, int target) {
//     int[] comb = new int[target + 1];
//     comb[0] = 1;
//     for (int i = 1; i < comb.length; i++) {
//         for (int j = 0; j < nums.length; j++) {
//             if (i - nums[j] >= 0) {
//                 comb[i] += comb[i - nums[j]];
//             }
//         }
//     }
//     return comb[target];
// }