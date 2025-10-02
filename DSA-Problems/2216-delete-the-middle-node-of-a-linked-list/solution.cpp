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
    ListNode* deleteMiddle(ListNode* head) {

        if(!head || !head->next) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow;
        ListNode* temp = head;
        while(temp->next != middle) temp = temp->next;
        temp->next = temp->next->next;
        middle->next = nullptr;


        return head;
        
    }
};
