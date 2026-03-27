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
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head)
            return nullptr;

        ListNode* curr = head;
        ListNode* unique = nullptr;
        ListNode* ans = nullptr;
        while (curr) {

            int count = 1;

            while (curr && curr->next && curr->val == curr->next->val) {
                count++;
                curr = curr->next;
            }

            if (count == 1) {
                if (!unique) {
                    unique = curr;
                    ans = unique;
                } else {
                    unique->next = curr;
                    unique = curr;
                }
                
            }
            curr = curr->next;
        }
        if (unique) unique->next = nullptr; 
        return ans;
    }
};
