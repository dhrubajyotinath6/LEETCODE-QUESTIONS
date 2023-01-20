class Solution {
    
public:
    void dfs(vector<vector<int>> &res,  vector<int> &seq, vector<int>& nums, int index){
        
        if(seq.size() >= 2){
            res.push_back(seq);
            
        }
        
        unordered_set<int> seen;
        for(int i = index; i < nums.size(); i++){
            
            // if(i > index && nums[i-1] == nums[i]) continue;
            
            if((seq.empty() || seq.back() <= nums[i]) && seen.find(nums[i]) == seen.end()){
                                
                seq.push_back(nums[i]);
                seen.insert(nums[i]);
                dfs(res, seq, nums, i + 1);
                seq.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> suq;
        
        dfs(res, suq, nums, 0);
        return res;
    }
};