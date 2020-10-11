class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        if (k == 0) return ans;
        priority_queue<int> big_heap;
        int i;
        for (i = 0; i < k; i++) {
            big_heap.push(arr[i]);
        }
        for (; i < arr.size(); i++) {
            if (big_heap.top() > arr[i]) { 
                big_heap.pop();
                big_heap.push(arr[i]);
            }
        }
        for (i = 0; i < k; i++) {
            int temp = big_heap.top();
            big_heap.pop();
            ans[i] = temp;
        }
        return ans;
    }
};