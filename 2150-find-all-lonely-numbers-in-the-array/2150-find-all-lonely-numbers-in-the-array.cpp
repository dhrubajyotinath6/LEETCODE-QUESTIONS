class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        
        unordered_map<int,int> mpp;
        for(auto& num : nums){
            mpp[num]++;
        }
        
        vector<int> res;
        
        for(auto [key, value] : mpp){
            if(value == 1 && mpp.count(key-1) == 0 && mpp.count(key + 1) == 0){
                res.push_back(key);
            }
        }
        
        return res;
    }
};