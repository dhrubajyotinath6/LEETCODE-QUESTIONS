//https://leetcode.com/problems/search-suggestions-system/discuss/436674/C%2B%2BJavaPython-Sort-and-Binary-Search-the-Prefix
class Solution {
public:
        vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
            
        for(auto &a : A){
            cout << a << "  ";
        }
        
         cout << endl;
            
        auto it = A.begin();
            
        sort(it, A.end());
            
        cout << endl;
            
        for(auto &a : A){
            cout << a << "  ";
        }
        cout << endl;
            
        vector<vector<string>> res;
            
        string cur = "";
            
        for (char c : searchWord) {
            
            cur += c;
            vector<string> suggested;
            
            it = lower_bound(it, A.end(), cur);
            
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            
            res.push_back(suggested);
        }
        return res;
    }
};

/*
Your input
["mobile","mouse","moneypot","monitor","mousepad"]
"mouse"

stdout
mobile  mouse  moneypot  monitor  mousepad  

mobile  moneypot  monitor  mouse  mousepad  

Output
[["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]

Expected
[["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]

----------------------------------------------

Your input
["bags","baggage","banner","box","cloths"] 
"bags"

stdout
bags  baggage  banner  box  cloths  

baggage  bags  banner  box  cloths  

Output
[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

Expected
[["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]


--------------------------------------------

String find is used to find the first occurrence of sub-string in the specified string being called upon. It returns the index of the first occurrence of the substring in the string from given starting position. The default value of starting position is 0.

#include <iostream>

using namespace std;

int main()
{
   string s = "mousepad"; // 0
   
   string s2 = "padmouse"; // 3
   
   string curr = "mouse";
   
   cout << s2.find(curr) << endl;

    return 0;
}


*/