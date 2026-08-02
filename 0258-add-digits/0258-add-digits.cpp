class Solution {
public:
    int addDigits(int num) {
        

        while(num >= 10){
            int p = num;
            int sum = 0;
            while(p){
                sum += p % 10; 
                p /= 10;
            }
            num = sum;
        }
        return num;
        
    }
};