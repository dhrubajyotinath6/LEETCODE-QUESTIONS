class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //maxHeap
        priority_queue<int> pq;
        
        int m = matrix.size(),  n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pq.push(matrix[i][j]);
                
                if(pq.size() > k) pq.pop();
            }
        }
        
        return pq.top();
    }
};