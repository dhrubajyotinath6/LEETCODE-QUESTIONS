class Solution {
    
public:
    bool checkSame(char a, char b){
        
        int x = (int)a;
        int y = (int)b;
        
        if(x == y || abs(x - y) == 1) return true;
        return false;        
    }
    
public:
    int removeAlmostEqualCharacters(string word) {
        
        int ans = 0, cnt = 1;
        
        for(int i = 0; i < word.size() - 1; i++){
            
            if(checkSame(word[i], word[i+1])){
                cnt += 1;
            }else{
                ans += cnt/2;
                cnt = 1;
            }
        }
        
        ans += cnt/2;
        
        return ans;
    }
};