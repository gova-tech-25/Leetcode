class Solution {
    // as sum of first n even nums = n (n + 1 ) and odd is n^2
    // so gcd (n(n+1) , n^2) -> n * gcd (n , n+1) -> n * 1 ;
public:
    int gcdOfOddEvenSums(int n) {
        return n; 
    }
        
};

class Solution1 {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;

        for(int i = 0 ; i < 2 * n ; i++){
            if(i % 2 == 0) sumEven += i;
            else sumOdd += i;

        }
        
        return gcd(sumOdd ,sumEven);    
    }
};