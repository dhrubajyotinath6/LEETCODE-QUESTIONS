class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int maxi = arr[0];
        
        for(auto& num : arr){
            maxi = max(maxi, num);
        }
        
        int curr = arr[0];
        int winStreak = 0;
        
        for(int i = 1; i < arr.size(); i++){
            
            int opponent = arr[i];
            
            if(curr > opponent){
                winStreak++;
            }else{
                curr = opponent;
                winStreak = 1;
            }
            
            if(winStreak == k || curr == maxi){
                return curr;
            }
        }
        
        //never get executed
        return 0;
    }
};