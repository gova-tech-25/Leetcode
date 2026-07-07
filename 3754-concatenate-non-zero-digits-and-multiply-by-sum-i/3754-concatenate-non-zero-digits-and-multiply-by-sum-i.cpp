class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0 ) return 0;
        long long sum = 0;
        int res = 0;
        int place = 1;
        while(n > 0){
            int x = n % 10;
                if(x != 0) {
                    sum += x;
                    res += x * place;
                    place *= 10;
                }
            n /= 10;
            
        }
        
        return sum * res;
    }
};