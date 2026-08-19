class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , int> rows;

        for(auto &p : reservedSeats ){
            int row = p[0];
            int s = p[1];

            if(s >= 2 && s <= 9){
                rows[row] |= (1 << (s-2));
            }
        }

        int ans = 2 * n;

        int left = 0b00001111;
        int middle = 0b00111100;
        int right = 0b11110000;

        for(auto&[row , reserved] : rows){
            bool canleft = (reserved & left) == 0;
            bool canmiddle = (reserved & middle) == 0;
            bool canright = (reserved & right) == 0;

            if(canleft && canright) continue;

            else if(canleft || canmiddle || canright) ans--;
            
            else ans-=2;

        }

        return ans;
    }
};