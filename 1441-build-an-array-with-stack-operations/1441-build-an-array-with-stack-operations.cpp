class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        
        int i = 1;
        int j = 0;
        
        int limit = target[target.size() - 1];
        
        while(i <= n){
                     
            while(i < target[j]){
                ans.push_back("Push");
                ans.push_back("Pop");
                
                i++;
            }
            
            ans.push_back("Push");
            j++;
            i++;
            
            if(i > limit) break;
            
        }
        
        return ans;
    }
};