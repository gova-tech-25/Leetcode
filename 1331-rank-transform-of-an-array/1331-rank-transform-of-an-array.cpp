class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
           int n = arr.size();

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;

        for(int i = 0 ; i < n ; i++){
            pq.push({arr[i] , i});
        }

        vector<int>ans(n);

        int rank = 0 ;
        int prev = INT_MIN;

        while(!pq.empty()){
            auto [val , idx] = pq.top();
            pq.pop();

            if(rank == 0 || val != prev){
                rank++;
                prev = val;
            }
            ans[idx] = rank;
        }
        return ans;



      
        
        // vector<int>s = arr;
        // sort(s.begin() , s.end());

        // unordered_map<int,int>rank;

        // int r = 1 ;

        // for(int x : s){
        //     if(rank.find(x) == rank.end()){
        //         rank[x] = r++;
        //     }
        // }

        // vector<int>ans;
        // for(int x : arr){
        //     ans.push_back(rank[x]);
        // }
        // return ans;
    }
};