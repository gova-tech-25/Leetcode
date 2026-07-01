class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       int n = nums.size();

       for(int i = 0 ; i <= n ; i++){
            int num = k*(i+1);
            if(find(nums.begin() , nums.end() , num) == nums.end()){
                return num;
            }
       }
       return (n+1)*k;
        
    }
};