class DisjointSet{
   
public:
    vector<int>rank , parent , size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n * n);

        //step 1 : connecting components;

        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 0) continue;
                int dx[] = {-1 , 0 , 1 , 0};
                int dy[] = {0 , 1 , 0 , -1};
                for(int i = 0 ; i < 4 ; i++){
                    int nx = row + dx[i];
                    int ny = col + dy[i];
                    if(nx >= 0 && ny >=0 && nx < n && ny < n && grid[nx][ny] == 1){
                        int nodeNo = row * n + col;
                        int newNo = nx * n + ny;

                        ds.unionBySize(nodeNo , newNo);
                    }
                }
            }
        }

        // step 2 : converting and checking them with side
        int mx = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 1) continue;
                int dx[] = {-1 , 0 , 1 , 0};
                int dy[] = {0 , 1 , 0 , -1};
                set<int>comp;
                for(int i = 0 ; i < 4 ; i++){
                    int nx = row + dx[i];
                    int ny = col + dy[i];
                    if(nx >= 0 && ny >=0 && nx < n && ny < n ){
                        if(grid[nx][ny] == 1){
                            comp.insert(ds.findUPar(nx * n + ny));
                        }
                    }
                }
                int sizeTotal = 0;
                for(auto it : comp){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx , sizeTotal + 1);
            }
        }

        for(int cellNo = 0 ; cellNo < n * n; cellNo++ ){
            mx = max(mx , ds.size[ds.findUPar(cellNo)]);
        }
        return mx;    
    }
};