class Solution {
    
public:
    
    struct valueCompare {
        
        char operator()(const pair<int, int> &x, const pair<int, int> &y) {
          return y.second > x.second;
        }
        
    };
    
    
    int minSetSize(vector<int>& arr) {
        
       unordered_map<int,int> mpp;
        
       for(auto i : arr){
           mpp[i]++;
       }
        
       // 
        
       priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> maxHeap;
        
       for(auto x : mpp){
           maxHeap.push(x);
       }
        
       int n = arr.size()/2;
       int size = 0;
        
        
        while(n > 0){
            n -= maxHeap.top().second;
            maxHeap.pop();
            size++;
        }
       
        return size;
        
    }
};