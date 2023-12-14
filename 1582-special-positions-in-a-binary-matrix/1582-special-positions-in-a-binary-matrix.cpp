class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        //3                        4
        int noOfRows = mat.size(), noOfCols = mat[0].size();
        
        vector<int> zerosRows(noOfRows,0),  zerosCols(noOfCols, 0);
        
        for(int i = 0; i < noOfRows; i++){
            for(int j = 0; j < noOfCols; j++){
                
                int isItOne = (mat[i][j] == 1 ? 1:0);
                
                zerosRows[i] += isItOne;
                zerosCols[j] += isItOne;
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < noOfRows; i++){
            for(int j = 0; j < noOfCols; j++){
                
                if(mat[i][j] == 1 && zerosRows[i] == 1 && zerosCols[j] == 1) cnt++;
            }
        }
        
        return cnt;
    }
};