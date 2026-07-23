class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>pairs;
        if(n == 1) return 1;
        bitset<2048>ans;

        for(int x: nums){
            ans.set(x);
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                pairs.insert(nums[i] ^ nums[j]);
            }
        }

        for(int x : pairs){
            for(int num : nums){
                ans.set(x^num);
            }
        }

        return ans.count();
    }
};