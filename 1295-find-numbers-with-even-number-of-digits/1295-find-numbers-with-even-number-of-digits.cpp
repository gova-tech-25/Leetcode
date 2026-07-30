class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        
       
        int tc = 0;
        for(auto it : nums){
            int p = it;
            int cnt = 0;
            while(p > 0){
                p /= 10;
                cnt++;
                
            }
            if(cnt % 2 == 0) tc++;
        }
        return tc;
        
    }
};