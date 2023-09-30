//https://leetcode.com/problems/132-pattern/solution/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n < 3) return false;
        
        stack<int> st;
        vector<int>minArray(n);
        
        minArray[0] = nums[0];
        
        for(int i = 1; i < n; i++){
            minArray[i] = min(minArray[i-1], nums[i]);
        }
        
        for(int j = n - 1; j > 0; j--){
            
            if(nums[j] <= minArray[j]) continue;
            
            while(st.empty() == false && st.top() <= minArray[j]) st.pop();
            
            if(st.empty() == false && st.top() < nums[j]) return true;
            
            st.push(nums[j]);
        }
        return false;
    }
};