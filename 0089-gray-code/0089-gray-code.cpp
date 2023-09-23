//n = 3 bit numbers is: [000, 001, 011, 010, 110, 111, 101, 100]
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        
        int length = 1 << n; // if n = 3, length = 1 << 3 [100 ie 8]
        for(int i = 0; i < length; i++){
            int num = i ^ (i >> 1);
            result.push_back(num);
        }
        
        return result;
    }
};


/*


*/