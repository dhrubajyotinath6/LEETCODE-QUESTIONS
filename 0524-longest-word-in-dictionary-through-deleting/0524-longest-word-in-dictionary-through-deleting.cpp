class Solution {
    
public:
    bool isPossible(string str, string s){
        
        int i = 0, j = 0;
        
        while(i < s.size()){
            if(s[i] == str[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return j == str.size();
    }
    
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        
        string ans = "";
        
        for(auto& str : dictionary){
            
            if(isPossible(str, s)){
                if(ans.size() == 0 || str.size() > ans.size()) ans = str;
                else if(ans.size() == str.size()) ans = min(ans,str); 
            }
            
        }
        
        return ans;
    }
};