//https://leetcode.com/problems/binary-subarrays-with-sum/discuss/186683/C%2B%2BJavaPython-Sliding-Window-O(1)-Space

/*
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        
        int prefixSum = 0, cnt = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            prefixSum += nums[i];
            
            cnt += mpp[prefixSum - goal];
            
            mpp[prefixSum]++;
        }
        
        return cnt;
    }
};
*/

class Solution {
    
public:
    int atMost(vector<int> &nums, int goal){
        
        if(goal < 0) return 0;
        
        int windowStart = 0, cnt = 0;
        
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            goal -= nums[windowEnd];
            
            while(goal < 0){
                goal += nums[windowStart++];
            }
            
            cnt += (windowEnd - windowStart + 1);
        }
        
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) { 
       return atMost(nums, goal) - atMost(nums, goal -1);
    }
};