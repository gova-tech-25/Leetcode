class Solution {
public:
    bool isPalindrome(string &s , int i , int j){
        int n = s.size();

        while(i < j){
            if(s[i] != s[j]) return false;

            i++;
            j--;
        }

        return true;

    }
    int maxPalindromes(string s, int k) {


        const int n = s.size();
        int count = 0;
        
       
        for (int i = 0; i <= n - k; i++) {
            
            if (isPalindrome(s, i, i + k - 1)) {
                count++;
                i += k - 1; 
            } 
            
            else if (i + k < n && isPalindrome(s, i, i + k)) {
                count++;
                i += k; 
            }
        }
        
        return count;

        // int n = s.size();

        // vector<pair<int,int>> palin;

        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i ; j < n ; j++){
        //         if(j - i + 1 >= k){
        //             if(isPalindrome(s , i , j)){
        //                 palin.push_back({i , j});
        //             }
        //         }
        //     }
        // }
        
        // sort(palin.begin() , palin.end() , 
        //     [](pair<int,int>a , pair<int,int>b){
        //         return a.second < b.second;
        //     });
        
        // int count = 0 ; 
        // int lastend = -1;

        // for(auto p : palin){
        //     int st = p.first;
        //     int ls = p.second;

        //     if(st > lastend){
        //         count ++;
        //         lastend = ls;
        //     }

        // }

        // return count;

    }
};