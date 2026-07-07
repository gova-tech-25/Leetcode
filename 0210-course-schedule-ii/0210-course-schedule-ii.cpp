class Solution {
public:
    bool dfs(int node ,vector<vector<int>>& adj ,vector<int>&vis , stack<int>&st ){
        vis[node] = 1;

        for(int p : adj[node]){
            if(vis[p] == 0){
                if(!dfs(p, adj , vis , st)) return false;
            }
            if(vis[p] == 1) return false;
        }
        vis[node] = 2;
        st.push(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>vis(n , 0);
        vector<int>ans;
        vector<vector<int>> adj(numCourses);

        stack<int>st;

        for (auto &p : prerequisites)
            adj[p[1]].push_back(p[0]);

      for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
           if(!dfs(i , adj , vis ,st)) return{};
        }
      }

      while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
      }
        return ans;
        
    }
    
};