class Solution {
public:
    long long countCommas(long long n) {
        if(n < 999) return 0;
        long long ans = 0;

        long long threshold = 1000;

        while(threshold <= n){
            ans += n - threshold + 1;
            threshold *= 1000;
        }

        return ans;


        
    }
};