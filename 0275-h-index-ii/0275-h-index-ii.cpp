class Solution {
    
public:
    bool isPossible(vector<int> &citations, int h){
        
        int count = 0;
        
        for(int i = citations.size()-1; i >= 0; i--){
            if(citations[i] >= h){
                count++;
            }
            
            if(count >= h) return true;
        }
        
        return false;
    }
    
public:
    int hIndex(vector<int>& citations) {
        
        int low = 0,  high = citations.size();
        
        int ans = 0;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(isPossible(citations, mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        return ans;
    }
};