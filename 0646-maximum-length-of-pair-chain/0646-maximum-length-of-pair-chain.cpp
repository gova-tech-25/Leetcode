class Solution { /// optimal
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        const int OFFSET = 1000;
        const int SIZE = 2001;

        vector<int>best(SIZE , INT_MIN);

        for(auto &p : pairs){
            int left = p[0];
            int right = p[1];

            best[right + OFFSET] = max( best[right + OFFSET] , left);
        }
        int freeup = -1001;
        int cnt = 0;

        for(int right = -1000 ; right <= 1000 ; right++){
            int left =  best[right + OFFSET];

            if(left != INT_MIN && left > freeup){
                cnt++;
                freeup = right;
            }
        }
        return cnt;
    }
};

// below solution is brute force 
class Solution1 {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin() , pairs.end() , [](vector<int> & a, vector<int> &b){
                                            return a[1] < b[1];
        });
        

        int freeup = pairs[0][1];
        int cnt = 1;

        for(int i = 1 ; i < n ; i++){
            if(freeup < pairs[i][0]){
                freeup = pairs[i][0];
                cnt++;
            }
        }

        return cnt;
    }
};