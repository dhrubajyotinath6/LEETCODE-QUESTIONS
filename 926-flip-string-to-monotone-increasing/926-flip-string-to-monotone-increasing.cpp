class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int one = 0;
        int flip =0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] =='1')
                one++;
            else
                flip++;
            flip = min(one,flip);
        }
    return flip;
    }
};