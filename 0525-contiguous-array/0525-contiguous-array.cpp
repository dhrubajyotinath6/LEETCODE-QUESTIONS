class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        
        int maxi = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            sum = sum + (nums[i] == 1 ? 1 : -1);
            
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i - mpp[sum]);
            }else{
                mpp[sum] = i;
            }
        }
        
        return maxi;
    }
};