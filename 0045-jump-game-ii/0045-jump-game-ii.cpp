class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jumps = 0 , l = 0 , r = 0;

        while(r < n-1){
            int far = 0 ;

            for(int i = l ; i <= r ; i++)
                far = max(i+nums[i] , far);
            l = r+1;
            r =far;
            jumps++;
        }
        return jumps;
    }
};