// https://leetcode.com/problems/add-two-numbers-ii/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        stack<int> stk1;
        stack<int> stk2;
        while(l1 != NULL) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while(!stk1.empty() && !stk2.empty()) {
            int sum = stk1.top() + stk2.top() + carry;
            carry = 0;
            if (sum > 9) {
                carry = sum / 10;
                sum = sum % 10;
            }
            ListNode* t = new ListNode(sum);
            t->next = result;
            result = t;
            stk1.pop();
            stk2.pop();
        }
        while(!stk1.empty()) {
            int sum = stk1.top() + carry;
            carry = 0;
            if (sum > 9) {
                carry = sum / 10;
                sum = sum % 10;
            }
            ListNode* t = new ListNode(sum);
            t->next = result;
            result = t;
            stk1.pop();
        }
        while(!stk2.empty()) {
            int sum = stk2.top() + carry;
            carry = 0;
            if (sum > 9) {
                carry = sum / 10;
                sum = sum % 10;
            }
            ListNode* t = new ListNode(sum);
            t->next = result;
            result = t;
            stk2.pop();
        }
        if (carry != 0) {
            ListNode* t = new ListNode(carry);
            t->next = result;
            result = t;
            carry = 0;
        }
        
        return result;
    }
};