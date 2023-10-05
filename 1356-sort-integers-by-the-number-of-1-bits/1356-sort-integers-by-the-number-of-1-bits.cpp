class Solution {
    
public:    
static int noOf1s(int num){
    int count = 0;
    
    while(num > 0){
        count++;
        num &= (num - 1);
    }
    
    return count;
}
    
public:
   static  bool comparator(int a, int b){
        if(noOf1s(a) == noOf1s(b)){
            return a < b;
        }
        return noOf1s(a) < noOf1s(b);
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), comparator);
        return arr;
    }
};