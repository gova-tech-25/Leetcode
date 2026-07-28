class Solution {
public:
    class fenwick{
        public:
        int n ; 
        vector<int>bit;

        fenwick(int size){
            n = size;
            bit.assign(n+1 , 0);
        }
        void update(int idx , int val){
            while(idx < n){
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }
        
        int query(int idx){
            int s = 0;
            while(idx > 0 ){
                s += bit[idx];
                idx  -= idx & (-idx);
            }
            return s; 
        }
    };

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sn = nums;
        sort(sn.begin() , sn.end());

        sn.erase(unique(sn.begin() , sn.end()) , sn.end());
        
        fenwick ft(sn.size());

        int n = nums.size();

        vector<int>ans(n);

        for(int i = n - 1 ; i >= 0 ; i--){

            int rank = lower_bound(sn.begin() , sn.end() , nums[i]) - sn.begin() + 1;

            ans[i] = ft.query(rank - 1);

            ft.update(rank  , 1);
        }
        return ans;
    }
};