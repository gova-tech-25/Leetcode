class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int mini = *min_element(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++){
            count += nums[i] - mini;
        }
        // /sigma/(nums[i] - min) => will gives the num of operations that needed
        return count;
        
    }
};