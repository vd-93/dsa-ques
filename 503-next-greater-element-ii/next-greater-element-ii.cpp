class Solution {
public:
    // M-2 : Optimal
    // TC : O(4n) -> at max 2n push operations and 2n pop operations
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st; // Stack to keep track of potential next greater elements
        vector<int> nge(n);

        // Traverse the array twice in reverse to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; i--) {
            int ind = i % n; // Get the actual index in circular array

            /* Remove elements from the stack that are less than or equal to
            current element because they can't be the next greater for
            current or any previous element
            */
            while (!st.empty() && nums[ind] >= st.top()) {
                st.pop();
            }

            // For the first pass only (i < n), update the result array
            if (i < n) {
                // If stack is empty, no greater element exists
                if (st.empty()) {
                    nge[ind] = -1;
                } else {
                    // Top of the stack is the next greater element
                    nge[ind] = st.top();
                }
            }

            // Push current element onto the stack for future comparisons
            st.push(nums[ind]);
        }

        return nge;
    }

    // M-1 : Brute O(n^2)
    // vector<int> nextGreaterElements(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<int> nge(n, -1);

    //     for(int i = 0; i < n; i++) {
    //         // Iterating the circular array to find nge of current num
    //         (nums[i]) for(int j = i + 1; j <= i + n - 1; j++) {
    //             int index = j % n;

    //             if(nums[index] > nums[i]) {
    //                 nge[i] = nums[index];
    //                 break;
    //             }
    //         }
    //     }
    //     return nge;
    // }
};