class Solution {
    
public:
    struct valueCompare {
        bool operator()(const pair<int, pair<int, int>> &x,const pair<int, pair<int, int>> &y) {
        return x.first > y.first;
    }
  };
    
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,valueCompare> minHeap;
        
        int maxi = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(!nums[i].empty()){
                             //           number , (arrayIndex, index Of the number In That Array)
                minHeap.push(make_pair(nums[i][0], make_pair(i,0)));
                maxi = max(maxi, nums[i][0]);
            }
        }
        
        int rangeStart = 0, rangeEnd = INT_MAX;
        
        while(minHeap.size() == nums.size()){
            auto node = minHeap.top();
            minHeap.pop();
            
            
            if(rangeEnd - rangeStart > maxi - node.first){
                rangeStart = node.first;
                rangeEnd = maxi;
            }
            
            int arrayIndex = node.second.first;  // 0
            int indexOfthenumber = node.second.second; // 4
            
            /*
            (26, (0, 4))
            [4,10,15,24,26]
            size = 5, 
            */            
            
            if(nums[arrayIndex].size() > indexOfthenumber + 1){
                node.first = nums[arrayIndex][indexOfthenumber + 1];
                node.second.first = arrayIndex;
                node.second.second = indexOfthenumber + 1;
                
                maxi = max(maxi, node.first);
                minHeap.push(node);
            }
        }
        
        vector<int> ans {rangeStart, rangeEnd};
        return ans;
    }
};