class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> vis(n , 0);

        for(auto &edge : edges){
            vis[edge[1]]++;
        }
        int p = 0;
        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            if(vis[i] == 0){
                cnt++;
                p = i;
            }
        }
        return (cnt == 1 )? p : -1;
    }
};