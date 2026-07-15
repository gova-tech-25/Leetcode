class Solution {
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