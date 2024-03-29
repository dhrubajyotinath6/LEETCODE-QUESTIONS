/*
https://leetcode.com/problems/max-points-on-a-line/discuss/47330/Does-anyone-use-the-idea-of-Hough-Transform-O(N)
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int maxi = 0;
        
        //start
        for(int i = 0; i < n; i++){
            
            int dup = 0;
            map<pair<int,int>,int> slope;
            
            for(int j = i; j < n; j++){
                int dy = points[i][1] - points[j][1];
                int dx = points[i][0] - points[j][0];
                
                if(dy == 0 && dx == 0) dup++;
                
                else{
                    int gg = __gcd(dy,dx);
                    dy /= gg;
                    dx /= gg;
                    slope[{dy,dx}]++;
                }
            }
           maxi = max(maxi,dup);
            
            for(auto it : slope){
                maxi = max(maxi, it.second + dup);
            }
        }
        //end
        
        return maxi;
    }
};