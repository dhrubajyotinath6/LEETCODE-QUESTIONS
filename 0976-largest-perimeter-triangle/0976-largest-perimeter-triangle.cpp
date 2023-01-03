/*
a, b, c 

a + b > c
b + c > a
c + a > b

but since we are sorting the element

a < b < c

so if a + b > c satifies then it will be a triange
bcoz of sorting other two conditions will always remain true;

*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        
        sort(A.begin(), A.end());
        
        for(int i = A.size()-3; i >= 0; i--){
            if(A[i] + A[i+1] > A[i+2]){
                return A[i] + A[i+1] + A[i+2];
            }
        }
        return 0;
    }
};