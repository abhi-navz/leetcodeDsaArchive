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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*> ans(k, nullptr);

        ListNode* temp = head;
        int n = 0;
        while (temp) {
            n++;
            temp = temp->next;
        }

        int q = n / k;
        int r = n % k;

        // now the optimal distribution is that first r parts have
        // q+1 members, and the rest k-r parts have q members

        temp = head;
        ListNode* next = nullptr;

        for (int i = 0; i < k; i++) {
            ans[i] = temp;

            // the partsize will be one extra that is q=1 if i is less than r or
            // it'll be size q;

            int add = 0;
            if (i < r) {
                add = 1;
            } else {
                add = 0;
            }

            int partSize = q + add;

            if (temp) {
                for (int j = 1; j < partSize; j++) {
                    temp = temp->next;
                }
            }

            if (temp) {

                next = temp->next;
                temp->next = nullptr;
                temp = next;
            }

           
        }

        return ans;
    }
};
