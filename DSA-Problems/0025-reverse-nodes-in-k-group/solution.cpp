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
    ListNode* revLl(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head) {
            return nullptr;
        }
        if (k == 1) {
            return head;
        }

        ListNode* temp = head;
        int n = 0;
        while (temp) {
            n++;
            temp = temp->next;
        }

        int groups = n / k;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        for (int i = 0; i < groups; i++) {

            ListNode* groupStart = curr;
            ListNode* groupEnd = curr;

            for (int j = 0; j < k - 1; j++) {
                groupEnd = groupEnd->next;
            }

            ListNode* nextGroupStart = groupEnd->next;
            groupEnd->next = nullptr;

            ListNode* newHead = revLl(groupStart);

            ListNode* newTail = groupStart;

            prev->next = newHead;
            newTail->next = nextGroupStart;

            prev = newTail;
            curr = nextGroupStart;
        }

        return dummy.next;
    }
};
