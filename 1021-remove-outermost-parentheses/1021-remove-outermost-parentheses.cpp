class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int bal = 0;
        string ans = "";
        
        for(auto& ch : s){
            
            if(ch == '('){
                
                if(bal != 0){
                    ans += ch;
                }
                
            }else{ // ch == ')'
                
                if(bal > 1){
                    ans += ch;
                }
            }
            
            bal += (ch == '(') ? 1:-1;
            
            }
        
        
        return ans;
    }
};