class Solution {
public:

    // 0 not yet processed
    // 1 currently processing
    // 2 already visited

    bool dfs(int node , vector<vector<int>>& graph ,  vector<int>&state){
        state[node] = 1 ; // currently expanding

        for(auto n : graph[node]){
            if(state[n] == 1){
                return false; // cycle found
            }
            else if(state[n] == 0){
                if(!dfs(n , graph , state)) return false;
            }
        }
        state[node] = 2; // completely processed 
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(auto &p :  prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int>state(numCourses , 0);

        for(int i = 0 ; i < numCourses ; i++){
            if(state[i] == 0){
                if(!dfs(i , graph , state)) return false;
            }
        }
        return true;

    }
};