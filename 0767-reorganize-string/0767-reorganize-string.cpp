class Solution {
    
public:
    struct valueCompare {
        char operator()(const pair<int, int> &x, const pair<int, int> &y) {
          return y.second > x.second;
        }
   };
    
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> mpp;
        for(auto& ch : s){
            mpp[ch]++;
        }
        
        //(ch,freq)  -> sort them descending order based on freq
        priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

        
        for(auto& entry : mpp){
            maxHeap.push(entry);
        }
        
        string ans = "";
        
        pair<char,int> prev(-1, -1);
        while(!maxHeap.empty()){
            auto node = maxHeap.top();
            maxHeap.pop();
            
            ans += node.first;
            node.second--;
            
            if(prev.second > 0) maxHeap.push(prev);
            
            prev.first = node.first;
            prev.second = node.second;
        }
        
        
        return ans.length() == s.length() ? ans : "";
    }
};