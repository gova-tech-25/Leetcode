class Solution {
public:
    int maximumGap(vector<int>& nums) {
       int n = nums.size();

       if(n < 2 ) return 0;

       int maxi = *max_element(nums.begin() , nums.end());
       int mini = *min_element(nums.begin() , nums.end());
       if(maxi == mini) return 0;

       int gap = (maxi - mini) / (n -1);
       if(gap == 0) gap = 1;

       int bucketCount = (maxi - mini) / gap + 1 ;

       vector<int>bucketMax(bucketCount , INT_MIN);
       vector<int>bucketMin(bucketCount , INT_MAX);
       vector<bool>used(bucketCount , false);

       for(int num : nums){
            int idx = (num - mini) / gap;
            bucketMax[idx] = max(num , bucketMax[idx]);
            bucketMin[idx] = min(num , bucketMin[idx]);

            used[idx] = true;

       }
       int ans = 0;

       int prevMax = mini;

       for(int i = 0 ; i < bucketCount ; i++){
            if(!used[i]) continue;

            ans = max(ans ,bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
       }
       return ans;
       
    }
};

class Solution1 {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if(n < 2) return 0;
        sort(nums.begin() , nums.end());
        int ans = 0;

        for(int i = 1 ; i < n ; i++){
            int diff = nums[i] - nums[i-1];
            ans = max(ans , diff);
        }

        return ans;
        
    }
};