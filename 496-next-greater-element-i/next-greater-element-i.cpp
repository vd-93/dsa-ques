class Solution {
public:
    // M-4 (Optimal)
    // TC - O(n1 + n2), SC - O(n2)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;
        vector<int> result;

        // Traverse nums2 to fill nextGreater map
        for(int num : nums2) {
            // If current number is greater than the top of stack, it's the next greater
            while(!st.empty() && num > st.top()) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Remaining elements in stack don't have a next greater element
        while(!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        for(int num : nums1) {
            result.push_back(nextGreater[num]);
        }

        return result;
    }

    // M-3 (Optimal) Prefer
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> nextGreater;
    //     stack<int> st;
    //     vector<int> result;

    //     // Traverse nums2 in reverse to build the next greater map
    //     for (int i = nums2.size() - 1; i >= 0; i--) {
    //         int num = nums2[i];

    //         /*
    //         Pop all elements smaller than the current number from the stack.
    //         These elements cannot be the next greater element (NGE) for any
    //         element to the left, because the current number is greater and
    //         appears closer to the left side. So, the current number is a better
    //         candidate for NGE than any of the smaller elements being removed.
    //         */
    //         while (!st.empty() && st.top() < num) {
    //             st.pop();
    //         }

    //         /* This means the current num has no next greater element*/
    //         if (st.empty()) {
    //             nextGreater[num] = -1;
    //         } else {
    //             // Top of stack is the next greater element
    //             nextGreater[num] = st.top();
    //         }

    //         st.push(num);
    //     }

    //     // For each number in nums1, fetch its next greater from map
    //     for (int num : nums1) {
    //         result.push_back(nextGreater[num]);
    //     }

    //     return result;
    // }

    /* M-2 : Brute
    using map to store the indices of the elements of nums2, so that there will
    not be the need to traverse entire nums2 for finding next greater of each
    element in nums1
    */
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     int n1 = nums1.size();
    //     int n2 = nums2.size();

    //     unordered_map<int, int> mp;

    //     // storing the indices of all elements of nums2 in map
    //     for(int i = 0; i < n2; i++) {
    //         mp[nums2[i]] = i;
    //     }

    //     // Finding next greater element for each element in nums1
    //     for(int i = 0; i < n1; i++) {
    //         int nextGreater = -1;

    //         // Finding in the right side part of the element in nums2
    //         for(int j = mp[nums1[i]] + 1; j < n2; j++ ) {
    //             if(nums2[j] > nums1[i]) {
    //                 nextGreater = nums2[j];
    //                 break;
    //             }
    //         }

    //         nums1[i] = nextGreater;
    //     }

    //     return nums1;
    // }

    /* M-1 : Brute, TC - O(n1 * n2)
    Finding each element from nums1 in nums2 and then finding the next greater
    element
    */
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     int n1 = nums1.size();
    //     int n2 = nums2.size();

    //     for(int i = 0; i < n1; i++) {
    //         bool isNumFound = false;
    //         int nextGreater = -1;

    //         for(int j = 0; j < n2; j++) {
    //             if(nums1[i] == nums2[j]) {
    //                 isNumFound = true;
    //                 continue;
    //             }
    //             else if (!isNumFound) {
    //                 continue;
    //             }
    //             else if (nums2[j] > nums1[i]) {
    //                 nextGreater = nums2[j];
    //                 break;
    //             }
    //         }

    //         nums1[i] = nextGreater;
    //     }

    //     return nums1;
    // }
};