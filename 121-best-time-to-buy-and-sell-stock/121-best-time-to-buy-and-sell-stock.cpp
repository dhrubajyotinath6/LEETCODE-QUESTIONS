class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxPro = 0, minPrice = INT_MAX;
        
        for(auto price : prices){
            
            minPrice = min(minPrice, price);
            maxPro = max(maxPro, price - minPrice);
        }
        
        return maxPro;
    }
};