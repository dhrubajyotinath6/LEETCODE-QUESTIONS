class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        vector<int> leftIndex(26, INT_MAX);
        vector<int> rightIndex(26, INT_MIN);
        
        for(int i = 0; i < s.size(); i++){
            int index = s[i] - 'a';
            
            leftIndex[index] = min(leftIndex[index], i);
            rightIndex[index] = max(rightIndex[index], i);
        }
        
        
        
       int ans = -1;
        
       for(int i = 0; i < 26; i++){
           if(leftIndex[i] == INT_MAX || rightIndex[i] == INT_MIN  || leftIndex[i] == rightIndex[i]) continue;
           ans = max(ans, rightIndex[i] - leftIndex[i] - 1);
       }
        
        return ans;
    }
};