class NumArray {
private : 
    vector<long long> bit;
    vector<int>nums;
    int n;

    void add(int idx , int delta){
        while(idx <= n){
            bit[idx] += delta;
            idx += idx & (-idx);
        }
    }
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        bit.assign(n+1 , 0);

        for(int i = 0 ; i < n ; i++){
            add(i+1 , nums[i]);
        }
        
    }
    
    void update(int index, int val) {
        int delta = val - nums[index];

        nums[index] = val;

        add(index+1 , delta);
        
    }
    int query(int idx){
        long long sum  = 0 ;

        while(idx > 0){
           sum += bit[idx];
           idx -= idx & (-idx); 
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        left++;
        right++;
        return query(right) - query(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */