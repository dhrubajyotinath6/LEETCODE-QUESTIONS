class Solution {
public:
    int minSwaps(vector<int>& data) {
        
        int windowSize = 0;
        
        for (int datum : data)
            if (datum == 1) windowSize++;
        
        
        int windowStart = 0, countOnes = 0, maxOnes = 0;
        
        for (int windowEnd = 0; windowEnd < data.size(); windowEnd++) {
            
            countOnes += data[windowEnd];
            
            while(windowEnd - windowStart >= windowSize){
                countOnes -= data[windowStart++];
            }
            
             maxOnes = max(maxOnes, countOnes);
        }
        
       return windowSize - maxOnes;
        
    }
};