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
    pair<ListNode*, ListNode*> reverseK(ListNode* head, int k) {

        // if k =0;
        if (k == 0)
            return {head, nullptr};

        // checking if k nodes are present
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp)
                return {head, nullptr}; // not enough noded no reversal
            temp = temp->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        return {prev, curr};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);

        ListNode* curr = head;
        ListNode* prevGroupTail = &dummy;

        ListNode* ans = nullptr;

        while (curr) {
            auto [newHead, nextGroupHead] = reverseK(curr, k);
            if (!ans)
                ans = newHead;
            if (newHead == curr && !nextGroupHead){ // less than k nodes left;
                prevGroupTail->next = curr;
                break;
            }
                
           

            // connectiong prev grouptail to this reversed group head

            prevGroupTail->next = newHead;
            prevGroupTail = curr; // new tail is the old head;

            curr = nextGroupHead;
        }
        return ans;
    }
};
