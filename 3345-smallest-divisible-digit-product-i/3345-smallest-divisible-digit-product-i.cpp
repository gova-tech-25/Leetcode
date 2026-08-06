class Solution {
public:
    int smallestNumber(int n, int t) {

        for(int i = n ; ; i++){
            int res = i;
            int p = 1;
            while(res >= 10){
                p *= res % 10;
                res /= 10;
            }
            if(res < 10 ){
                p *= res; 
                if(p % t == 0) return i;
            }
            else if(p / t == 0) return i;
            
        }
        return 0;
        
    }
};