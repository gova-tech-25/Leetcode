class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    int n;
    void solve(vector<int>& nums, vector<int>& vis) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            if(i > 0 && nums[i] == nums[i-1] && !vis[i-1])
                continue;

            vis[i] = 1;

            curr.push_back(nums[i]);
            solve(nums, vis);
            curr.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<int>vis(n , 0);
        sort(nums.begin() , nums.end());
        solve(nums,vis);
        //sort(ans.begin() , ans.end());
        //ans.erase(unique(ans.begin() , ans.end()) , ans.end());
        return ans;
    }
};