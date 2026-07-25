class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        
        vector<vector<int>> dup = mat;
        int p = k % n;
        while(p--){
            for(int i = 0 ; i < m ; i++){
                if(i % 2 == 0){
                    int first = dup[i][0];
                    for(int j = 0 ; j < n-1 ; j++){
                        dup[i][j] = dup[i][j+1];
                    }
                    dup[i][n-1] = first;

                }
                else{
                    int last = dup[i][n-1];
                    for(int j = n - 1 ; j >= 1 ; j--){
                        dup[i][j] = dup[i][j-1];
                    }
                    dup[i][0] = last;

                }
            }

        }
        return dup == mat;
    }
};