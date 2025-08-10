class Solution {
public:
    /* Logic:
    For each element arr[i], count how many subarrays exist where arr[i] is the
    minimum. For that, find:
       - PSEE: Previous Smaller or Equal Element index (to handle the edge case of duplicate elements,
       we are also considering the prev equal element, do dry run for [1,1] for better understanding)
       - NSE: Next Smaller Element index
        
        The count of such subarrays is (i - PSEE[i]) * (NSE[i] - i).
        Multiply this count by arr[i] and take modulo 1e9+7 to get the arr[i]'s contribution in the
        total sum
     */
    vector<int> getNseIndexArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return result;
    }

    vector<int> getPrevSmallerOrEqaulNumberIndexArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            result[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;

        vector<int> nse = getNseIndexArray(arr);
        vector<int> psee = getPrevSmallerOrEqaulNumberIndexArray(arr);

        int mod = (int)(1e9 + 7);

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total + ((1LL * left * right * arr[i]) % mod)) % mod;
        }

        return total;
    }
};