class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        long long cnt = 0;
        unordered_map<double, long long> mpp;
        
        for(auto& rec : rectangles){
            int width = rec[0];
            int height = rec[1];
            
            double ratio = (double)width/height;
            
            cnt += mpp[ratio];
            mpp[ratio]++;
        }
        
        
        return cnt;
    }
};