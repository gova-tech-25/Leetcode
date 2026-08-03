class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n = nums.size();
        int cnt = 0;

        for(int l = 0 ; l < n ; l++){
            int oc = 0;
            int ec = 0;
            for(int r = l ; r < n ;r++){
                if(nums[r] & 1) oc++;
                else ec++;

                if(oc > 0 && 1LL * ec * b <= 1LL * a * oc ) cnt++;
            }

        }
        return cnt;
        
    }
};