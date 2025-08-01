class Solution {
public:
    long long getHoursRequired(int hourly, vector<int>& piles) {
        long long hoursReq = 0;

        for (int numOfBananas : piles) {
            // hoursReq += ceil((double)numOfBananas / (double)hourly);
            hoursReq += (numOfBananas + hourly - 1) / hourly;
        }
        return hoursReq;
    }

    int getMaxElementInArray(vector<int>& nums) {
        int maxElem = INT_MIN;

        for (int num : nums) {
            maxElem = max(maxElem, num);
        }
        return maxElem;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxInAPile = getMaxElementInArray(piles);

        /* Answer will always lie between [1 to max element in piles] 
        so applying binary search for that range [1 to maxInAPile]
        */
        int low = 1;
        int high = maxInAPile;

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            // Hours required to eat all bananas if koko is eating 'mid' bananar per hour
            long long hoursReq = getHoursRequired(mid, piles);

            // if hoursReq are less than or equal to h, then the 'mid' can be possible answer
            if (hoursReq <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // At the end low will be pointing to the minimum number of bananas required to eat per hour
        return low;
    }
};