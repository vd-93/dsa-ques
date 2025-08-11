/*Logic
sum of all subarray ranges = (sum of subarray maximums) - (sum of subarray minimums)
*/

// Ex dry run for better understanding -
// [1, 2, 4, 5, 2, 3, 6, 2, 1]
class Solution {
public:
    // NOTE: we are storing indices and not the actual elements in psee, nse, pgee and pge

    // Previous smaller or equal element's index
    vector<int> getPSEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            
            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return psee;
    }

    // Next smaller element
    vector<int> getNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            nse[i] =  st.empty() ? n : st.top();

            st.push(i); 
        } 
        return nse;
    }

    // Previous greater or equal element
    vector<int> getPGEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> pgee(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            pgee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return pgee;
    }

    // Next greater element
    vector<int> getNGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }
        return nge;
    }

    // Sum of subarray minimums
    long long sumSubarrayMins(vector<int>& nums) {
        long long total = 0;
        vector<int> psee = getPSEE(nums);
        vector<int> nse = getNSE(nums);

        for(int i = 0; i < nums.size(); i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            total += (1LL * left * right * nums[i]);
        }
        return total;
    }

    // Sum of subarray maximums
    long long sumSubarrayMaxs(vector<int>& nums) {
        long long total = 0;
        vector<int> pgee = getPGEE(nums);
        vector<int> nge = getNGE(nums);

        for(int i = 0; i < nums.size(); i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;

            total += (1LL * left * right * nums[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

    // M-1 : Brute O(N^2)
    // long long subArrayRanges(vector<int>& nums) {
    //     long long total = 0;

    //     for(int i = 0; i < nums.size(); i++) {
    //         int mini = nums[i];
    //         int maxi = nums[i];

    //         for(int j = i; j < nums.size(); j++) {
    //             mini = min(mini, nums[j]);
    //             maxi = max(maxi, nums[j]);

    //             total += (maxi - mini); 
    //         }
    //     }
    //     return total;
    // }
};