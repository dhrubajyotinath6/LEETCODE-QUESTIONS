class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        unordered_set<int> st;
        int cnt = 0;
        
        for(int i = nums.size() - 1; i >= 0; i--){
            
            if(nums[i] <= k){
                st.insert(nums[i]);
                
            }
                  
            cnt++;      
            
            if(st.size() == k) break;
        }
        
        return cnt;
    }
};