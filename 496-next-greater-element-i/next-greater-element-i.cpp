class Solution {
public:
    /* M-2 : Brute 
    using map to store the indices of the elements of nums2, so that there will not be
    the need to traverse entire nums2 for finding next greater of each element in nums1
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
    Finding each element from nums1 in nums2 and then finding the next greater element
    */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i = 0; i < n1; i++) {
            bool isNumFound = false;
            int nextGreater = -1;

            for(int j = 0; j < n2; j++) {
                if(nums1[i] == nums2[j]) {
                    isNumFound = true;
                    continue;
                }
                else if (!isNumFound) {
                    continue;
                }
                else if (nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            nums1[i] = nextGreater;
        }

        return nums1;
    }
};