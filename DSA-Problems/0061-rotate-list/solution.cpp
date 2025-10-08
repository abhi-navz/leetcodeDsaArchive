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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;

        int n =0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }

        k = k%n;
        if(k ==0) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        for(int i =0; i<k; i++){
            fast = fast->next;
        }
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;

        temp = newHead;
        while(temp->next){
            temp = temp->next;

        }

        temp->next = head;
        return newHead;
        
    }
};
