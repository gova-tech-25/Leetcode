class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n , 0);

        for(auto it : bookings){
            int st = it[0] - 1;
            int en = it[1] - 1;
            int no = it[2];

            diff[st] += no;
            if(en + 1 < n)
                 diff[en+1] -= no;

        }
   

        for(int i = 1 ; i < n ; i++ ){
             diff[i] += diff[i-1];
        }
        return diff;
    }
};