
class Solution {
public:
    int maximum69Number (int num) {
        string x = to_string(num);
        
        for(char &c : x){
            if(c == '6'){
                c = '9';
                break;
            }
        }

        return stoi(x);
        
    }
};

class Solution1 {
public:
    int maximum69Number (int num) {
        string x = to_string(num);
        int ans = num;
        int n = x.size();

        for(int i = 0 ; i < n ; i++){
            
            if(x[i] == '9'){
                x[i] = '6';
                int p = stoi(x);
                ans = max(ans , p);
                x[i] = '9';
                
            }

            else if(x[i] == '6'){
                x[i] = '9';
                int p = stoi(x);
                ans = max(ans , p);
                x[i] = '6';
            }
        }

        return ans;


        
    }
};