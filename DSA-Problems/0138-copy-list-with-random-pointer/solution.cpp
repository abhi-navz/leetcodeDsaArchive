/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }

        // step 01: inserting copied nodes after each node.

        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }

        // Step 2: Assign random pointers for the copied nodes

        temp = head;
        while (temp) {
            if (temp->random) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // step 03: separating the list;

        Node* newHead = head->next;
        temp = head;

        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next;
            if (copy->next)
                copy->next = copy->next->next;
            else
                copy->next = nullptr;
            temp = temp->next;
        }

        return newHead;
    }
};
