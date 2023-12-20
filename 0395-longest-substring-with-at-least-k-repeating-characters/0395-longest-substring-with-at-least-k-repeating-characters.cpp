class Solution {
    
public:
    int getMaxUniqueLetters(string s){
        bool map[26] = {0};
        int maxUnique = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(map[s[i] - 'a'] == 0){
                maxUnique++;
                map[s[i] - 'a'] = true;
            }
        }
        
        return maxUnique;
    }
    
public:
    int longestSubstring(string s, int k) {
  
        int countMap[26];
        int maxUnique = getMaxUniqueLetters(s);
        
        int result = 0;
        
        for(int currUnique = 1; currUnique <= maxUnique; currUnique++){
            
            memset(countMap, 0, sizeof(countMap));
            int windowStart = 0, unique = 0;
            int i = 0;
            int countAtLeastK = 0;
            
            for(int windowEnd = 0; windowEnd < s.size();){
                
                if(unique <= currUnique){
                    i = s[windowEnd] - 'a';
                    
                    if(countMap[i] == 0) unique++;
                    countMap[i]++;
                    
                    if(countMap[i] == k) countAtLeastK++;
                    windowEnd++;
                }
                else{
                    i = s[windowStart] - 'a';
                    if(countMap[i] == k) countAtLeastK--;
                    countMap[i]--;
                    
                    if(countMap[i] == 0) unique--;
                    windowStart++;
                }
                
                if(unique == currUnique && unique == countAtLeastK){
                    result = max(result, windowEnd - windowStart);
                }
            }
        }
        
        return result;
    }
};