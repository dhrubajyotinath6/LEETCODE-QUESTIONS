/*
( +-)   (numbers)   (.)     (numbers)             [ (e,E)    (+,-)     (number) ]
(opt)   (opt)       (opt)   ()          (opt)     [ ()       (opt)     ()       ]

                                

*/

class Solution {
public:
    bool isNumber(string s) {
        
        bool seenDigitFirst = false;
        bool seenExp = false;
        bool seenDot = false;
        bool seenDigitSecond = false;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            
            char curr = s[i];
            
            if(curr == '+' || curr == '-'){
                
                if(i == 0) continue;                
                if(i > 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
                
            }else if(isdigit(curr) && seenExp == false){
                    seenDigitFirst = true;
            }else if(curr == '.'){
                    
                if(seenDot == true || seenExp == true) return false;
                seenDot = true;
            }else if( curr == 'e' || curr == 'E'){
                if(seenExp == true || seenDigitFirst == false) return false;
                seenExp = true;
            }else if(isdigit(curr) && seenExp == true){
                seenDigitSecond  = true;
            }
            else{
                return false;
            }
            
            
        }
        
        if(seenExp == true) return seenDigitSecond;
        return seenDigitFirst;
    }
};