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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev  = NULL;
        ListNode * curr = head;
        
        while(curr){
            ListNode * next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

     return prev;            
     }

    void reorderList(ListNode* head) {
        
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next;
        }

        ListNode * mid = slow->next;
        ListNode * second = reverseList(mid);
        slow->next = NULL;
        ListNode * first = head;
        

        while(second){
            ListNode * fnext = first->next;
            ListNode * snext = second->next;

            first ->next = second;
            second->next = fnext;
            
            first = fnext;
            second = snext;
        }
    }
};
