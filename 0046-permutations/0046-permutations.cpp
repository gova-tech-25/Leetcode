class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    void solve(vector<int>& nums , vector<int>&vis){

        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            if(vis[i]) continue;

            vis[i] = 1;

            curr.push_back(nums[i]);

            solve(nums , vis);

            curr.pop_back();

            vis[i] = 0;
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int>vis(n , 0);
        solve(nums , vis);

        return ans;
        
    }
};