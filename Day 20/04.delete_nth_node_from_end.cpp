// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
        int c = n;
        ListNode* ref = head;
        while(c--) {
            ref = ref->next;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(ref != NULL) {
            prev = temp;
            temp = temp->next;
            ref = ref->next;
        }
        if (prev == NULL) {
            head = head->next;
        } else {
            prev->next = temp->next;
        }
        return head;
    }
};