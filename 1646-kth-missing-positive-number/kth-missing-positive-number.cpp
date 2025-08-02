class Solution {
public:
    // M-1 : using linear traversal O(N)
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;   // Count of missing numbers found
        int currNum = 1; // Current number to check

        for (int i = 0; i < n; i++) {
            while (arr[i] > currNum) {
                count++;
                if (count == k) {
                    return currNum;
                }
                currNum++;
            }
            // If arr[i] == currNum, move to next number
            currNum++;
        }

        // If we exit loop, k-th missing number is after the last element
        return arr[n - 1] + (k - count);
    }
};
