class Solution {
public:
    /* M-1
    Logic : 
    traverse each element in height array
    find the leftMax and rightMax of that element, 
    if height[i] is less than both the leftMax and rightMax
        then the water stored at that particular position would be ->
            min(leftMax, rightMax) - height[i]
        else there will not be any water stored at that position

    we are getting leftMax and righMax for each element using prefiMax and suffixMax arrays
    */

    /* This array can be eliminated by using a variable storing the max element till now while
    traversing */
    vector<int> getPrefixMax(vector<int>& height) {
        vector<int> arr;

        arr.push_back(height[0]);

        for(int i = 1; i < height.size(); i++) {
            arr.push_back(max(arr[i-1], height[i]));
        }
        return arr;
    }

    vector<int> getSuffixMax(vector<int>& height) {
        vector<int> arr(height.size());

        arr[height.size() - 1] = height.back();

        for(int i = height.size() - 2; i >= 0; i--) {
            arr[i] = max(arr[i+1], height[i]);
        }
        return arr;
    }

    int trap(vector<int>& height) {
        vector<int> prefixMax = getPrefixMax(height);
        vector<int> suffixMax = getSuffixMax(height);

        int totalTrappedWater = 0;

        for(int i = 0; i < height.size(); i++) {
            int leftMax = prefixMax[i];
            int rightMax = suffixMax[i];

            if(height[i] < leftMax && height[i] < rightMax) {
                totalTrappedWater += (min(leftMax, rightMax) - height[i]);
            }
        }
        return totalTrappedWater;
    }
};