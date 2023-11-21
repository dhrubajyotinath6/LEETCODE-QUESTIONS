/*
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

Let's denote x = nums[i] and y = nums[j] and rewrite the formula:

x + rev(y) == y + rev(x)

Now, let's rearrange the formula so that all terms involving x are on one side and all terms involving y are on the other:

x - rev(x) == y - rev(y)

We have simplified the problem. As you can see, for a given num, we are interested in num - rev(num). Let's define a new array arr with the same length as nums where:

arr[i] = nums[i] - rev(nums[i])

Now, the problem becomes "how many pairs in arr are equal?"

*/


class Solution {
    
public:
    int rev(int num){
        int res = 0;
        
        while(num > 0){
            int digit =  num % 10;
            res = (res * 10) + digit;
            num /= 10;
        }
        
        return res;
    }
public:
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++){
            arr[i] = nums[i] - rev(nums[i]);
        }
        
        
        unordered_map<int,int> mpp;
        int ans = 0,  mod = 1e9 + 7;
        
        for(auto& num : arr){
            ans = (ans + mpp[num]) % mod;
            mpp[num]++;
        }
        
        return ans;
    }
};