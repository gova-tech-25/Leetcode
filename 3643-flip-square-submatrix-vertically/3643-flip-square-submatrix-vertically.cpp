class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int top = x ; 
        int bottom = x + k - 1;

        while(top < bottom){
            for(int i = y ; i < y + k ; i++ ){
                swap(grid[top][i] , grid[bottom][i]);

            }
            top++;
            bottom--;
        }

        // for (int i = 0; i < k / 2; i++) {
        //     for (int j = 0; j < k; j++) {
        //         swap(grid[x + i][y + j], grid[x + k - 1 - i][y + j]);
        //     }
        // }
        return grid;
        
    }
};