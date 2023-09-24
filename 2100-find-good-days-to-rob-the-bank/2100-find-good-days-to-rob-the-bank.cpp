class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        int n = security.size();        
        
        vector<int> ans;
        
        if(time == 0){
            for(int i = 0; i < n; i++){
                ans.push_back(i);
            }
            return ans;
        }
        
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        
        /* 
        [5,3,3,3,5,6,2]  //decreasing + equal
         1,2,3,4,1,1,2      
        */
        for(int i = 1; i < n; i++){
            if(security[i-1] >= security[i]) prefix[i] = (prefix[i-1] + 1);
        }
        
        /*
        [5,3,3,3,5,6,2]  // increasing + equal
        [1,4,3,3,2,1,1]
        */
        for(int i = n-2; i >= 0; i--){
            if(security[i] <= security[i+1]) suffix[i] = (suffix[i+1] + 1);
        }
        
        for(int i = time; i < n - time; i++){
           if(prefix[i-1] >= time && suffix[i+1] >= time && security[i-1] >= security[i] && security[i] <= security[i+1]){
                ans.push_back(i);
           }
        }
        
        return ans;
    }
};


/*
[6, 7, 8, 5, 4], time = 0

[0, 1, 2, 3, 4]

*/

/*
n = 7
n - 1 = 5

i = 1

*/