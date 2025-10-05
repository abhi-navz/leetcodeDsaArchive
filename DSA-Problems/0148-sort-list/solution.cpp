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
    ListNode* getMiddle(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {

        if(left == nullptr) return right;
        if(right == nullptr) return left;

        ListNode* curr = nullptr;

        if(left->val <= right->val){
            curr = left;
            left = left->next;
        }else{
            curr = right;
            right = right->next;
        }
        ListNode* ans = curr;

        while(left && right){
            if(left->val <= right->val){
                curr->next = left;
                left = left->next;
                
            }else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
            
        }

        // now add the rest of the elements which will be left in one of the list;
        curr->next = (left ? left : right);
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* mid = getMiddle(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        return merge(leftSorted, rightSorted);
    }
};
