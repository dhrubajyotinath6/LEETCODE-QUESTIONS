class Solution {
    
public:
    void mapCity(vector<vector<string>>& paths, unordered_map<string,string> &mpp){
        
        for(auto& path : paths){
            
            string city1 = path[0];
            string city2 = path[1];
            
            mpp[city1] = city2;
        }
    }

public:
    void findDestination(vector<vector<string>>& paths, unordered_map<string,string> &mpp, string &ans){
        
        for(auto& path : paths){
            
            string city1 = path[0];
            string city2 = path[1];
            
            if(mpp[city1] == ""){
               ans = city1;
               return;
            } 
            if(mpp[city2] == ""){
                ans = city2;
                return;
            } 
        }
    }
    
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string,string> mpp;
        mapCity(paths, mpp);
        
        string ans;
        
        findDestination(paths, mpp, ans);
        
        return ans;
    }
};