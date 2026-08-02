class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<long long> p;
        long long s = 0;
        for (int a : tasks) {
            s += a;
            p.push_back(s);
        }
        long long d = 0;
        vector<int> res;
        int n = tasks.size();
        for (int t : shifts) {
            if (d + t >= s) {
                res.push_back(0);
                d = 0;
            } else {
                d += t;
                auto it = upper_bound(p.begin(), p.end(), d);
                res.push_back(n - distance(p.begin(), it));
            }
        }
        return res;
    }
};

class Solution1 {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();

        int rem = tasks[0];
        int idx = 0;
        

        vector<int>ans;
        
        for(int shift : shifts){
            long long time = shift;
            bool completed = false;

            while(time >= rem ){
                time -= rem;
                idx++;

                if(idx == n) {
                    completed = true;
                    idx = 0;
                    rem = tasks[0];
                    time  = 0;
                    break;
                }
                rem = tasks[idx];
            }

            if(time > 0){
                rem -= time;
            }
            if (completed){
                ans.push_back(0);
           
            }
            else
                ans.push_back(n - idx);
        }
        return ans;

    }
};