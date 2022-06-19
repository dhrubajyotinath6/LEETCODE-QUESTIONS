//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/discuss/294893/JavaC%2B%2BPython-Two-Pointers-and-Stack-Solution
class Solution {
public:
     string removeDuplicates(string s) {
         
        int i = 0, n = s.length();
         
        for (int j = 0; j < n; ++j, ++i) {
            
            s[i] = s[j];
            
            if (i > 0 && s[i - 1] == s[i]){ // count = 2
                i -= 2;
                // cout << i << endl;
            }                
            
        }
         
        return s.substr(0, i);
    }
};

/*
Your input
"leelcode"

stdout
0
-1

Output
"code"

Expected
"code"


*/