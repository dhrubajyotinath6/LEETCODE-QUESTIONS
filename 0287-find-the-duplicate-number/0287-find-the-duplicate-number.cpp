/*
[1,3,4,2,2]

here n = 4

1,2,3,4  1,3,4,2,2


*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
      int slow = 0, fast = 0;
        
      do{
         slow = nums[slow];
         fast = nums[nums[fast]];
      }while(slow != fast);
        
      slow = 0;
      while(slow != fast){
          slow = nums[slow];
          fast = nums[fast];
      }
          
      
      return slow;  
    }
};