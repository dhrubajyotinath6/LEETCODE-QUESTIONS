//brute force approch
/*
class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};


*/

/*
https://leetcode.com/problems/wiggle-sort/solution/
*/
class Solution {
    
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void wiggleSort(vector<int>& nums) {
        
        for(int i = 0; i < nums.size() - 1; i++){
            if( ((i%2 == 0) && nums[i] > nums[i+1]) ||  ((i % 2 == 1) && nums[i] < nums[i + 1])){
                swap(nums, i, i+1);
            }
        }
    }
};



















