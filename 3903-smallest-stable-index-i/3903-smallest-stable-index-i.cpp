class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>mini(n);
        vector<int>maxi(n);
        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        
        for(int i = 1 ; i < n ; i++){
            maxi[i] = max(maxi[i-1] , nums[i]);
        }

        for(int i = n-2 ; i >= 0 ; i--){
            mini[i] = min(mini[i+1] , nums[i]);
        }

        for(int i = 0 ; i < n ; i++){
            int x = maxi[i]-mini[i] ;
            if(x <= k){
               return i;
            }
        }
        return -1;



    }
};