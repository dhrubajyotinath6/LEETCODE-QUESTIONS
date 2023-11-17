class Solution {
public:
    int minPairSum(vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
        
        int i = 0, j = nums.size()-1;
        int maxi = INT_MIN;
        
        while(i < j){
            int sum = nums[i] + nums[j];
            maxi = max(maxi, sum);
            
            i++, j--;
        }
        
        return maxi;
    }
};


/*
2   3   4   4   5   6


2   3   3   5

*/