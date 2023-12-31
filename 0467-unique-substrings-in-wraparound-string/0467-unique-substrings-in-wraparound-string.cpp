//https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/95439/Concise-Java-solution-using-DP
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        
        vector<int> freqMap(26,0);
        
        int maxLength = 1;
        
        for(int i = 0; i < s.size(); i++){
            
            if(i > 0 && ( (s[i] - s[i-1]) == 1 || (s[i-1] - s[i]) == 25)){
                maxLength += 1;
            }else{
                maxLength = 1;
            }
            
            int index = s[i] - 'a';
            freqMap[index] = max(freqMap[index], maxLength);
        }
        
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += freqMap[i];
        }
        
        return ans;
    }
};

/*
why ending , not starting point

we can do with start point also but the time complexity can go upto O(N^2)

*/