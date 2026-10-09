class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int open = 0;
        int close = 0;

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                open++;
            }
            else {
                if(i + 1 < n && s[i + 1] == ')'){
                   i++;
                }
                else{
                    close++;
                }
                if(open > 0){
                    open--;
                }
                else{
                    close++;
                }
            }
        }

        return 2 * open + close;



        
    }
};