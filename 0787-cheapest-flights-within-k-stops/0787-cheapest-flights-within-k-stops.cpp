class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

       vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adj[u].push_back({v , cost});
        }

        vector<int>dist(n ,1e9);
        dist[src] = 0;
        queue<pair<int, pair<int,int>>> q;

        q.push({0 , {src , 0}}); // { stops , {node ,dist}}

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(steps > k) continue;

            for(auto &p : adj[node]){

                int adjNode = p.first;
                int ew = p.second;

                if(cost + ew < dist[adjNode] && steps <= k){
                    dist[adjNode] = cost + ew;
                    q.push({steps+1 , {adjNode , cost + ew}});
                }

            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};