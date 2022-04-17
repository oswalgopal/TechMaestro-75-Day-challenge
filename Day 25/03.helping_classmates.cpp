// https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1/

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> result(n, -1);
        stack<int> stk;
        for (int i = n-1; i >= 0; i--) {
            if (stk.empty()) {
                result[i] = -1;
            } else if (!stk.empty() && stk.top() >= arr[i]) {
                while (!stk.empty() && stk.top() >= arr[i]) {
                    stk.pop();
                }
                if (stk.empty()) {
                    result[i] = -1;
                } else {
                    result[i] = stk.top();
                }
            } else {
                result[i] = stk.top();
            }
            stk.push(arr[i]);
        }
        
        return result;
    } 
};