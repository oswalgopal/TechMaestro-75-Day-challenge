// https://leetcode.com/problems/copy-list-with-random-pointer/

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
        if (head == NULL) {
            return head;
        }
        Node* curr = head;
        // copy the nodes
        while(curr != NULL) {
            Node* t = new Node(curr->val);
            t->next = curr->next;
            curr->next = t;
            curr = curr->next->next;
        }
        // add random pointers
        curr = head;
        while (curr != NULL) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }  
        // remove the duplicate one
        curr = head;
        head = head->next;
        while(curr != NULL && curr->next != NULL) {
            Node* next = curr->next;
            curr->next = curr->next->next;
            curr = next;
        }
        return head;
    }
};