class Solution {
    
public:
    int compare(int x, int y){
        if(x > y) return 1;
        else if(x < y) return -1;
        return 0;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        int windowStart = 0;
        int ans = 1;
        
        for(int windowEnd = 1; windowEnd < arr.size(); windowEnd++){
            
            int value = compare(arr[windowEnd-1], arr[windowEnd]);
            
            if(value == 0){
                windowStart = windowEnd;
            }
            else if( windowEnd == arr.size()-1 || value * compare(arr[windowEnd], arr[windowEnd+1]) != -1){
                ans = max(ans, windowEnd - windowStart + 1);
                windowStart = windowEnd;
            }
        }
        
        
        return ans;
    }
};