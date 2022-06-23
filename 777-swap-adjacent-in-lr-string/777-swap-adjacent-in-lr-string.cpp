// https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/113787/C%2B%2B-with-explanation-O(n)-14ms

// https://leetcode.com/problems/swap-adjacent-in-lr-string/discuss/1704920/C%2B%2B-one-pass-time%3AO(n)-space%3AO(1)-(with-explanation)



class Solution {
public:
    bool canTransform(string start, string end) {
        
        int i = 0, j = 0;
        
        while(i < start.size() && j < end.size()){
            
            while(start[i] == 'X') i++;
            while(end[j] == 'X') j++;
            
            if(start[i] != end[j]) return false;
            if(start[i]=='R' && i>j) return false;
            if(start[i]=='L' && i<j) return false;
            
            i++; j++;
        }
        
        while(i<start.size() && start[i]=='X') i++;
        while(j<end.size() && end[j]=='X') j++;
        
        return i==j;
    }
};