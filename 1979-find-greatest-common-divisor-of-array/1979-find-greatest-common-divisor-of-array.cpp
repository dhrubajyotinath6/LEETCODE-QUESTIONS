//https://en.wikipedia.org/wiki/Euclidean_algorithm

//https://www.freecodecamp.org/news/euclidian-gcd-algorithm-greatest-common-divisor/



class Solution {
    
public:
    //freecodecamp
    int _gcd(int a, int b){
        
      int R;
      while ((a % b) > 0)  {
        R = a % b;
        a = b;
        b = R;
     }
      return b;
    }
     
public:
    int findGCD(vector<int>& nums) {
        auto [mn, mx] = minmax_element(begin(nums), end(nums));
        return _gcd(*mx, *mn);
    }
};


/*

    int findGCD(vector<int>& nums) {
        auto [mn, mx] = minmax_element(begin(nums), end(nums));
        return gcd(*mn, *mx);
    }
    
    
    int findGCD(vector<int>& n) {
    return gcd(*min_element(begin(n), end(n)), *max_element(begin(n), end(n)));
}
*/