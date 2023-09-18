class myComparator{    
public:
    //[row, soldier]
    int operator()(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.second == p2.second){
            return p1.first > p2.first;
        }
        return p1.second > p2.second;
    }
};
  

class Solution {    

public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComparator> pq;
        
        int n = mat.size(),  m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            
            int count = 0 , j = 0;
            
            while(j < m && mat[i][j] != 0 ){
                count++;
                j++;
            }
            
            pq.push({i,count});
        }
        
        
        vector<int> ans;
        
        for(int i = 0; i < k ; i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};


