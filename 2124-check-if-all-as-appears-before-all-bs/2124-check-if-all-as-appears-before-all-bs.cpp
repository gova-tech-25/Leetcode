class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int a = -1;
        int b = -1;

        for(int i = 0 ; i < n ; i++){
            if(s[i] =='a'){
                a = i;
            }
            else{
                b = i;
            }

            if(b != -1 && b < a){
                return false;
            }
        }
        return true;
    }
};