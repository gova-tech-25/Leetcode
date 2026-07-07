class Solution {
public:
    bool dfs(int node , int col , vector<vector<int>>& graph , vector<int>&vis ){
        vis[node] = col;

        for(int p : graph[node]){
            if(vis[p] == -1) {
                if(!dfs(p , !col , graph ,vis)) 
                      return false;
            }
           else if(vis[p] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>color(n , -1);

        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
               if( !dfs(i ,0 , graph , color)) return false;
            }
        }
        return true;
    }
};