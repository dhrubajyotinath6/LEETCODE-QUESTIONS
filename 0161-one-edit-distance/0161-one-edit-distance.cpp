/*
abc , ab
ab  , abc
ab  , ac


abc  , abc -->false

*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        int n = s.length(), m = t.length();
        
        if(abs(n - m) > 1) return false;
        
        int i = 0, j = 0;
        
        while(i < n && j < m && s[i] == t[j]){
            i++;
            j++;
        }
        
        //if we reach end of both strings, it means both strings are same, so straight return false as same strings cannot be one edit distance apart.
        if(i == n && j == m) return false;
        
        /*
        characters are different 
        */
        
        //deletion is possible,   [ab'c'd  , ab'd']
        if(n > m){            
            return s.substr(i+1) == t.substr(j);
        }
        
        //insertion is possible [ab'd',  ab'c'd]
        else if(n < m){
            return s.substr(i) == t.substr(j+1);
        }
        //replace   [ab'c'd,  ab'f'd]
        else{
            return s.substr(i+1) == t.substr(j+1);
        }
        
        //never get executed
        return true;
 
    }
};