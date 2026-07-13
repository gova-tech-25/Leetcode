class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue< 
                    pair<int , pair<int,int>> ,
                        vector<pair<int, pair<int,int>>> , 
                        greater<pair<int , pair<int,int>>> > pq;
        
        vector<vector<int>>dist(n , vector<int>(m , 1e9));

        dist[0][0] = 0;

        pq.push({0, {0,0}});

        int dr [] = {-1 , 0 , 1 , 0 };
        int dc [] = { 0 , 1 , 0 , -1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(diff > dist[r][c]) continue;

            for(int i = 0 ; i < 4 ; i++){
                int nx = r + dr[i];
                int ny = c + dc[i];


                if(r == n-1  && c == m-1) return diff;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int newEffort = max(abs(heights[r][c] - heights[nx][ny]) , diff);
                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort , {nx , ny}});
                    }
                }
            }
        }

        return 0;
    }
};