/*
4 approach

dfs
union
optimized dfs
optimized union

*/

//dfs
class Solution {
    
public:
    // Return true if stone a and b shares row or column
    int shareSameRowOrColumn(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] || a[1] == b[1];
    }
    
public:
    void dfs(vector<vector<int>> &graph, vector<int> &visit, int src){
        
        visit[src] = 1;
        
        for(auto &child : graph[src]){
            // cout << src << " " << child;
            if(visit[child] == 0){
                dfs(graph, visit, child);
            }
        }
    }
    
public:
    int countComponents(int n, vector<vector<int>>& stones) {
        
        if(n == 0) return 0;
        int comp = 0;
        
        vector<int> visit(n, 0);
        vector<vector<int>> graph(n);
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < stones.size(); j++){
                if(shareSameRowOrColumn(stones[i], stones[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            
            if(!visit[i]){
                comp++;
                dfs(graph, visit, i);
            }
        }
        return comp;
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int comp = countComponents(stones.size(), stones);
        cout << comp << endl;
        cout << stones.size() << endl;
        return stones.size() - comp;
    }
};