class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<int> st;
        string str = "";
        
        for(int i = 0; i < s.size(); i++){
            
            char ch = s[i];
            
            if(ch == '('){
                
                if(st.size() > 0)   str+=ch;
                st.push(ch);
            }
            else{
                st.pop();
                if(st.size() > 0)   str+=ch;
                // str += ch;
            }
        }
        return str;
    }
};

/*
    if(st.size() > 0)   str+=ch;
    str += ch;


Your input
"(()())(())"

Output
"()())())"

Expected
"()()()"

*/