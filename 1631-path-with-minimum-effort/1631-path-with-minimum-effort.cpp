class Solution {
    
public:
    bool isValidCell(int i, int j, int row, int col){
        return i >= 0 && i <= row - 1 && j >= 0 && j <= col - 1;
    }
  
public:
    bool dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>> &vis, int row, int col, int mid, vector<vector<int>> &dir){     
        
        if(i == row - 1 && j == col - 1) return true;
        
        vis[i][j] = true;
        
        for(auto &direction : dir){
            int adjI = i + direction[0];
            int adjJ = j + direction[1];
            
            if(isValidCell(adjI, adjJ, row, col) && !vis[adjI][adjJ]){
                int currDiff = abs(heights[i][j] - heights[adjI][adjJ]);
                
                if(currDiff <= mid){
                    if(dfs(adjI, adjJ, heights, vis, row, col, mid, dir)) return true;
                }
            }
        }
        
        return false;
    }
    
public:
    bool possible(vector<vector<int>>& heights, int mid){
        
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>> vis(row, vector<int>(col, 0));
        vector<vector<int>> dir {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        return dfs(0, 0, heights, vis, row, col, mid, dir);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int left = 0, right = 1e6;
        
        int ans = 1e6;
        
        while(left <= right){
            int mid = (left + right) >> 1;
            
            if(possible(heights, mid)){
                ans = mid;
                right =  mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
