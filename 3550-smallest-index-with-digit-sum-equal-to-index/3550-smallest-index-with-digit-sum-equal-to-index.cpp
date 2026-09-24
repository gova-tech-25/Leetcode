class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();


        for(int i = 0 ; i < n ;i++){
            int p = nums[i];
            int sum = 0;
            while(p > 0){
                sum += p % 10;
                p /= 10;
            }
            if(sum == i) return i;
        }

        return ans;
        
    }
};