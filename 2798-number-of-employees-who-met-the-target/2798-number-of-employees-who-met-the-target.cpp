class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        
        int cnt = 0;
        
        for(auto& h : hours){
            if(h >= target) cnt++;
        }
        
        return cnt;
    }
};