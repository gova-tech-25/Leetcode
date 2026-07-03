class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int t = 0;

        queue<pair<pair<int,int> , int>>q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , t});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }


        int tm = 0;
        int dx [] = {-1 , 0 , 1 , 0};
        int dy [] = {0 , 1 , 0 , -1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            tm = max(tm , t);
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m
                   && grid[nx][ny] == 1 && vis[nx][ny] != 2){
                    q.push({{nx ,ny} , t+1});
                    vis[nx][ny] = 2;
                   }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }

        return tm;
    }
};