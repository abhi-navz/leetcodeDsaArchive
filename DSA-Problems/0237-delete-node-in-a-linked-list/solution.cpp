/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        // approach : we'll copy the data from next node to current node and then delete the next node.

     ListNode* temp = node->next; // taking reference of the old next node.
     node->val = temp->val; // copy value from the next node.
     node->next = temp->next;
     delete temp;                 // deleting the next node.
        
    }
};
