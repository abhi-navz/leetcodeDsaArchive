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
    bool isPalindrome(ListNode* head) {

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalfStart = nullptr;
        if(fast == NULL){
            // even no of elements in list.
            secondHalfStart = slow;

        }else{
            // odd no of elementsin the list.
            secondHalfStart = slow->next;
        }

       ListNode* revSecondHalfStart = reversedList(secondHalfStart);

       // compare first part with reversed 2nd part.

       ListNode* p1 = head;
       ListNode* p2 = revSecondHalfStart;

       while(p1!= NULL && p2 != NULL){
        if(p1->val != p2->val){
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
       }

       
       return true;
  
    }


private:

    ListNode* reversedList (ListNode* head){

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextEl = nullptr;

        while(curr){
            nextEl = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextEl;
        }

        return prev;
    }
};


