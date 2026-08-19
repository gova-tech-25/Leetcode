class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            int curr = nums[i];
            int tempMax = maxProduct;
            maxProduct = max({curr , curr * maxProduct , curr * minProduct});
            minProduct = min({curr , curr * tempMax , curr * minProduct});

            maxi = max(maxi , maxProduct);
        }

        return maxi;
        
    }
};