class Solution {
public:
    int tribonacci(int n) {
        
        if(n < 2) return n;
        
        if(n == 2) return 1;
        
        int n0 = 0, n1 = 1, n2 = 1, temp;
        
        for(int i = 3; i <=  n; i++){
            temp = n0 + n1 + n2;
            n0 = n1;
            n1 = n2;
            n2 = temp;
        }
        
        return n2;
    }
};



// int CalculateFibonacci(int n) {
//     if (n < 2) {
//       return n;
//     }
//     int n1 = 0, n2 = 1, temp;
//     for (int i = 2; i <= n; i++) {
//       temp = n1 + n2;
//       n1 = n2;
//       n2 = temp;
//     }
//     return n2;
//   }