/*
https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686316/JavaC%2B%2BPython-Binary-Search

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686237/C%2B%2B-Binary-search



*/

class Solution {

public:
    bool isPoss(vector<int>& bloomDay, int k, int m, int mid){
        
        int adj = 0, bouq = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            
//             if(mid >= bloomDay[i]){
//                 adj++;
//             }else{
//                 adj = 0;
//             }
            
//             if(adj == k){
//                 bouq++;
//                 adj = 0;
//             }
            
            if(mid < bloomDay[i]){
                adj = 0;
            }
            else if(++adj == k){
                adj = 0;
                bouq++;
            }
        }
        
        return bouq >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int ans = -1;
        
//         long long int mul = m*k;
        
//         if(mul > bloomDay.size()) return -1;
        
        auto p=minmax_element(bloomDay.begin(),bloomDay.end());
        
        int low = *p.first, high = *p.second;
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            
            cout << mid << endl;
            
            if(isPoss(bloomDay, k, m, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};