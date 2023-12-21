//https://leetcode.com/problems/count-tested-devices-after-test-operations/discuss/4384489/JavaC%2B%2BPython-Easy-and-Concise
/*
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        
        int cnt = 0;
        
        for(int i = 0; i < batteryPercentages.size(); i++){
            
            if(batteryPercentages[i] > 0){
                cnt++;
                
                for(int j = i + 1; j < batteryPercentages.size(); j++){
                    batteryPercentages[j]--;
                }
            }
        }
        
        return cnt;
    }
};
*/

/*
arr[i] - noOfTimeTesting > 0
arr[i] > noOfTimeTesting

*/

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        
        int k = 0;
        
        for(auto& a : batteryPercentages){
            if(a > k){
                k++;
            }
        }
        
        return k;
    }
};