class Solution {
public:
    void dfs(int node , vector<vector<int>> &adj ,  vector<int> &vis , vector<int>&components){
        vis[node] = 1;
        components.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , adj , vis ,components);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>vis(n , 0);
        int cnt = 0 ;

        for(int i = 0 ; i < n ; i++ ){
            if(!vis[i] ){
                vector<int>components ;

                dfs(i , adj , vis , components);
                int vertices = components.size();
                int edgeCount  = 0;

                for(int node : components){
                    edgeCount  += adj[node].size();
                }

                edgeCount /= 2 ;
                if(edgeCount  == vertices * (vertices-1) / 2){
                      cnt++;
                }

            }
        }
        return cnt;
    }
};