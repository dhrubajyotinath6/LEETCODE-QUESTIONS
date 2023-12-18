class Solution {
    
public:
    vector<int> twoMaxiTwoMini(vector<int> &nums){
        
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        int mini1 = INT_MAX, mini2 = INT_MAX;
        
        for(auto& num : nums){
            
            if(num > maxi1){
                maxi2 = maxi1;
                maxi1 = num;
            }else if(num > maxi2){
                maxi2 = num;
            }
            
            
            if(num < mini1){
                mini2 = mini1;
                mini1 = num;
            }else if(num < mini2){
                mini2 = num;
            }
        }
        
        vector<int> ans {maxi1, maxi2, mini1, mini2};
        return ans;
    }
public:
    int maxProductDifference(vector<int>& nums) {
        
        //constant size vector
        vector<int> ans = twoMaxiTwoMini(nums);
        
        cout << ans[0] << endl;
        cout << ans[1] << endl;
        cout << ans[2] << endl;
        cout << ans[3] << endl;
        
        return ans[0]*ans[1] - ans[2]*ans[3];
    }
};