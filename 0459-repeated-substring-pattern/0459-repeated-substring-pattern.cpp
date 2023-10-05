class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if(t.substr(1, t.size() - 2).find(s) != -1) return true;
        
        return false;
    }
};


/*
Algorithm
1. Create a string variable t and set it to s + s.

2. If the substring formed by removing the first and last character of t contains s, we return true. Otherwise, return false. 

Note in our implementation, the substr function in C++ and the substring method in Java both take two parameters. In both languages, the first parameter is the initial index from which our substring begins, while the second parameter works differently. It is the length of the substring in C++ and the index of the last character in Java.


*/