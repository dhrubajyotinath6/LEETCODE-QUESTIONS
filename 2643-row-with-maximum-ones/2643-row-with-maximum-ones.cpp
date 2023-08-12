class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
       int n = mat.size(), m = mat[0].size();
        
       int maxRow = 0, max1 = 0;
        
       for(int i = 0; i < n; i++){
           
           int count = 0;
           
           for(int j = 0; j < m; j++){
               if(mat[i][j]) count++;
           }
           
           if(count > max1){
                maxRow = i;
                max1 = count; 
           }
       }
        
       return {maxRow,max1};
        
    }
};