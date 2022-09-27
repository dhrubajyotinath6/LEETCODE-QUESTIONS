//https://leetcode.com/problems/pascals-triangle-ii/solution/ --VERY IMP


//APPROACH 1
/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> curr, prev = {1};
        
        for(int i = 1; i <= rowIndex; i++){
            
            curr.assign(i+1,1);
            
            for(int j = 1; j < i; j++){
                curr[j] = prev[j-1] + prev[j];
            }
            
            prev = move(curr);  //This is O(1)
        }
        
        return prev;
    }
};

TC -> O(k^2)
SC -> o(2k)
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans = vector<int>(rowIndex + 1, 1);
        
        if(rowIndex == 0) return ans;
        
        for(int i = 1; i <= rowIndex; i++){
            //exclude last nd first in that row
            for(int j = i-1; j > 0; j--){
                ans[j] += ans[j-1];    // ans[j] = ans[j-1] + ans[j]
            }
        }
       
        return ans;
    }
};