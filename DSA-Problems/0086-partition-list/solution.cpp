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
    ListNode* partition(ListNode* head, int x) {

        if (head == nullptr)
            return head;

        ListNode* smallHead = nullptr;
        ListNode* smallTail = nullptr;

        ListNode* equalHead = nullptr;
        ListNode* equalTail = nullptr;

        ListNode* temp = head;

        while (temp) {

            if (temp->val < x) {
                ListNode* n1 = new ListNode(temp->val);
                if (!smallHead) {
                    smallHead = smallTail = n1;
                } else {
                    smallTail->next = n1;
                    smallTail = n1;
                }

            } else {
                ListNode* n2 = new ListNode(temp->val);
                if (!equalHead) {
                    equalHead = equalTail = n2;
                } else {
                    equalTail->next = n2;
                    equalTail = n2;
                }
            }

            temp = temp->next;
        }

        // merging the lists now

        ListNode* newHead = nullptr;

        if (smallHead) {
            newHead = smallHead;
            if (equalHead) {
                smallTail->next = equalHead;
            }

        } else {
            newHead = equalHead;
        }

        return newHead;
    }
};
