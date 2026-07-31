class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        
        vector<vector<int>>dp(n , vector<int>(11,0));

        for(auto it : pick){
            int player = it[0];
            int color = it[1];

            dp[player][color]++;
        }

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <= 10 ; j++){
                if(dp[i][j] > i) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};