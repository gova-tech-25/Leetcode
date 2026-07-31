class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int > mpp;

        for(auto it : nums){
            mpp[it]++;
            if(mpp[it] > 1) return it;
        }
   
        return -1;
    }
};