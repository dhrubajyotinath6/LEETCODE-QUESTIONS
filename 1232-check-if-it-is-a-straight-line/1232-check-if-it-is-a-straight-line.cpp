//coordinates[i] = [x, y]
/*
2/3      2/3        4/6   --> same slope 

[ ]       [ ]    [ ]    [ ]     [ ] 

*/
class Solution {
    
public:
    int getDiffY(vector<int> &a, vector<int> &b){
        return  b[1] - a[1];
    }
    
    int getDiffX(vector<int> &a, vector<int> &b){
        return b[0] - a[0];
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int deltaY = getDiffY(coordinates[1], coordinates[0]);
        int deltaX = getDiffX(coordinates[1], coordinates[0]);
        
        for(int i = 2; i < coordinates.size(); i++){
            
            if(deltaY * getDiffX(coordinates[i], coordinates[0]) !=  deltaX*getDiffY(coordinates[i], coordinates[0])){ 
                return false;
            }
               
        }   
        
        return true;
    }
};