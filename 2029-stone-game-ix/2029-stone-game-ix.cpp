class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            return min(cnt[1], cnt[2]) > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};

        //                  Start
        //                    |
        //                    ↓
        //          Count remainders
        //                    |
        //       ┌────────────┼────────────┐
        //       ↓            ↓            ↓
        //    cnt[0]       cnt[1]       cnt[2]
        //  x % 3 == 0   x % 3 == 1   x % 3 == 2
        //                    |
        //                    ↓
        //           Is cnt[0] even?
        //              /          \
        //            YES           NO
        //             |             |
        //             ↓             ↓
        //   min(cnt[1],cnt[2])   abs(cnt[1]-cnt[2])
        //           > 0?                > 2?
        //         /     \             /     \
        //       YES      NO         YES      NO
        //        |        |          |        |
        //        ↓        ↓          ↓        ↓
        //     Alice     Bob        Alice      Bob
        //      wins      wins        wins      wins

class Solution1 {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        int cnt [3] = {0 , 0  , 0};

        for(int x : stones){
            cnt[x % 3]++;
        }

        if(cnt[0] % 2 == 0){
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) >= 3;
        
    }
};