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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1 , -1};

        int k = 2;

        ListNode * prev = head;
        ListNode * curr = head->next;
        vector<int>ans;


        while(curr->next){
            ListNode * next = curr->next;
            if((prev->val < curr->val  && curr->val > next->val) || 
                (prev->val > curr->val && curr->val < next->val)){
                ans.push_back(k);
            }
            
            prev = curr;
            curr = next;
            k++;

        }
        if(ans.size() < 2) return {-1, -1};

        int mini = INT_MAX;
        for(int i = 1 ; i < ans.size() ; i++){
            mini = min(mini , ans[i] - ans[i-1]);            
        }

        int maxi = ans.back() - ans.front();

        return {mini , maxi};


        
    }
};