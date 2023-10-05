
// 1 2 3 4 5 6 7 8 8 9 9
// 8 8 9 9 1 2 3 4 5 6 7

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        
        for(auto& num : nums){
            if(num == num1) count1++;
            else if(num == num2) count2++;
            else if(count1 == 0){
                num1 = num;
                count1 = 1;
            }else if(count2 == 0){
                num2 = num;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
            
        }
        
        count1 = 0, count2 = 0;
        
        for(auto& num : nums){
            if(num == num1) count1++;
            else if(num == num2) count2++;
        }
        
        int n = nums.size();
        vector<int> ans;
        
        if(count1 > n/3) ans.push_back(num1);
        if(count2 > n/3) ans.push_back(num2);
        
        return ans;
    }
};

