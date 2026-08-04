class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int>ans;
        int l = 0;
        for(int i = nums.front() ; i <= nums.back() ; i++){
            if(nums[l] != i ){
                ans.push_back(i);
            }
            else{
                l++;
            }

        }


        return ans;
    }
};