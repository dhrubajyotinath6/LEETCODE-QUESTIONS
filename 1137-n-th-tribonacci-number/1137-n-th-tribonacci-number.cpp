class Solution {
public:
    int tribonacci(int n) {
        
        if(n < 2) return n;
        
        if(n == 2) return 1;
        
        int n1 = 0, n2 = 1, n3 = 1, temp;
        
        for(int i = 4; i <=  n + 1; i++){
            temp = n1 + n2 + n3;
            n1 = n2;
            n2 = n3;
            n3 = temp;
        }
        
        return n3;
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