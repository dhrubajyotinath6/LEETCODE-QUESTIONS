/*
all numbers can be represented as sum of 2 and 3 except 1.

so when freq is 1 return -1;

now we need to find minimum no of rounds.

https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/solution/
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int> freq;
        
        for(auto &task : tasks){
            freq[task]++;
        }
        
        int miniRounds = 0;
        
        for(auto [task, count] : freq){
            
            if(count == 1) return -1;
            
            if(count % 3 == 0){
                miniRounds += count/3;
            }else{
                /*if it is not divided by 3, then 2 possible remainders are there 1 and 2
                
                eg: 7, 8
                
                7 = 7 + 2 + 2
                7/3 = 2 and rem = 1 (3,3,1)->(3,2,2)
                
                8 = 3 + 3 + 2 
                8/3 = 2 and rem 2  (3,3,2)
                
                */
                
                miniRounds += count/3 + 1;
            }
        }
        
        return miniRounds;
    }
};