class Solution {
public:

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>>dp(n , vector<int>(n ,0));

        for(int i = 0 ; i < n ; i++)
            dp[i][i] = piles[i];

        for(int len = 2 ; len <= n ; len ++){
            for(int i = 0 ; i + len - 1 < n ; i++){
                int j = i + len - 1 ;
                dp[i][j] = max(piles[i] - dp[i+1][j] , piles[j] - dp[i][j-1]);

            }
        }
        return dp[0][n-1] > 0 ;
        
    }
};

class Solution1 {
public:

    bool stoneGame(vector<int>& piles) {
        return true; 
    }
};

class Solution2 {
public:
    bool fn(vector<int>& piles, bool turn, int start, int end, int a, int b) {

        // No piles left
        if (start > end)
            return a > b;

        if (turn) { // Alice's turn

            // Alice picks left
            bool left = fn(piles, false, start + 1, end,
                           a + piles[start], b);

            // Alice picks right
            bool right = fn(piles, false, start, end - 1,
                            a + piles[end], b);

            // Alice chooses the move that lets her win
            return left || right;

        } else { // Bob's turn

            // Bob picks left
            bool left = fn(piles, true, start + 1, end,
                           a, b + piles[start]);

            // Bob picks right
            bool right = fn(piles, true, start, end - 1,
                            a, b + piles[end]);

            // Bob plays optimally to stop Alice from winning
            return left && right;
        }
    }

    bool stoneGame(vector<int>& piles) {

        return fn(piles, true, 0, piles.size() - 1, 0, 0);
    }
};