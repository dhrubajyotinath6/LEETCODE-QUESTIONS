class Solution {
    
public:
    static bool comp(vector<int> a, vector<int> b){
        return b[1] > a[1];
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