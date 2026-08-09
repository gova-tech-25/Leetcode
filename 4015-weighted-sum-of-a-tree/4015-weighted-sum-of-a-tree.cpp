class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>>adj(n);
        
        for(int i = 1 ; i < n ; i++) adj[parent[i]].push_back(i);

        vector<int>depth(n);

        depth[0] = 1;
        int h = 1;

        queue<int>q;
        q.push(0);

        while(!q.empty()){
            auto u = q.front();
            q.pop();

            for(auto v : adj[u]){
                depth[v] = 1 + depth[u];
                h = max(h , depth[v]);
                q.push(v);
            }
        }
        long long ans = 0;
        for(int i = 0 ; i < n ; i++) ans += 1LL * nums[i] * ( h - depth[i] + 1);
        return ans;
    }
};