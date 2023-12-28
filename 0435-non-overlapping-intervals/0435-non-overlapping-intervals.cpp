//https://leetcode.com/problems/non-overlapping-intervals/discuss/792726/C%2B%2B-Simple-O(NlogN)-solution-with-explanation

//https://leetcode.com/problems/non-overlapping-intervals/discuss/1157602/Easy-C%2B%2B-solution-with-drawing

/*
we have to sort based on end point:

why not start point??
ANS : suppose you have cases like : (1,8), (2,3), (3,4), (5,9)
if you sort in the basis of start points you will end up considering (1,8) and deleting rest which collide with (1,8).
For a greedy approach you will want the point with lower end point to be considered.


             -------------
Case 1:-
------------------   -----------------
|   Interval 1   |   |   Interval 2  |
------------------   -----------------

Case 2:-
------------------
|   Interval 1   |
------------------
           ------------------
           |    Interval 2  |
           ------------------

Case 3:-
 --------------------
 |    Interval 1    |
 --------------------
    --------------
    | Interval 2 |
    --------------

*/

class Solution {
    
public:
    static bool comp(vector<int> a, vector<int> b){
        return b[1] > a[1]; // sort based on end points
    }
        
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size() <= 1) return 0;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int limit = intervals[0][1];
        int ans = 0;
        
        for(int i = 1; i < intervals.size(); i++){
            
            if(limit > intervals[i][0]){
                ans += 1;
            }else{
                limit = intervals[i][1];
            }
        }
        
        return ans;
        
    }
};