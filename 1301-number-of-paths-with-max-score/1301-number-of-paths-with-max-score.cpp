class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int MOD  = 1e9 + 7;

        vector<vector<int>>score(n ,vector<int>(n,-1));

        vector<vector<long long>>ways(n , vector<long long>(n , 0));

        score[0][0] = 0;
        ways[0][0] = 1;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'X') continue;

                if(i == 0 && j == 0 ) continue;

                long long bs = -1;
                long long cnt = 0;

                // up

                if(i > 0 && score[i-1][j] != -1){
                    if(score[i-1][j] > bs){
                        bs = score[i-1][j];
                        cnt = ways[i-1][j];
                    }
                    else if(score[i-1][j] == bs){
                        cnt = (cnt + ways[i-1][j]) % MOD;
                    }
                }

                // left 
                if(j > 0 && score[i][j-1] != -1){
                    if(score[i][j-1] > bs){
                        bs = score[i][j-1];
                        cnt = ways[i][j-1];
                    }
                    else if(score[i][j-1] == bs){
                        cnt = ( cnt + ways[i][j-1]) % MOD;
                    }

                }

                // up - left
                if(i > 0 && j > 0 && score[i-1][j-1] != -1){
                    if(score[i-1][j-1] > bs){
                        bs = score[i-1][j-1];
                        cnt = ways[i-1][j-1];
                    }
                    else if(score[i-1][j-1] == bs){
                        cnt = (cnt + ways[i-1][j-1]) % MOD;
                    }

                }

                if(bs == -1) continue;

                int val = 0;

                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    val = board[i][j] - '0';
                }

                score[i][j] = val + bs;
                ways[i][j] = cnt % MOD;


            }

        }

        if(ways[n-1][n-1] == 0) return {0,0};

        return {score[n-1][n-1] , (int)ways[n-1][n-1]};

    }
};