class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        multiset<int> st;
        int ans = INT_MAX;

        for(int j = 1; j <= n; j++) {

            int add = j - l;
            int remove = j - r - 1;

            if(add >= 0) {
                st.insert(pref[add]);
            }

            if(remove >= 0) {
                st.erase(st.find(pref[remove]));
            }

            auto it = st.lower_bound(pref[j]);

            if(it != st.begin()) {
                --it;

                int sum = pref[j] - *it;

                if(sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};