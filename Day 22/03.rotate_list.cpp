// https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        if (size == 0) {
            return NULL;
        }
        temp = head;
        k = k % size;
        int c = size-k-1;
        while(c--) {
            temp = temp->next;
        }
        ListNode* t = temp->next;
        temp->next = NULL;
        temp = t;
        if (temp == NULL) {
            return head;
        }
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        head = t;
        return head;
    }
};