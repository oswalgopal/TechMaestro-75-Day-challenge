// https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        ListNode* curr = NULL;
        int size = lists.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < size; i++) {
            ListNode* t = lists[i];
            while(t != NULL) {
                q.push(t->val);
                t = t->next;
            }
        }
        
        while(!q.empty()) {
            ListNode* t = new ListNode(q.top());
            q.pop();
            if (result == NULL) {
                result = t;
                curr = result;
            } else {
                curr->next = t;
                curr = curr->next;
            }
        }
        
        
        return result;
    }
};