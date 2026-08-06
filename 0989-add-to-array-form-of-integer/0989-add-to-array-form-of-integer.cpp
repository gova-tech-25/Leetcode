class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int n = nums.size();
        int i = n -1;
        int c = 0;

        while(i >= 0 || k > 0 || c){
            if(i >= 0) c += nums[i];
            c += k % 10;

            if(i >= 0){
                nums[i] = c % 10;
            }
            else{
                nums.insert(nums.begin() , c % 10);
            }
            c /= 10;
            k /= 10;
            i--;
        }

        return nums;
        
    }
};