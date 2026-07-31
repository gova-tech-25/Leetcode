class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        
      
       int j = 0;
       int ones = 0;
       int zeros = 0;

       for (int i = 1 ; i < n ; i++){
            if(s[i] != s[j]){
                int cnt  = i - j ;
                if(s[j] == '1'){
                    ones = max(ones , cnt);
                }
                else{
                    zeros = max(zeros , cnt);
                }
                j = i;
            } 
        } 

        int cnt = n - j;
        if(s[j] == '1') ones = max(ones , cnt);
        else zeros = max(zeros ,cnt);

        return ones > zeros;     
    }
};