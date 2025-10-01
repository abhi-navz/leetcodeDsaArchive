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
    ListNode* middleNode(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* middle = nullptr;

        while(fast!= nullptr && fast->next != nullptr){
            slow =slow->next;
            fast= fast->next->next;

        }

        if(fast == nullptr){
            // even no of nodes
            middle = slow;

        }else{
            // odd case;
            middle = slow;

        }

        return middle;
        
    }
};
