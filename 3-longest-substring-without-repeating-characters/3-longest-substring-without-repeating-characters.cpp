class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int windowStart = 0, maxLength = 0;
        unordered_map<char, int> mpp;
        
        for(int windowEnd = 0; windowEnd < s.size(); windowEnd++){
            
            char rightChar = s[windowEnd];
            
            //if it is in the mpp
            if(mpp.find(rightChar) != mpp.end()){
                
                windowStart = max(windowStart, mpp[rightChar] + 1);
            }
            
            mpp[rightChar] = windowEnd;
            
            maxLength = max(windowEnd - windowStart + 1, maxLength);
                
        }
        
        return maxLength;
    }
};