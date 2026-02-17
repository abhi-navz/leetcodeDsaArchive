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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int m =0,n =0;

        ListNode* temp = headA;
        while(temp){
            m++;
            temp = temp->next;
        }

        temp = headB;
        while(temp){
            n++;
            temp= temp->next;
        }

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        if(m>n){
            for(int i =0; i<m-n; i++){
                tempA = tempA->next;
            }
        }else if(n>m){
            for(int i =0; i<n-m; i++){
                tempB = tempB->next;
            }
        }

        while(tempA && tempB){
            if(tempA == tempB){
                return tempA;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr;
        
    }
};
