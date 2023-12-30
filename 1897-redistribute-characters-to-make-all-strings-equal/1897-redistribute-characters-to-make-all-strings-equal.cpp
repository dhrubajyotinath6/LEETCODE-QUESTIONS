class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int n = words.size();        
        vector<int> freqMap(26,0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].size(); j++){
                int index = words[i][j] - 'a';
                freqMap[index]++;
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(freqMap[i] % n != 0) return false;
        }
        
        return true;
    }
};