class Solution {
    
public:
    void put(vector<vector<int>>& mat, unordered_map<int, vector<int>> &mpp){
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                
                vector<int> indexes {i,j};
                mpp[mat[i][j]] = indexes;
            }
        }
    }
    
public:
    vector<int> find(int val, unordered_map<int, vector<int>> &mpp){
        return mpp[val];
    }
    
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int noOfRows = mat.size(),  noOfCols = mat[0].size();
        vector<int> rows(noOfRows,0),  cols(noOfCols, 0);
        
        unordered_map<int, vector<int>> mpp;
        put(mat, mpp);
        
        for(int i = 0; i < arr.size(); i++){
            
            int val = arr[i];
            
            vector<int> rowCol = find(val, mpp);
            
            rows[rowCol[0]] += 1;
            cols[rowCol[1]] += 1;
            
            if(rows[rowCol[0]] == noOfCols || cols[rowCol[1]] == noOfRows){
                return i;
            }
            
            
        }
        
        return -1;
    }
};