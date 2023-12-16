class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        set<string> st;
        vector<string> ans;
        
        set<string> st2;
        
        int i = 0; 
        
        for(int i = 0; i + 9 <= s.size(); i++){
            
            string subStr = s.substr(i,10);
            
            //already the string is there and we hv not included it in the ans
            if(st.find(subStr) != st.end() && st2.find(subStr) == st2.end()){
                st2.insert(subStr);
                ans.push_back(subStr);
            }else{
                st.insert(subStr);
            }
        }
        
        return ans;
    }
};