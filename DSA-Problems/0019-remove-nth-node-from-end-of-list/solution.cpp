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

        int len =0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }

        if(n == len){
            head = head->next;
            return head;
        }

        temp = head;
        int k = 1;
        while(temp){
            if(k == len-n){
                temp->next = temp->next->next;
                break;
            }
            k++;
            temp = temp->next;

        }


        return head;
        
    }
};
