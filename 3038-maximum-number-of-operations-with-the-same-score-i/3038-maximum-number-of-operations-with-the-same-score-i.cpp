class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0] + nums[1];
        int i = 0;
        int op = 0;

        while(i+1 < n){
            if(nums[i] + nums[i+1] == sum){
                op++;
                i+=2;
            }
            else{
                break;
            }
        }

      return op;

    }
};