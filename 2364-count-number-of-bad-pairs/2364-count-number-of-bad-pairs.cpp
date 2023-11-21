/*
https://leetcode.com/problems/count-number-of-bad-pairs/discuss/2388183/n*(n-1)2-Valid-oror-(C%2B%2BJava)

Trick to this problem:
Total= Valid + Invalid
Invalid = Total- Valid

The real Equation: ( j - i ) != ( A[j] - A[i] )
The simple and more intuitive form of above equation: ( j - A[j] ) != ( i - A[i] )


invalid :: ( j - A[j] ) != ( i - A[i] )
valid   :: ( j - A[j] )  = ( i - A[i] )  -- count this 

*/


/*
O(n^2)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       
        long long cnt = 0;
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(j - i != nums[j] - nums[i]) cnt++;
            }
        }
        
        return cnt;
    }
};
*/


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       
        long long cnt = 0;
        int n = nums.size();
        
        unordered_map<int, long long> mpp;
        
        for(int i = 0; i < n; i++){
            
            int diff = i - nums[i];
            cnt += mpp[diff];
            
            mpp[diff]++;
            
        }
        
        return  1L*n*(n-1)/2 - cnt;;
    }
};