class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        
        for(auto& num : nums){
            
            if(num == 0) count++;
            else{
                ans += (count * (count+1))/2;
                count = 0;
            }
        }
        
        ans += (count * (count+1))/2;
        return ans;
    }
};