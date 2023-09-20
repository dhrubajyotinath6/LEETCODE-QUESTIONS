
/*

case 1: 
[ (.  .  .  .)  .  .  .  .  .] ,   x = 5
    5                 10
    total sum = 15
 
 length of the subarray (sum = total sum - x) having maximum elements


case 2:
[ .  .  .  .  .  .  (.  .  .)]



case 3:
[(.  .)  .  .  .  .  (.  .  .)]

*/


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = 0;
        for(auto& num : nums){
            sum += num;
        }
        
        if(sum == x) return nums.size();
        if(sum < x) return -1;
        
        sum = sum - x;
        
        int windowStart = 0, n = nums.size(), windowSum = 0;
        
        int ans = 0;
        
        for(int windowEnd = 0; windowEnd < n; windowEnd++){
            
            windowSum += nums[windowEnd];
            
            while(windowSum > sum){
                windowSum -= nums[windowStart++]; 
            }
            
            if(windowSum == sum) ans = max(ans, windowEnd - windowStart + 1);
            
        }
        
        if(ans == 0) return -1;
        
        return n - ans;
    }
};