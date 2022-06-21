class Solution {
public:
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        
        for(int i = 0; i < n; i++){
            
            if(informTime[i] == 0){
                res = max(res, dfs(i,n,manager, informTime));
            }
        }
        return res;
}

int dfs(int i, int n, vector<int>& manager, vector<int>& informTime){
    
    int ans = 0;
    
    if(manager[i] != -1){
        ans += informTime[manager[i]];
        ans += dfs(manager[i], n, manager, informTime);
    }
    return ans;
}
    
};


