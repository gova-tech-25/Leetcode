class Solution {
public:
    vector<int> getRow(int row) {
          long long ans = 1;

        vector<int>ansRow;

        ansRow.push_back(1);

        for(int col = 0 ; col < row ; col++ ){
            ans = ans * (row - col);
            ans = ans / (col + 1 );
            ansRow.push_back(ans);
        }
        return ansRow;
        
    }
};

