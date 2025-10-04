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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;

        for(int i =0;i<n; i++){
            fast = fast->next;
        }

        // If fast == nullptr, that means we must delete the head
        if (fast == nullptr) {
            ListNode* toDelNode = head;
            head = head->next;
            delete toDelNode;
            return head;
        }

        ListNode* slow = head;
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;

        }

        // now slow is just behind the node to be deleted.
        ListNode* toDelNode = slow->next;
        slow->next = slow->next->next;
        delete toDelNode;
        return head;
 
    }
};
