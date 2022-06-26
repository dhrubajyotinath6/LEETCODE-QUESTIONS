/*
https://leetcode.com/problems/count-servers-that-communicate/discuss/436130/C%2B%2B-Simple-Preprocessing

Complexity
Here m is the number of rows and n is the number of columns.
Space: O(m+n).This can be reduced to min(m,n).
Time: O(m*n).

*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        vector<int> rows(grid.size(),0);
        vector<int> cols(grid[0].size(),0);
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[i][j] == 1){
                    rows[i]++, cols[j]++;
                }
                
            }
        }
        
        int result = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)){
                    result++;
                }
            }            
        } 
        
        return result;
    }
};