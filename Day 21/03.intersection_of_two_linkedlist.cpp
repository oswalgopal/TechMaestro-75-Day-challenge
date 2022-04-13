// https://leetcode.com/problems/intersection-of-two-linked-lists/
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
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int s1 = 0;
        int s2 = 0;
        while(l1 != NULL) {
            s1++;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            s2++;
            l2 = l2->next;
        }
        l1 = headA;
        l2 = headB;
        int diff = abs(s1-s2);
        if (s1 > s2) {
            while(diff--) {
                l1 = l1->next;
            }
        } else {
            while(diff--) {
                l2 = l2->next;
            }
        }
        while(l1 != NULL && l2 != NULL) {
            if (l1 == l2) {
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1;
    }
};