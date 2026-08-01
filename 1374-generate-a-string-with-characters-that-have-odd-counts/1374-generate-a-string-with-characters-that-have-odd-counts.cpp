class Solution {
public:
    string generateTheString(int n) {

        string s = "" ;

        if(n % 2 == 1){
            s.append(n , 'a');
        }   
        else{
            s.append(n-1 , 'a');
            s += 'b';
        }
        return s;
        
    }
};