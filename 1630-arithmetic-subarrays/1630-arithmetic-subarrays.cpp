/*
class Solution {
public:
    bool check(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++) {
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        
        return ans;
    }
};

tc - O(m.n.logn)
sc - O(n)

*/

class Solution {
    
public:
    bool check(vector<int> &arr){
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> st;
        
        for(auto& num : arr){
            mini = min(mini, num);
            maxi = max(maxi, num);
            
            st.insert(num);
        }
        
        /*
        2  4  6  8  10
        10 - 2 = 8
        8/4 = 2
        */
        int n = arr.size();
        if((maxi - mini) %  (n-1) != 0) return false;
        
        int diff = (maxi - mini) / (arr.size() - 1);
        int curr = mini + diff;
        
        while(curr < maxi){
            if(st.find(curr) == st.end()) return false;
            
            curr += diff;
        }
        
        return true;
    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        
        for(int i = 0; i < l.size(); i++){
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr));
        }
        
        return ans;
    }
};

/*
tc - O(m*n)
sc - O(n)


n -> nums.length
m -> length of l and r
*/