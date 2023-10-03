// https://leetcode.com/problems/number-of-good-pairs/discuss/731561/JavaC%2B%2BPython-Count
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int res = 0;
        unordered_map<int,int> count;
        
        for(int num : nums){
            res += count[num]++;
        }
        return res;
    }
    
};