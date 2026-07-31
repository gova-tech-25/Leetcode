class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        vector<int>arr(101 , 0);

        for(int i = 0 ; i < n ; i++){
            if(arr[bulbs[i]] == 1){
                arr[bulbs[i]] = 0;
            }
            else{
                arr[bulbs[i]] = 1;
            }
        }
        vector<int>ans;
       
        for(int i = 0 ; i < 101 ; i++){
            if(arr[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};