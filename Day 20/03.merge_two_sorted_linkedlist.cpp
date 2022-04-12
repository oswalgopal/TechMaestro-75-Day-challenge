// https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode(0);
        ListNode* curr = result;
        while(list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                ListNode* t = new ListNode(list1->val);
                curr->next = t;
                list1 = list1->next;
            } else {
                ListNode* t = new ListNode(list2->val);
                curr->next = t;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 != NULL) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        
        return result->next;
    }
};