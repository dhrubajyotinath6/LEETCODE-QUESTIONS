//https://leetcode.com/problems/strobogrammatic-number/discuss/67207/C%2B%2B-unordered_map
//https://leetcode.com/problems/strobogrammatic-number/solution/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        unordered_map<char,char> mpp{
                                    {'0', '0'},
                                    {'1', '1'},
                                    {'6', '9'},
                                    {'8', '8'},
                                    {'9', '6'}            
                                    };
        
        int left = 0;
        int right = num.size() - 1;
        
        while(left <= right){
            
            if(mpp.find(num[left]) == mpp.end() || mpp[num[left]] != num[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};