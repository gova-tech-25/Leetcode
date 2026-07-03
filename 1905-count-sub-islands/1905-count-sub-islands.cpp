class Solution {
public:
    int n , m ;
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i ,int j){
        if(i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] == 0)
            return true;

        grid2[i][j] = 0;
        bool isSubIsland = (grid1[i][j] == 1);

        isSubIsland &= dfs(grid1 , grid2 , i+1 ,j );
        isSubIsland &= dfs(grid1 , grid2 , i ,j+1 );
        isSubIsland &= dfs(grid1 , grid2 , i-1 ,j );
        isSubIsland &= dfs(grid1 , grid2 , i ,j-1 );

        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid2[i][j] == 1){
                    if(dfs(grid1 , grid2 , i , j )){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};