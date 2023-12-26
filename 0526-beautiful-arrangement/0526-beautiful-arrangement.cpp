/*
TLE when n = 11

class Solution {
    
public:    
    bool check(vector<int> nums){
        int i = 0;
            
        for(i = 0; i < nums.size(); i++){
            if(nums[i] % (i+1) != 0 && (i+1) % nums[i] != 0) return false;
        }
            
        return true;
    }
    
public:
    void recurPermute(int index, vector<int> &nums, int &cnt) {
        //base case
        if(index == nums.size()) {  
            if(check(nums)){
                cnt += 1;
            }             
            return; 
        }
        
        for(int i = index;i<nums.size();i++) {
            swap(nums[index], nums[i]); 
            recurPermute(index+1, nums, cnt); 
            swap(nums[index], nums[i]); 
        }
        
    }

public:
    int countArrangement(int n) {
        
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = i + 1;
        }
        
        int cnt = 0;
        recurPermute(0, nums, cnt);
        return cnt;
    }
};
*/


class Solution {
    
public:
    void recurPermute(int index, vector<int> &nums, int &cnt) {
        //base case
        if(index == nums.size()) {  
            cnt += 1;           
            return; 
        }
        
        for(int i = index;i<nums.size();i++) {
            swap(nums[index], nums[i]); 
            
            if(nums[index] % (index + 1) == 0 || (index + 1) % nums[index] == 0){
                 recurPermute(index+1, nums, cnt); 
            }           
            swap(nums[index], nums[i]); 
        }
        
    }

public:
    int countArrangement(int n) {
        
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = i + 1;
        }
        
        int cnt = 0;
        recurPermute(0, nums, cnt);
        return cnt;
    }
};