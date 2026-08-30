class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        int mini = 0;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[maxi]){
                maxi = i;
            }

            if(nums[i] < nums[mini]){
                mini = i;
            }
        }

       int l = min(maxi , mini);
       int r = max(mini , maxi);

        // int left = maxi + 1;
        // int right = n - mini;
        // int both = (mini + 1) + (n - maxi);

        return min({r+1 , n - l , (l + 1) + (n - r)});
    }
};