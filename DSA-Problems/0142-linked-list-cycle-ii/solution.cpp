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
    ListNode *detectCycle(ListNode *head) {

        if(!head || !head->next ) return nullptr;

        // we'll create a set and put the node inside it as we traverse, if we find the same node inside the set, it means there's loop and we'll simply retunn the node

        unordered_set<ListNode*> st;
        ListNode* curr = head;

        while(curr){
            if(st.find(curr) != st.end()){
                return curr;

            }
            st.insert(curr);
            curr = curr->next;
        }

        return nullptr;
        
    }
};
