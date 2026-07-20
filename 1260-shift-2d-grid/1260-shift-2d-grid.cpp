class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = i * n + j;
                int next = (curr + k) % total;

                ans[next / n][next % n] = grid[i][j];
            }
        }

        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        while (k--) {
            int last = grid[m - 1][n - 1];

            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    if (j > 0)
                        grid[i][j] = grid[i][j - 1];
                    else if (i > 0)
                        grid[i][0] = grid[i - 1][n - 1];
                }
            }

            grid[0][0] = last;
        }

        return grid;
        
    }
};