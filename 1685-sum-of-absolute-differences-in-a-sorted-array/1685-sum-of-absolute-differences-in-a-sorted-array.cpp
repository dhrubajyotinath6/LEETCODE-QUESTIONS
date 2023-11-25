/*
0  1 2 3  4
[1,4,6,8,10]

for i = 3,

6*2 - 5   = 7
18  - 6*2 = 5

ans = 13



*/


class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int sum = 0;
        
        for(auto& num : nums){
            sum += num;
        }
        
        int leftSum = 0, rightSum = sum;
        int n = nums.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++){
            
            rightSum -= nums[i];
            
            int noOfLeftDigits = i - 0;
            int noOfRightDigits = n -1 - i ;
            
            int diff1 =  abs(nums[i]*noOfLeftDigits - leftSum);
            int diff2 =  abs(rightSum - nums[i]*noOfRightDigits);
            
            int finalDiff = diff1 + diff2;
            ans.push_back(finalDiff);
                
            leftSum += nums[i];
            
        }
        
     
        return ans;
    }
};