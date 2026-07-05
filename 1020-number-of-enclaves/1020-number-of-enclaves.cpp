class Solution {
public:
    int n , m ;

    void dfs(int i , int j , vector<vector<int>>& grid ,vector<vector<int>> &vis ){
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        if(vis[i][j] || grid[i][j] == 0 ) return;

        vis[i][j] = 1;

            dfs(i-1, j, grid, vis);
            dfs(i+1, j, grid, vis);
            dfs(i, j-1, grid, vis);
            dfs(i, j+1, grid, vis);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));

        for(int i = 0 ; i < n ; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i , 0 , grid , vis);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i , m-1 , grid, vis);
            }
        }
         for(int j = 0 ; j < m ; j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs( 0, j , grid , vis);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs( n-1, j , grid, vis);
            }
        }
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};