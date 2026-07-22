class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n , vector<int>(m,INT_MAX));
        
        dist[0][0] = 0;

        // Right, Left, Down, Up
        vector<pair<int,int>> dir = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

         deque<pair<int,int>> dq;
         dq.push_front({0,0});

        while(!dq.empty()){
            auto[x , y] = dq.front();
            dq.pop_front();

            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) 
                    continue;
                
                 // Cost = 0 if moving in the cell's indicated direction,
                // otherwise we pay 1 to change the arrow.

                int wt = (grid[x][y] == i + 1) ? 0 : 1;

                if(dist[nx][ny] > dist[x][y] + wt){
                    dist[nx][ny] = dist[x][y] + wt;
                    if(wt == 0) dq.push_front({nx,ny});
                    else dq.push_back({nx,ny});

                }

            }
        }
        return dist[n-1][m-1];
    }
};