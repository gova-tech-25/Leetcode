class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int>mini(n);
       // vector<int>maxi(n); --> dont need this
        //maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            mini[i] = min(mini[i+1] , nums[i]);
        }
        int maxt = -1;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxt) maxt = nums[i];
            if(maxt-mini[i] <= k) return i;
        }


        // for(int i = 0 ; i < n ; i++){
        //     int x = maxi[i]-mini[i] ;
        //     if(x <= k){
        //        return i;
        //     }
        // }
        return -1;
        
    }
};