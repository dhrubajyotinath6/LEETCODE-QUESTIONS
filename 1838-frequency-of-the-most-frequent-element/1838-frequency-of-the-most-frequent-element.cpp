/*
    k = 5

    1   4   8   13
    1   5   13  26  -- prefixSum


*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int windowStart = 0, windowEnd = 0;
        int maxi = 0;
        
        long long windowSum = 0;
        
        for(windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            
            long long target = nums[windowEnd];         
            long long reqdSum = (windowEnd - windowStart + 1)*target;
            
            windowSum += target;
            
            if(reqdSum - windowSum > k){
                windowSum -= nums[windowStart++];
            }
            
            maxi = max(maxi, windowEnd - windowStart + 1);
        }
        
        return maxi;
    }
};