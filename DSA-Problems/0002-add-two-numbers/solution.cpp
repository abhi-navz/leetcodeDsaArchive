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
    ListNode* helper(ListNode* l1, ListNode* l2, int carry){

        // base case: 
        if(!l1 && !l2 && carry == 0) return nullptr;

        int val1 =0;
        int val2 = 0;
        int total =0;
        if(l1) {
            val1 = l1->val;
        }
        if(l2){
            val2 = l2->val;
        }

        total = val1+val2+carry;
        int newDigit = total%10;
        carry = total/10; // would be 1 in only as the nodes contain single digit so maximum the sum would be 18 , making the digit 8 and carry 1;

        ListNode* newHead = new ListNode(newDigit);

       if(l1){
        l1 = l1->next;
        }
        if(l2){
            l2 = l2->next;
        }

        newHead->next = helper(l1,l2,carry);

        return newHead;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* ans = helper(l1,l2,0);
        return ans;
        
    }
};
