class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> freq(n+1,0);
        
        for(auto& num : arr){
            freq[min(num,n)]++;
        }
        
        int ans = 1;
        for(int num = 2; num <= n; num++){
            ans = min(ans + freq[num], num);
        }

        
        return ans;
    }
};