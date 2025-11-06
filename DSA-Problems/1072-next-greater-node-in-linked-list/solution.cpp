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

    ListNode* revLl(ListNode* head){

        ListNode* temp = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;

        while(temp){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return prev;
        

    }

    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* temp = head;

        int n =0;
        while(temp){
            n++;
            temp = temp->next;
        }


        ListNode* revHead = revLl(head);

        vector<int>ans (n,0);
        stack<int>st;
        temp = revHead;

        for(int i =n-1; i>=0; i--){

            while(!st.empty() && temp->val >= st.top()){
                st.pop();
            }

            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(temp->val);


            temp = temp->next;


        }

        return ans;


        
    }
};
