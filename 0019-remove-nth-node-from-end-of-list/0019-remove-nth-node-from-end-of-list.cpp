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
class Solution { // two pass approach
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
       ListNode dummy(0);
       dummy.next = head;

       ListNode * fast = &dummy;
       ListNode * slow = &dummy;

       for(int i = 0 ; i <= n ; i++){
            fast = fast ->next ;
       }

       while(fast){
        slow = slow->next;
        fast = fast->next;
       }

       slow->next = slow->next->next;

       return dummy.next;
        
    }
};


class Solution1 { // using length approach
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0 ;
        ListNode * tmp = head;

        while(tmp){
            tmp = tmp->next;
            len++;
        }

        if(n == len){
            return head->next;
        }

        tmp = head;
        
        for(int i = 1 ; i < len - n ; i++){
            tmp = tmp ->next;
        }

        tmp->next = tmp->next->next;
        return head;
        
    }
};