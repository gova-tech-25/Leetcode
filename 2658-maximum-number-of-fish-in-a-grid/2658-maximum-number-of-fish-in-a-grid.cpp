class Solution {
public:
    int m , n;
    int dfs(int i , int j , vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0){
            return 0;
        }

       int fish = grid[i][j];
       grid[i][j] = 0;

       fish += dfs(i+1 , j , grid);
       fish += dfs(i , j+1 , grid);
       fish += dfs(i-1 , j , grid);
       fish += dfs(i , j-1 , grid);

       return fish;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]){
                    ans = max(ans,dfs(i , j , grid));
                }
            }
        }
        return ans;
        
    }
};