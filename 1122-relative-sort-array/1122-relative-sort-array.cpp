class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> cnt(1001,0);
        
        //Count each number in arr1.
        for(int n : arr1) cnt[n]++;
        
        //Sort the common numbers in both arrays by the order of arr2.
        int i = 0;
        for(int n : arr2) {
            while(cnt[n]-- > 0) {
                arr1[i++] = n;
            }
        }
        
        
        // Sort the remaining numbers(which are present only in arr1) in arr1.
        for(int n = 0; n < cnt.size(); n++) {
            while(cnt[n]-- > 0) {
                arr1[i++] = n;
            }
        }
        return arr1;
    }
};