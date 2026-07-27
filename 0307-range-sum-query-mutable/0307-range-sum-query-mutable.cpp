class NumArray1 { // fenwick 
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
    NumArray1(vector<int>& nums) {
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



class NumArray { // Segment trees
public:
    vector<int>nums;
    vector<int> tree;
    int n;
    
    void build(int node , int l , int r){
        // leaf
        if(l == r) {
            tree[node] = nums[l];
            return;

        }
        int mid = l + ( r - l ) / 2;

        build(2*node , l , mid);
        build(2*node + 1 , mid+1 , r);

        tree[node] = tree[2*node] + tree[2*node + 1];

    }

    int query(int node , int l , int  r , int ql ,  int qr){
        if (l > r)
        return 0;
        
        if(r < ql || l > qr) return 0;

        if(ql <= l && r <= qr){
            return tree[node];
        }
        int mid = l + ( r - l ) /2;

        return query(2*node , l , mid , ql , qr) + 
                query(2*node + 1 , mid + 1 , r , ql ,qr); 
    }

    void up(int node , int l , int r , int idx , int val){
        if(l == r ){
            tree[node] = val;
            return;
        }

        int mid = l + (r - l) / 2;

        if(idx <= mid)
            up(node*2 , l , mid , idx , val);
        else{
            up(2*node + 1 , mid+1 , r , idx , val);
        }

        tree[node] = tree[2*node] + tree[2*node+1];

    }
    NumArray(vector<int>& arr) {
        nums = arr;
        n = nums.size();
            if (n == 0) return;
        tree.resize(4*n);
        build(1 , 0 , n-1);
    }
    
    void update(int index, int val) {
        nums[index] = val;
        up(1 , 0 , n-1 , index ,val);
        
    }
    
    int sumRange(int left, int right) {
        return query(1 , 0 , n-1 , left , right);
        
    }
};
