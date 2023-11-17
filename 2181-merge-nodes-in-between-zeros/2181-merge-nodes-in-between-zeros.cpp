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

//https://leetcode.com/problems/merge-nodes-in-between-zeros/discuss/1784766/JavaPython-3-One-pass-two-pointers-copy-sum-to-0-nodes.
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode *dummy = new ListNode(1), *prev = dummy;
        
        while(head != NULL && head->next != NULL){
            prev->next = head;
            head = head->next;
            
            while(head != NULL && head->val != 0){
                prev->next->val += head->val;
                head = head->next;
            }
            
            prev = prev->next;
        }
        
        prev->next = NULL;
        return dummy->next;
    }
};


/*
   public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode(Integer.MIN_VALUE), prev = dummy;
        while (head != null && head.next != null) {
            prev.next = head; // prev connects next 0 node.
            head = head.next; // head forward to a non-zero node.
            while (head != null && head.val != 0) { // traverse all non-zero nodes between two zero nodes.
                prev.next.val += head.val; // add current value to the previous zero node.
                head = head.next; // forward one step.
            }
            prev = prev.next; // prev point to the summation node (initially 0).
        }
        prev.next = null; // cut off last 0 node.
        return dummy.next;
    }

*/