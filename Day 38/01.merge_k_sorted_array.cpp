// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/#
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> result;
        helper(arr, 0, K-1, result);
        return result;
    }
    void helper(vector<vector<int>> arr, int i, int j, vector<int> &result) {
        if (i == j) {
            for (int index = 0; index < arr.size(); index++) {
                result.push_back(arr[i][index]);
            }
            return;
        }
        if ((j-i) == 1) {
            mergeArray(arr[i], arr[j], result);
            return;
        }
        vector<int> temp1;
        vector<int> temp2;
        helper(arr, i, (i+j)/2, temp1);
        helper(arr, ((i+j)/2) + 1, j, temp2);
        mergeArray(temp1, temp2, result);
    }
    void mergeArray(vector<int> arr1, vector<int> arr2, vector<int> &arr3) {
        int size1 = arr1.size();
        int size2 = arr2.size();
        int i = 0;
        int j = 0;
        while(i < size1 && j < size2) {
            if (arr1[i] < arr2[j]) {
                arr3.push_back(arr1[i]);
                i++;
            } else {
                arr3.push_back(arr2[j]);
                j++;
            }
        }
        while(i < size1) {
            arr3.push_back(arr1[i]);
            i++;
        }
        while(j < size2) {
            arr3.push_back(arr2[j]);
            j++;
        }
    }
};