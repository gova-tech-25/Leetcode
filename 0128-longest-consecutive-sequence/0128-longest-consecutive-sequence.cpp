class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int l = 1 , curr = 1;
        for(int i = 0 ; i < n-1 ; i++){
            if(nums[i+1] == nums[i] + 1){
                curr++;
            }
            else{
                curr = 1;
            }
            l = max(l , curr);
        }
        return l;
    }
};