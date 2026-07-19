class DisjointSet{
    public:
    vector<int>rank , parent ,size;
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1 , 0);
        size.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{

             parent[ulp_v] = ulp_u;
             rank[ulp_u]++;
        }
    }

    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v] ){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
             parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds (n*n);
        vector<vector<bool>>active(n , vector<bool>(n,false));
        vector<vector<int>>cells;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                cells.push_back({grid[i][j] , i , j});
            }
        }

        sort(cells.begin() , cells.end());

        int dx[] = { -1 ,0 , 1 , 0};
        int dy[] = { 0 , 1 , 0 , -1};

        for(auto it : cells){
            int h = it[0];
            int r = it[1];
            int c = it[2];

            active[r][c] = true;

            int node = r*n + c;

            for(int k = 0 ; k < 4 ; k++){
                int nx = r + dx[k];
                int ny = c + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && active[nx][ny]){
                    int adj = nx * n + ny;
                    ds.unionBySize(node ,adj);
                }
            }
        

        if(active[0][0] && active[n-1][n-1] && ds.findUPar(0) == ds.findUPar(n*n-1)){
            return h;
        }
        }

        return -1;

    }
};