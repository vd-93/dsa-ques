/*
At each bar, the water trapped would be equal to the
-> min(leftMax, rightMax) - height[i]
i.e. the minimum of the left max and right max will be the deciding factor
*/
class Solution {
public:
    // M-2 Optimal
    /*
     Logic:
     Use 2 pointers from both ends to track the maximum height to the left and right. 
     Water trapped at any bar is determined by the shorter of the
     two max heights. Traverse inward, always moving the pointer with the
     smaller max height. 
     Time Complexity: O(N), Space Complexity: O(1)
    */

    int trap(vector<int>& height) {
        int leftMax = 0;  // Tracks the maximum height from the left
        int rightMax = 0; // Tracks the maximum height from the right
        int ans = 0; 

        int l = 0, r = height.size() - 1; // Two pointers

        while (l < r) {
            // Update the max heights from both ends
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            // Always process the side with the smaller max height
            if (leftMax <= rightMax) {
                // Water trapped at current left is leftMax - height[l]
                ans += (leftMax - height[l]);
                l++;
            } else {
                // Water trapped at current right is rightMax - height[r]
                ans += (rightMax - height[r]);
                r--;
            }
        }

        return ans;
    }

    /* M-1
    Logic :
    traverse each element in height array
    find the leftMax and rightMax of that element,
    if height[i] is less than both the leftMax and rightMax
        then the water stored at that particular position would be ->
            min(leftMax, rightMax) - height[i]
        else there will not be any water stored at that position

    we are getting leftMax and righMax for each element using prefiMax and
    suffixMax arrays
    */

    /* This array can be eliminated by using a variable storing the max element
    till now while traversing */
    // vector<int> getPrefixMax(vector<int>& height) {
    //     vector<int> arr;

    //     arr.push_back(height[0]);

    //     for(int i = 1; i < height.size(); i++) {
    //         arr.push_back(max(arr[i-1], height[i]));
    //     }
    //     return arr;
    // }

    // vector<int> getSuffixMax(vector<int>& height) {
    //     vector<int> arr(height.size());

    //     arr[height.size() - 1] = height.back();

    //     for(int i = height.size() - 2; i >= 0; i--) {
    //         arr[i] = max(arr[i+1], height[i]);
    //     }
    //     return arr;
    // }

    // int trap(vector<int>& height) {
    //     vector<int> prefixMax = getPrefixMax(height);
    //     vector<int> suffixMax = getSuffixMax(height);

    //     int totalTrappedWater = 0;

    //     for(int i = 0; i < height.size(); i++) {
    //         int leftMax = prefixMax[i];
    //         int rightMax = suffixMax[i];

    //         if(height[i] < leftMax && height[i] < rightMax) {
    //             totalTrappedWater += (min(leftMax, rightMax) - height[i]);
    //         }
    //     }
    //     return totalTrappedWater;
    // }
};