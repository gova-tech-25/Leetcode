class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>>adj(n);

        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }

        vector<bool>sus(n , false);
        queue<int>q;
        q.push(k);

        sus[k] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : adj[u]){
                if(!sus[v]){
                    sus[v] = true;
                    q.push(v);
                }
            }
        }

        for(auto &e : invocations){
            int u = e[0] , v =e[1];

            if(!sus[u] && sus[v]){
                vector<int>ans;
                for(int i = 0 ; i < n ; i++)
                    ans.push_back(i);
                
                return ans;
            }
        }

        // the above loop says if any u -> v , u is not sus and v is sus so we cannot remove that element so return whole array.
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }
        // here we are taking the elements which are not sus so that in this array only non sus elements will be present.
        return ans;
        
    }
};