//https://leetcode.com/problems/champagne-tower/discuss/1818599/FULL-VISUAL-EXPLANATION-oror-DP-oror-Beginner-Friendly-oror-Easy-and-Simple-oror-C%2B%2B

/*
|__|        i = 0
|__|__|     i = 1
|__|__|__|  i = 2


(x - 1)/2.0 if x > 1

*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<double> currRow(1,poured);
        
        for(int i = 0; i <= query_row; i++){
            
            vector<double> nextRow(currRow.size() + 1, 0);
            
            for(int j = 0; j <= i; j++){
                
                if(currRow[j] > 1){
                    nextRow[j] += (currRow[j] - 1)/2.0;
                    nextRow[j + 1] += (currRow[j] - 1)/2.0;  
                    currRow[j] = 1;
                }
                  
                
                
            }
            
            
          if(i!=query_row) currRow = nextRow;
          
            /*
            if(i == query_row) {
                continue;
            }
            else{
                currRow = nextRow;
            }
            */
            
        }
        
        return currRow[query_glass];
    }
};

/*
Input: poured = 100000009, query_row = 33, query_glass = 17 

we need to calculate till 34 row
so when i = 33, then we are not putting next_row into curr_row

*/
