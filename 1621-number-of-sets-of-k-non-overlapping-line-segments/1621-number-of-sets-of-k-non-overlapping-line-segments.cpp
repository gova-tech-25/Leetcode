class Solution {
public:
    const int MOD = 1e9 + 7;

    long long pow(int x , int n){
        long long base = x , ans = 1;
        while(n){
            if(n & 1){
                ans = (ans * base ) % MOD;
            }
            base = (base * base ) % MOD;

            n >>= 1;
        }
        return ans;
    }
    long long inv(int n){
        return pow(n ,  MOD - 2);

    }
    int c (int n , int r){
        long long nr = 1 ,dr1 = 1, dr2 = 1;
        for(int i = 1 ; i <= n ; i++)
            nr = ( nr * i) % MOD;
        for(int i = n - r ; i >= 1 ; i--)
            dr1 = (dr1 * i ) % MOD;
        for(int i = r ;i >= 1 ; i--)
            dr2 = (dr2 * i ) % MOD;
        return nr * inv (dr1) % MOD * inv(dr2) % MOD;
    }
    int numberOfSets(int n, int k) {
     return c(n+k-1 , 2 * k);

    }
};
class Solution1 {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>>dp(n , vector<long long>(k+1 , 0));

        dp[0][0] = 1;

        for(int i = 1 ; i < n ; i++){
            dp[i][0] = 1;
        }

        for(int j = 1 ; j <= k ;j++){
            long long sum = 0;

            for(int i = 1 ; i < n ;i++){
                sum = (sum + dp[i-1][j-1]) % MOD;

                dp[i][j] = dp[i-1][j];

                dp[i][j] = (dp[i][j] + sum) % MOD;
            }
        }
        return dp[n-1][k];

    }
};