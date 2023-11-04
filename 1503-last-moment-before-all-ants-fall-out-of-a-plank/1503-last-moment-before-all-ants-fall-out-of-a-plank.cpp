class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int maxi = 0;
        
        for(auto& x : left) maxi = max(maxi, x);
        
        for(auto& x : right) maxi = max(maxi, n - x);
        
        return maxi;
        
    }
};