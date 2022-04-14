// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        temp = head;
        int c = size/k;
        ListNode* result = new ListNode(0);
        ListNode* curr = result;
        while(c--) {
            ListNode* t = temp;
            int i = 0;
            while(i < (k-1)) {
                i++;
                t = t->next;
            }
            ListNode* next = t->next;
            ListNode* rev = reverse(temp, t->next);
            curr->next = rev;
            while(curr->next != NULL) {
                curr = curr->next;
            }
            ListNode* t2 = rev;
            while(t2 != NULL && t2->next != NULL) {
                t2 = t2->next;
            }
            t2->next = next;
            temp = t2->next;
        }
        return result->next;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = NULL;
        while(head != tail) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};