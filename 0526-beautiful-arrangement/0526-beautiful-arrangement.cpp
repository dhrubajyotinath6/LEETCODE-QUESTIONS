/*
https://leetcode.com/problems/beautiful-arrangement/discuss/99727/If-worried-about-Time-Limit-Exceeded...-Contest-Strategy

https://oeis.org/A320843

1, 1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679, 87328, 90478, 435812, 449586, 1939684, 3853278, 8650900, 8840110, 60035322, 80605209, 177211024, 368759752, 1380348224, 1401414640, 8892787136, 9014369784, 33923638848, 59455553072, 126536289568, 207587882368

*/

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