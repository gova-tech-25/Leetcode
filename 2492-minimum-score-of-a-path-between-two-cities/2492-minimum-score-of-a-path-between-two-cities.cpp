class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
      vector<vector<pair<int,int>>>adj(n+1 );

      for(auto &r : roads){
        adj[r[0]].push_back({r[1] , r[2]});
        adj[r[1]].push_back({r[0] , r[2]});
      }

      vector<bool>vis(n+1 , false);
      int ans = INT_MAX;

      stack<int>st;

      st.push(1);
      vis[1] = true;

      while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto &[nei , w] : adj[node]){
            ans = min(ans , w);

            if(!vis[nei]){
                vis[nei] = true;
                st.push(nei);
            }
        }
      }
      return ans;
        
    }
};