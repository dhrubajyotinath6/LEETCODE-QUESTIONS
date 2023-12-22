/*
tc - O(n)
sc - O(n)

class Solution {
public:
    int maxScore(string s) {
        
        int ans = 0;
        int n = s.size();
        
        
       // 0   1   1   1   0   1
       //4   4   3   2   1   1 --suffix
        
        
        vector<int> suffix(n);
        suffix[n-1] = s[n-1] - '0';
        
        for(int i = n-2; i >= 0; i--){
            char ch = s[i];
            int x = ch - '0';
            
            suffix[i] += (x + suffix[i+1]);
            
        }
        
        int zeros = 0;
        
        for(int i = 0; i <= n-2; i++){
            
            char ch = s[i];
            int x = ch - '0';
            
            if(x == 0) zeros++;
           
            ans = max(ans, zeros + suffix[i+1]);
            
            
            
        }
        
        return ans;
    }
};
*/

/*
tc - O(n)  -- 2 pass
sc - O(1)

class Solution {
public:
    int maxScore(string s) {
        int ones = count(s.begin(), s.end(), '1');
        
        int ans = 0;
        int zeros = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones--;
            } else {
                zeros++;
            }
            
            ans = max(ans, zeros + ones);
        }
        
        return ans;
    }
};
*/

/*
score = Zeros(left) + Ones(right);

Ones(right) = Ones(Total) - Ones(Left);

score = Zeros(left) + Ones(Total) - Ones(Left);
      = Zeros(left) - Ones(Left) + Ones(Total);
      = best + Ones(Total)
      
Here Ones(Total) is constant

*/

class Solution {
public:
    int maxScore(string s) {
        
        int ones = 0, zeros = 0, best = INT_MIN;// best = 0 will not work see s = "1111"
        
        for(int i = 0; i <= s.size() - 2; i++){
            if(s[i] == '1') ones++;
            else zeros++;
            
            best = max(best, zeros - ones);
        }
        
        if(s[s.size() - 1] == '1') ones++;
        
        return best + ones;
    }
};