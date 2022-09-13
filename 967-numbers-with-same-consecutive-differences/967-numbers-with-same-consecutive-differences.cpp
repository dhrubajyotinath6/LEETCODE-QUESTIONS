class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> curr1 = {1,2,3,4,5,6,7,8,9};
        
        for(int i = 2; i <= n; i++){
            
            vector<int> curr2;
            
            for(int x : curr1){          
            
            int y = x % 10;
            
            if(y + k < 10) curr2.push_back(x*10 + (y + k));
            if(y - k >= 0 && k > 0) curr2.push_back(x*10 + (y-k));
        }
        
            curr1 = curr2;
        }
        
        return curr1;
        
    }
};