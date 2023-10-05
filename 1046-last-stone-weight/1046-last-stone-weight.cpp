class Solution {
public:
    int lastStoneWeight(vector<int>& weights) {
        
    int n = weights.size();
    
    priority_queue<int> pq;
    
    for(int i = 0; i < n; i++){
        
        int x = weights[i];
        
        pq.push(x);
    }
    
    
    while(pq.size() > 1){
        
        int top1 = pq.top();
        pq.pop();
        
        int top2  = pq.top();
        pq.pop();
        
        if(top1 > top2){
            top1 -= top2;
            pq.push(top1);
        }else if(top2 > top1){
            top2 -= top1;
            pq.push(top2);
        }
    }
    
    int ans;
    
    if(pq.empty()){
        ans = 0;
    }else{
        ans = pq.top();
    }
    // cout << pq.size() << endl;
    
    return ans;
    }
};