class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        //3                      4
        int rows = grid.size(),  cols = grid[0].size();
        
        vector<int> oneRow(rows, 0),  oneCol(cols,0);
    
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                int val = (grid[i][j] == 1 ? 1:0);
                
                oneRow[i] += val;
                oneCol[j] += val;
                
            }
        }
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                int ones = oneRow[i] + oneCol[j];
                int zeros = (cols - oneRow[i]) + (rows - oneCol[j]);
                
                int diff = ones - zeros;
                grid[i][j] = diff;
                
            }
        }
        
        return grid;
    }
};