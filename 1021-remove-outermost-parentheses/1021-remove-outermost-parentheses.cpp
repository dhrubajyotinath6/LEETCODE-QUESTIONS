//https://leetcode.com/problems/remove-outermost-parentheses/discuss/270022/JavaC%2B%2BPython-Count-Opened-Parenthesis
class Solution {
public:
    string removeOuterParentheses(string s) {
       
        int opened = 0;
        string res;
        
        for(auto &c : s){
            if(c == '(' && opened++ > 0) res += c;
            if(c == ')' && --opened > 0) res += c;
        }
        
        return res;
    }
};