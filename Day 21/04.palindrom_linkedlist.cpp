// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ListNode* mid = head;
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL) {
            temp = temp->next->next;
            mid = mid->next;
        }
        mid = reverse(mid);
        temp = head;
        while(mid != NULL) {
            if (temp->val != mid->val) {
                return false;
            }
            temp = temp->next;
            mid = mid->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while(head != NULL) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};