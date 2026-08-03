class Solution {
public:
    vector<int>dp;
    int solve(vector<int> &stoneValue , int i){
        int n = stoneValue.size();
        if( i >= n) return 0;
        
        if(dp[i] != INT_MIN) return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for(int k = 0 ; k < 3 && i  + k < n ; k++){
            sum += stoneValue[i+k];
            ans = max(ans , sum - solve(stoneValue , i + k + 1));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        dp.assign(n+1 , INT_MIN);

        int diff = solve(stoneValue , 0);

        if(diff > 0) return "Alice";
        if(diff < 0) return "Bob";

        return "Tie";  


     
        
    }
};