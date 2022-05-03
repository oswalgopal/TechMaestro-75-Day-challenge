// https://www.geeksforgeeks.org/nearly-sorted-algorithm/
int sortK(int arr[], int n, int k)
{
     
    // Insert first k+1 items in a priority queue (or min
    // heap)
    //(A O(k) operation). We assume, k < n.
  //if size of array = k i.e k away from its target position
  //then
    int size;
    size=(n==k)?k:k+1;
    priority_queue<int, vector<int>, greater<int> > pq(arr, arr +size);
 
    // i is index for remaining elements in arr[] and index
    // is target index of for current minimum element in
    // Min Heap 'pq'.
    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
 
    while (pq.empty() == false) {
        arr[index++] = pq.top();
        pq.pop();
    }
}