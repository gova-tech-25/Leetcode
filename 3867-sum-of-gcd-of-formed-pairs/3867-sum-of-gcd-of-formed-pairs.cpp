class Solution {
public:
    int gcd(int a,int b)
        {
            int rem;
            while(b!=0)
                {
                    rem=a%b;
                    a=b;
                    b=rem;
                }
            return a;    
        }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        //vector<long long>pg(n);
        int mx = nums[0];
        for(int i = 0 ; i < n ; i++){
          //  int mx = *max_element(nums.begin() , nums.beigin() + i);
          mx = max(mx , nums[i]);
          nums[i] = gcd(nums[i] , mx);
        }

        sort(nums.begin() , nums.end());
        
        int low = 0 , high = nums.size() - 1;
        long long sum = 0;

        while(low < high){
            int x = gcd(nums[low] , nums[high]);
            sum += x;
            low++;
            high--;

        }
        return sum;
        
    }
};