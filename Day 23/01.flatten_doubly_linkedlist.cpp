// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr != NULL)  {
            if (curr->child == NULL) {
                curr = curr->next;
                continue;
            }
            Node* child = curr->child;
            child->prev = curr;
            while(child->next != NULL) {
                child = child->next;
            }
            Node* next = curr->next;
            if (next != NULL) {
                next->prev = child;
            }
            curr->next = curr->child;
            curr->child = NULL;
            child->next = next;
            curr = curr->next;
        }
        return head;
    }
};