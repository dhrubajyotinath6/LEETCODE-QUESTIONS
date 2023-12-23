class Solution {
public:
    bool isPathCrossing(string path) {
        
        set<pair<int,int>> st;
        st.insert({0,0});
        
        int x = 0, y = 0;
        
        for(auto& p : path){
             if(p == 'N') y += 1;
             if(p == 'S') y -= 1;
             if(p == 'E') x += 1;
             if(p == 'W') x -= 1;
            
             pair<int,int> point(x, y);
            
            if(st.find(point) != st.end()){
                return true;
            }
            
            st.insert(point);
             
        }
        
        return false;
    }
};
