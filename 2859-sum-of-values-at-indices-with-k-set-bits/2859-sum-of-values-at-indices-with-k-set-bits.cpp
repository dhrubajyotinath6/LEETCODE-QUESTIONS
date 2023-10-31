//https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/discuss/4063345/Hacker's-Delight

/*
class Solution {
    
public:    
    int bits(int i){
        int cnt = 0;
        
        while(i){
            cnt += i & 1;
            i >>= 1;
        }
        
        return cnt;
    }
    
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(k == bits(i)) sum += nums[i];
        }
        
       return sum;
        
    }
};

*/

//The getNextSamePopcount function (taken from the Hacker's Delight book) returns the next bigger number with the same number of bits set.






class Solution {
    
public:    
 int getNextSamePopcount(int a) {
    if (a == 0)
        return INT_MAX;
  int c = (a & -a), r = a + c;
  return ((((r ^ a) >> 2) / c) | r);
}
    
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for (int i = (1 << k) - 1; i < nums.size(); i = getNextSamePopcount(i))
            res += nums[i];
        return res;
    }
        
    
};

/*
k = 1,    start = 1 (1)
k = 2,    start = 3 (11)
k = 3,    start = 7 (111) -> 7 = 8 - 1 => (1 << k) - 1

*/

