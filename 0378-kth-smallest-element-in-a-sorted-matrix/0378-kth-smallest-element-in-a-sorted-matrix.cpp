/*
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
*/

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise


class Solution {
    
public:
    int countsLessThanMid(vector<vector<int>>& matrix, int mid){
        
        int count = 0;
        int m = matrix.size(), n = matrix[0].size(); 
        
        int c = n-1;
        
        for(int r = 0; r < m; r++){
            while(c >= 0 && matrix[r][c] > mid) c--;
            
            count += (c+1);
        }
        
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int low = matrix[0][0],  high = matrix[m-1][n-1];
        int ans = -1;
        
        while(low <= high){
            
            int mid = (low + high) >> 1;
            
            if(countsLessThanMid(matrix, mid)  >= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};











