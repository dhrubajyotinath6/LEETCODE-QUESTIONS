//https://ibb.co/album/JndHR2

/*
tc - O(n)
sc - O(n)

class Solution {
public:
    int depthFirstSearch(int n, int k, int rootVal) {
        if (n == 1) {
            return rootVal;
        }

        int totalNodes = pow(2, n - 1);

        // Target node will be present in the right half sub-tree of the current root node.
        if (k > (totalNodes / 2)) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current root node.
        else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return depthFirstSearch(n - 1, k, nextRootVal);
        }
    }

    int kthGrammar(int n, int k) {
        return depthFirstSearch(n, k, 0);
    }
};

*/
/*
Algorithm
Find the count of the number of 1 bits in k - 1.
Return 0 if count is even, 1 otherwise.


tc - O(logk)
sc - O(1)
*/
class Solution {
public:
    int kthGrammar(int n, int k) {
        int count = __builtin_popcount(k-1);
        return count % 2 == 0 ? 0 : 1;
    }
};
/*

0   1   1   0   1   0   0   1
0   1   2   3   4   5   6   7  -- index
0   1   1   2   1   2   2   3  -- NO OF 1 BITS IN INDEX

*/