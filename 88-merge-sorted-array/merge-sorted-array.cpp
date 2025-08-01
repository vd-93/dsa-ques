class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        /* when nums1 is over and nums2 is remaining just copy the remaining elements of nums2
        into nums1 */
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};