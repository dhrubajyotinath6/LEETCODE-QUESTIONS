class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for(auto ch : s){
            
            bool insert = true;
            
            if(!st.empty() && st.top() == ch){
                st.pop();
                insert = false;
            }
            
            if(insert) st.push(ch);
        }
        
        string ans;
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};