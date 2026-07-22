class Solution {
public:
    bool checkDivisibility(int n) {
        int ds = 0 ;
        int dp = 1 ;

        int k = n ;
        int p = n ;

        while(k){
            int p = k % 10;
            ds += p;
            dp *= p;
            k /= 10;
        }

        int m = dp + ds ;
        return (n % m == 0);    
    }
};