class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // for(int i = 0 ; i < n ; i++){
        //     if(nums[i] == target){
        //         return i;
        //     }
        // }

        int l = 0 ;
        int r = n - 1;

        while( l <= r){
            int mid = l + ( r - l) /2;

            if(nums[mid] == target) return mid;

            // left half is sorted

            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid]){
                    r = mid -1;
                }
                else{
                    l = mid + 1;
                }
            }

            // right half is sorted

            else{
                if(nums[r] >= target && target > nums[mid]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
 
        return -1;
    }
};