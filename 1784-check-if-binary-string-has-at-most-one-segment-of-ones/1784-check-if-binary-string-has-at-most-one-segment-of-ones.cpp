class Solution {
public:
    bool checkOnesSegment(string s) {

        if(s[0] == '0') return false;

        int n = s.size();
        int cnt = 0;

        for(int i = 1 ; i < n ; i++){
            if(s[i-1] == '0' && s[i] == '1') 
            return false;

           

        }

         return true; 
       
        
    }
};