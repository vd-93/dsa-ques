class Solution {
public:
    /* The answer must be between 0 to x, so to find that answer
    we are using binary search on the range [0 to x];
    instead of returing 'high' we can also use extra variable 'ans' to store the answer 
    */
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while(low <= high) {
            long long mid = low + ((high - low) / 2);

            if(mid * mid == (long long)x) {
                return mid;
            }
            else if(mid * mid < x) {
                // eliminate the left half
                low = mid + 1;
            }
            else {
                // eliminate the right half
                high = mid - 1;
            }
        } 
        return high;
    }
};