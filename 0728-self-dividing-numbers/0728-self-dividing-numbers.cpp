class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;

        for(int i = left ; i <= right ; i++){
            int p = i;
            bool self = true;

            while(p > 0){
                int x = p % 10;
                if(x == 0 || i % x != 0 ){
                    self = false;
                    break;
                }
                p /= 10;
            }
            if(self) ans.push_back(i);
        }
        return ans;
    }
};