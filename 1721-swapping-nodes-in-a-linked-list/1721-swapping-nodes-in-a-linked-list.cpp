/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
brute force

two pass solution 

*/
//optimise one
/*
1   2   3   4   5   6   7   8   9   10, k = 4
*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* curr = head;       
        
        for(int i = 1; i < k; i++){
            curr = curr->next;
        }
        
        ListNode* node1 = curr;
        ListNode* node2 = head;
        
        while(curr->next != NULL){
            curr = curr->next;
            node2 = node2->next;     
        }
        
        swap(node1->val, node2->val);
        return head;
    }
};