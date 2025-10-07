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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return nullptr;
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        int carry = 0;

        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* tl = new ListNode(t1->val + t2->val);
        if (tl->val < 10) {
            carry = 0;
        } else {
            tl->val = (tl->val) % 10;
            carry = 1;
        }
        ListNode* ans = tl;
        t1 = t1->next;
        t2 = t2->next;

        while (t1 && t2) {
            tl->next = new ListNode(t1->val + t2->val + carry);
            tl = tl->next;
            if (tl->val < 10) {
                carry = 0;
            } else {
                tl->val = (tl->val) % 10;
                carry = 1;
            }

            t1 = t1->next;
            t2 = t2->next;
        }

        if (t1 != nullptr) {
            while (t1) {
                tl->next = new ListNode(t1->val + carry);
                tl = tl->next;
                if (tl->val < 10) {
                    carry = 0;
                } else {
                    tl->val = (tl->val) % 10;
                    carry = 1;
                }
                t1 = t1->next;
            }
        }

        if (t2 != nullptr) {
            while (t2) {
                tl->next = new ListNode(t2->val + carry);
                tl = tl->next;
                if (tl->val < 10) {
                    carry = 0;
                } else {
                    tl->val = (tl->val) % 10;
                    carry = 1;
                }
                t2 = t2->next;
            }
        }

        if (carry == 1) {
            ListNode* tail = new ListNode(1);
            tl->next = tail;
        }

        return ans;
    }
};
