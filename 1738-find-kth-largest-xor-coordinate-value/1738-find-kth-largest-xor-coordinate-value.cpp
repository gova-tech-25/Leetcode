class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>pref(n , vector<int>(m,0));
        priority_queue<int , vector<int> , greater<int>>pq;

        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                pref[i][j] = matrix[i][j];
                if(i > 0 ) pref[i][j] ^= pref[i-1][j];
                if(j > 0 ) pref[i][j] ^= pref[i][j-1];
                if(i > 0 && j > 0) pref[i][j] ^= pref[i-1][j-1];  
                    
                    if(pq.size() < k){
                        pq.push(pref[i][j]);
                    }
                    else if(pref[i][j] > pq.top()){
                        pq.pop();
                        pq.push(pref[i][j]);
                    }
            }
        }
        return pq.top();
        
    }
};