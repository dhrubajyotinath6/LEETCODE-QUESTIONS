//acyclic graph  -- no cycle -- very very imp

//https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118691/C%2B%2BPython-Backtracking

//https://leetcode.com/problems/all-paths-from-source-to-target/discuss/986429/Python-Iterative-DFS-with-detailed-time-complexity-and-visuals

/*
class Solution {
    
public:
    void dfs(vector<vector<int>> graph, vector<vector<int>> &paths, vector<int> &path, int curr){
        path.push_back(curr);
        
        if(curr == graph.size() - 1) paths.push_back(path);
        else{
            
            for(auto& it : graph[curr])
                dfs(graph, paths, path, it);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        
        dfs(graph, paths, path, 0);
        return paths;
    }
};
*/

class Solution {
    
public:
    void dfs(vector<vector<int>> graph, vector<vector<int>> &paths, vector<int> &path, int curr){
        path.push_back(curr);
        
        if(curr == graph.size() - 1) paths.push_back(path);
        else{
            
            for(auto& it : graph[curr])
                dfs(graph, paths, path, it);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        
        dfs(graph, paths, path, 0);
        return paths;
    }
};



